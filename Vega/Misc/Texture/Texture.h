#pragma once
#include "../../Dependencies/GL.h"
#include <stb/stb_image.h>

#include "../../Vega.h"
#include "../../Helpers/Debug.h"
#include "../../Helpers/Conversion.h"

namespace Vega
{
	namespace Misc
	{
		namespace Texture
		{
			class Texture
			{
			public:
				/// <summary>
				/// Load a texture from a specified filepath.
				/// </summary>
				/// <param name="filePath"></param>
				void LoadTexture(const char* filePath);

				/// <summary>
				/// Binds the texture.
				/// </summary>
				void Bind() { glBindTexture(GL_TEXTURE_2D, texture); }

				// Getters & Setters.

				int GetWidth() { return width; }
				void SetWidth(int width) { this->width = width; }

				int GetHeight() { return height; }
				void SetHeight(int height) { this->height = height; }

				int GetChannels() { return channels; }
				void SetChannels(int channels) { this->channels = channels; }

				GLuint& GetTexture() { return texture; }
				void SetTexture(GLuint texture) { this->texture = texture; }

			private:
				int width = 0, height = 0, channels = 0;
				unsigned char* data = NULL;

				GLuint texture = 0;

			};
		}
	}
}

