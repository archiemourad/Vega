#include "Render.h"

using namespace Vega;

void Render::Draw(Core::Window* window)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glUseProgram(window->GetSP());

	// Get locations prior.
	GLuint mvpLocation = glGetUniformLocation(window->GetSP(), "mvp");
	GLuint modelLocation = glGetUniformLocation(window->GetSP(), "model");

	if (window->GetScene().GetCameras().GetMembers().empty()) {
		// No need to keep track here.
		window->GetScene().GetCameras().AddMember(
			Scene::Actors::Camera((float)window->GetDimensions().first / window->GetDimensions().second)
		);

		Helpers::Debug::Log(L"Warning! Camera preemptively created.");
	}

	for (std::shared_ptr<Scene::Actors::Object> object : window->GetScene().GetObjects().GetMembers()) {
		// Setup.
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, object->GetEBO());

		glEnableVertexAttribArray(0);
		glBindBuffer(GL_ARRAY_BUFFER, object->GetVBO());
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);

		glm::mat4 mvp = window->GetScene().GetCameras().GetMembers().front()->ComputeMVP();
		glUniformMatrix4fv(mvpLocation, 1, GL_FALSE, glm::value_ptr(mvp));

		glm::mat4 model = object->ComputeModel();
		glUniformMatrix4fv(modelLocation, 1, GL_FALSE, glm::value_ptr(model));

		// Draw.
		glDrawElements(
			GL_TRIANGLES, // Mode.
			(GLsizei)object->GetIndices().size(), // Count.
			GL_UNSIGNED_INT, // Type.
			(void*)0 // Element array buffer offset.
		);

		// Cleanup.
		glDisableVertexAttribArray(0);
	}

	glfwSwapBuffers(window->GetWindow());
	glfwPollEvents();
}

