#include "Texture.h"

using namespace Vega;

void Misc::Texture::Texture::LoadTexture(const char* filePath)
{
	glGenTextures(1, &texture);
	glBindTexture(GL_TEXTURE_2D, texture);

	stbi_set_flip_vertically_on_load(true);

	data = stbi_load(filePath, &width, &height, &channels, 0);

	if (!data) {
		Helpers::Debug::Log(L"Warning! Fallback. Failed to load texture from: " + Helpers::Conversion::CSTRtoWSTR(filePath) + L"!");

		filePath = FALLBACK_TEXTURE_PATH;
		data = stbi_load(filePath, &width, &height, &channels, 0);

		if (!data) {
			Helpers::Debug::Log(L"Warning! Final. Failed to load (fallback) texture from: " + Helpers::Conversion::CSTRtoWSTR(filePath) + L"!");

			stbi_image_free(data);
			return;
		}
	}

	GLenum format = 0;

	// Format.
	if (channels == 1) format = GL_RED;
	else if (channels == 3) format = GL_RGB;
	else if (channels == 4) format = GL_RGBA;

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format, GL_UNSIGNED_BYTE, data);
	glGenerateMipmap(GL_TEXTURE_2D);

	stbi_image_free(data);
}

