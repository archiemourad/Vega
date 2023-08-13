#include "Window.h"

using namespace Vega;

Core::Window::Window(const char* title, const int width, const int height)
{
	this->width = width;
	this->height = height;

	glfwWindowHint(GLFW_SAMPLES, 4); // 4x antialiasing.
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	window = glfwCreateWindow(width, height, title, NULL, NULL);

	if (window == nullptr) {
		Helpers::Debug::Error(L"Failed to create a GLFW window.");
	}

	glfwMakeContextCurrent(window);
	glewExperimental = true;

	if (glewInit() != GLEW_OK) {
		Helpers::Debug::Error(L"Failed to initialize GLEW.");
	}
}

void Core::Window::Run()
{
	glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);

	GLuint VAO;
	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);

	GLuint EBO;
	glGenBuffers(1, &EBO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(unsigned int), &indices.front(), GL_STATIC_DRAW);

	GLuint VBO;
	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(GLfloat), &vertices.front(), GL_STATIC_DRAW);

	// Vertex shader.
	const GLuint VS = Compiler::CompileVertexShader(L"Shaders/vertex.glsl");
	// Fragment shader.
	const GLuint FS = Compiler::CompileFragmentShader(L"Shaders/fragment.glsl");

	// Shader program.
	const GLuint SP = Compiler::AssembleShaderProgram(VS, FS);

	// Cleanup (no longer needed).
	glDeleteShader(VS);
	glDeleteShader(FS);

	// Projection / View / Model
	glm::mat4 projection = glm::perspective(glm::radians(45.0f), (float)width / height, 0.1f, 100.0f);
	glm::mat4 view = glm::lookAt(
		glm::vec3(5, 5, -5), // Camera position in world space.
		glm::vec3(0, 0, 0), // Looking at world origin.
		glm::vec3(0, 1, 0) // Head is up ((0, -1, 0) to look upside down).
	);
	glm::mat4 model = glm::mat4(1.0f);

	glm::mat4 mvp = projection * view * model;
	GLuint mvpLocation = glGetUniformLocation(SP, "mvp");

	do {
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		// Setup.
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);

		glEnableVertexAttribArray(0);
		glBindBuffer(GL_ARRAY_BUFFER, VBO);
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void*)0);

		glUseProgram(SP);

		// Serve to shader.
		glUniformMatrix4fv(mvpLocation, 1, GL_FALSE, &mvp[0][0]);

		// Draw.
		glDrawElements(
			GL_TRIANGLES, // Mode.
			(GLsizei)indices.size(), // Count.
			GL_UNSIGNED_INT, // Type.
			(void*)0 // Element array buffer offset.
		);

		// Cleanup.
		glDisableVertexAttribArray(0);

		glfwSwapBuffers(window);
		glfwPollEvents();
	} while (glfwGetKey(window, GLFW_KEY_ESCAPE) != GLFW_PRESS && glfwWindowShouldClose(window) == 0);
}

void Core::Window::DualPassIntoBuffers(const std::pair<std::vector<GLfloat>, std::vector<unsigned int>>& data)
{
	PassVerticesIntoBuffer(data.first);
	PassIndicesIntoBuffer(data.second);
}

void Core::Window::PassIndicesIntoBuffer(const std::vector<unsigned int>& indices)
{
	this->indices.insert(this->indices.end(), indices.begin(), indices.end());
}

void Core::Window::PassVerticesIntoBuffer(const std::vector<GLfloat>& vertices)
{
	this->vertices.insert(this->vertices.end(), vertices.begin(), vertices.end());
}

