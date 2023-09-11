#pragma once
#include "../Dependencies/GL.h"
#include "../Dependencies/GLM.h"

#include "../Helpers/Debug.h"
#include "../Compiler/Compiler.h"
#include "../Scene/Camera.h"
#include "../Render.h"

namespace Vega
{
	namespace Core
	{
		class Window
		{
		public:
			/// <summary>
			/// Window setup and initialization.
			/// </summary>
			/// <param name="title"></param>
			/// <param name="width"></param>
			/// <param name="height"></param>
			Window(const char* title, const int width, const int height);
			~Window() { glfwDestroyWindow(window); }

			/// <summary>
			/// Begins the rendering process.
			/// </summary>
			void Run();

			/// <summary>
			/// Pass vertices and indices into the buffers.
			/// </summary>
			/// <param name="data"></param>
			/// <returns>A success boolean (did succeed?).</returns>
			bool PassBuffers(const std::pair<std::vector<unsigned int>, std::vector<glm::vec3>>& data);

			/// <summary>
			/// Adds a camera to the scene.
			/// </summary>
			/// <param name="id"></param>
			/// <param name="pos"></param>
			/// <param name="look"></param>
			/// <returns>A success boolean (did succeed?).</returns>
			bool AddCamera(std::wstring id, glm::vec3 pos = glm::vec3(0, 0, 0), glm::vec3 look = glm::vec3(0, 0, 0));
			/// <summary>
			/// Remove a camera from the scene.
			/// </summary>
			/// <param name="id"></param>
			/// <returns>A success boolean (did succeed?).</returns>
			bool RemoveCamera(std::wstring id);
			/// <summary>
			/// Makes the camera the main camera.
			/// </summary>
			/// <param name="id"></param>
			bool PromoteCamera(std::wstring id);

			/// <summary>
			/// Get the first camera.
			/// </summary>
			/// <returns></returns>
			Scene::Camera& GetFirstCamera() { return cameras.front(); }

			// Getters & Setters.
			GLFWwindow* GetWindow() { return window; }
			void SetWindow(GLFWwindow* window) { this->window = window; }

			std::pair<int, int> GetDimensions() { return { width, height }; }
			void SetDimensions(int width, int height) { this->width = width; this->height = height; }

			GLuint& GetVAO() { return VAO; }
			void SetVAO(GLuint VAO) { this->VAO = VAO; }

			GLuint& GetEBO() { return EBO; }
			void SetEBO(GLuint EBO) { this->EBO = EBO; }

			GLuint& GetVBO() { return VBO; }
			void SetVBO(GLuint VBO) { this->VBO = VBO; }

			GLuint& GetSP() { return SP; }
			void SetSP(GLuint SP) { this->SP = SP; }

			std::vector<unsigned int>& GetIndices() { return this->indices; }
			void SetIndices(std::vector<unsigned int> indices) { this->indices = indices; }

			std::vector<glm::vec3>& GetVertices() { return this->vertices; }
			void SetVertices(std::vector<glm::vec3> vertices) { this->vertices = vertices; }

			std::vector<Scene::Camera>& GetCameras() { return cameras; }
			void SetCameras(std::vector<Scene::Camera> cameras) { this->cameras = cameras; }
		private:
			GLFWwindow* window;

			int width, height;

			// Buffer objects.
			GLuint VAO;
			GLuint EBO;
			GLuint VBO;

			GLuint SP; // Shader program.

			// Buffers.
			std::vector<unsigned int> indices;
			std::vector<glm::vec3> vertices = { glm::vec3(0, 0, 0) };

			std::vector<Scene::Camera> cameras; // Camera buffer.
		};
	}
}

