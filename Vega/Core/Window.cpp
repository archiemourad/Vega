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

void Core::Window::Start()
{
	glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);

	// Vertex shader.
	const GLuint VS = Compiler::CompileVertexShader(L"Shaders/vertex.glsl");
	// Fragment shader.
	const GLuint FS = Compiler::CompileFragmentShader(L"Shaders/fragment.glsl");

	// Shader program.
	SP = Compiler::AssembleShaderProgram(VS, FS);

	// Cleanup (no longer needed).
	glDeleteShader(VS);
	glDeleteShader(FS);

	// Callback.
	StartCallback(this);

	// Render.
	do {
		renderer->Draw(this);

		RenderCallback(this); // Callback.
	} while (glfwGetKey(window, GLFW_KEY_ESCAPE) != GLFW_PRESS && glfwWindowShouldClose(window) == 0);
}

