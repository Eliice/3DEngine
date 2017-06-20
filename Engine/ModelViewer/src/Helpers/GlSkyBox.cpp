#include "Helpers\GlSkyBox.h"

#include "Helpers\GlewHelper.h"
#include "stb/stb_image.h"

std::unique_ptr<GlSkyBox> GlSkyBox::m_Instance = nullptr;

GlSkyBox::GlSkyBox()
{
}


GlSkyBox::~GlSkyBox()
{
}

GlSkyBox* GlSkyBox::Get()
{
	if (GlSkyBox::m_Instance == nullptr)
		GlSkyBox::m_Instance = std::make_unique<GlSkyBox>();

	return GlSkyBox::m_Instance.get();
}

bool GlSkyBox::CreateSkyBox(const char* name, GLuint* TexSky)
{
	BindSkyBoxTexture(TexSky);
	SetSkyBoxTexture(name);

	return true;
}

void GlSkyBox::BindSkyBoxTexture(GLuint* TexSky)
{
	glGenTextures(1, TexSky);
	glBindTexture(GL_TEXTURE_2D, *TexSky);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
}

void GlSkyBox::SetSkyBoxTexture(const char* name)
{
	int w, h, c;
	float* imageData = stbi_loadf(name, &w, &h, &c, STBI_rgb);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB16F, w, h, 0, GL_RGB, GL_FLOAT, imageData);
	stbi_image_free(imageData);
}

void GlSkyBox::Renderer(GLint const& texSkyLocation, GLuint const& TexSky)
{
	glActiveTexture(GL_TEXTURE1);
	glBindTexture(GL_TEXTURE_2D, TexSky);
	glUniform1i(texSkyLocation, 1);
}

