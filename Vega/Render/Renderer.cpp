#include "Renderer.h"

using namespace Vega;

void Render::Renderer::Draw(Core::Window* window)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glUseProgram(window->GetSP());

	// Get locations prior.
	GLuint mvpLocation = glGetUniformLocation(window->GetSP(), "mvp");
	GLuint modelLocation = glGetUniformLocation(window->GetSP(), "model");
	GLuint samplerLocation = glGetUniformLocation(window->GetSP(), "sampler");

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

		// Attributes.
		glEnableVertexAttribArray(0);
		glBindBuffer(GL_ARRAY_BUFFER, object->GetVBO());
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Misc::Vertex::Vertex), (void*)offsetof(Misc::Vertex::Vertex, position));

		glEnableVertexAttribArray(1);
		glBindBuffer(GL_ARRAY_BUFFER, object->GetVBO());
		glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(Misc::Vertex::Vertex), (void*)offsetof(Misc::Vertex::Vertex, texCoord));

		// Serve to shader.
		glm::mat4 mvp = window->GetScene().GetCameras().GetMembers().front()->ComputeMVP();
		glUniformMatrix4fv(mvpLocation, 1, GL_FALSE, glm::value_ptr(mvp));

		glm::mat4 model = object->ComputeModel();
		glUniformMatrix4fv(modelLocation, 1, GL_FALSE, glm::value_ptr(model));

		glUniform1i(samplerLocation, 0);

		object->GetTexture().Bind(); // Texture.

		// Callback.
		PreRenderCallback(window);

		// Draw.
		glDrawElements(
			GL_TRIANGLES, // Mode.
			(GLsizei)object->GetIndices().size(), // Count.
			GL_UNSIGNED_INT, // Type.
			(void*)0 // Element array buffer offset.
		);

		// Callback.
		PostRenderCallback(window);

		// Cleanup.
		glDisableVertexAttribArray(0);
		glDisableVertexAttribArray(1);
	}

	glfwSwapBuffers(window->GetWindow());
	glfwPollEvents();
}

