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

	// Projection / View / Model
	glm::mat4 projection = glm::perspective(glm::radians(45.0f), (float)window->GetDimensions().first / window->GetDimensions().second, 0.1f, 100.0f);
	glm::mat4 view = glm::lookAt(
		glm::vec3(5, 5, -5), // Camera position in world space.
		glm::vec3(0, 0, 0), // Looking at world origin.
		glm::vec3(0, 1, 0) // Head is up ((0, -1, 0) to look upside down).
	);
	glm::mat4 model = glm::mat4(1.0f);

	glm::mat4 mvp = projection * view * model;
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

