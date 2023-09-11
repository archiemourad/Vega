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

	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);

	glGenBuffers(1, &EBO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(unsigned int), &indices.front(), GL_STATIC_DRAW);

	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(glm::vec3), &vertices.front(), GL_STATIC_DRAW);

	// Vertex shader.
	const GLuint VS = Compiler::CompileVertexShader(L"Shaders/vertex.glsl");
	// Fragment shader.
	const GLuint FS = Compiler::CompileFragmentShader(L"Shaders/fragment.glsl");

	// Shader program.
	SP = Compiler::AssembleShaderProgram(VS, FS);

	// Cleanup (no longer needed).
	glDeleteShader(VS);
	glDeleteShader(FS);

	// Render.
	do { Render::Render(this); } while (glfwGetKey(window, GLFW_KEY_ESCAPE) != GLFW_PRESS && glfwWindowShouldClose(window) == 0);
}

bool Core::Window::PassBuffers(const std::pair<std::vector<unsigned int>, std::vector<glm::vec3>>& data)
{
	if (data.first.empty() || data.second.empty()) return false; // Empty check.

	indices.insert(indices.end(), data.first.begin(), data.first.end());
	vertices.insert(vertices.end(), data.second.begin(), data.second.end());

	return true;
}

bool Core::Window::AddCamera(std::wstring id, glm::vec3 pos, glm::vec3 look)
{
	for (Scene::Camera camera : cameras) if (id == camera.GetID()) return false;

	Scene::Camera camera(id, (float)width / height);

	// Properties.
	camera.SetPos(pos);
	camera.SetLook(look);

	cameras.push_back(camera);

	return true;
}

bool Core::Window::RemoveCamera(std::wstring id)
{
	for (unsigned int i = 0; i < cameras.size(); i++)
		if (id == cameras[i].GetID()) {
			cameras.erase(cameras.begin() + i);
			return true;
		}

	return false;
}

bool Core::Window::PromoteCamera(std::wstring id)
{
	for (unsigned int i = 0; i < cameras.size(); i++)
		if (id == cameras[i].GetID()) {
			std::rotate(cameras.begin(), cameras.begin() + i, cameras.end());
			return true;
		}

	return false;
}

