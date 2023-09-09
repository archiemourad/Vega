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

	if (window == nullptr) Helpers::Debug::Error(L"Failed to create a GLFW window.");

	glfwMakeContextCurrent(window);
	glewExperimental = true;

	if (glewInit() != GLEW_OK) Helpers::Debug::Error(L"Failed to initialize GLEW.");
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
	glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(glm::vec3), &vertices.front(), GL_STATIC_DRAW);

	// Vertex shader.
	const GLuint VS = Compiler::CompileVertexShader(L"Shaders/vertex.glsl");
	// Fragment shader.
	const GLuint FS = Compiler::CompileFragmentShader(L"Shaders/fragment.glsl");

	// Shader program.
	const GLuint SP = Compiler::AssembleShaderProgram(VS, FS);

	// Cleanup (no longer needed).
	glDeleteShader(VS);
	glDeleteShader(FS);

	// Render.
	do {
		Render::Render(
			window,
			SP,
			// Buffer objects.
			EBO,
			VBO,
			// Buffers.
			indices,
			vertices
		);
	} while (glfwGetKey(window, GLFW_KEY_ESCAPE) != GLFW_PRESS && glfwWindowShouldClose(window) == 0);
}

bool Core::Window::PassBuffers(const std::pair<std::vector<unsigned int>, std::vector<glm::vec3>>& data)
{
	if (data.first.empty() || data.second.empty()) return false; // Empty check.

	indices.insert(indices.end(), data.first.begin(), data.first.end());
	vertices.insert(vertices.end(), data.second.begin(), data.second.end());

	return true;
}
