#include "Render.h"

using namespace Vega;

void Render::Render(Core::Window* window)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// Setup.
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, window->GetEBO());

	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, window->GetVBO());
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);

	glUseProgram(window->GetSP());

	// Serve to shader.
	GLuint mvpLocation = glGetUniformLocation(window->GetSP(), "mvp");

	if (window->GetScene().GetCameras().GetMembers().empty()) {
		// No need to keep track here.
		window->GetScene().GetCameras().AddMember(
			Scene::Actors::Camera((float)window->GetDimensions().first / window->GetDimensions().second)
		);

		Helpers::Debug::Log(L"Warning! Camera preemptively created.");
	}

	glm::mat4 mvp = window->GetScene().GetCameras().GetMembers().front()->GenerateMVP();
	glUniformMatrix4fv(mvpLocation, 1, GL_FALSE, &mvp[0][0]);

	// Draw.
	glDrawElements(
		GL_TRIANGLES, // Mode.
		(GLsizei)window->GetIndices().size(), // Count.
		GL_UNSIGNED_INT, // Type.
		(void*)0 // Element array buffer offset.
	);

	// Cleanup.
	glDisableVertexAttribArray(0);

	glfwSwapBuffers(window->GetWindow());
	glfwPollEvents();
}

