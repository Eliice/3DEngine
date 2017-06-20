#include "Libraries\GLTextureLibrary.h"
#include "Helpers\STBIHelper.h"
#include "Libraries\OpenGLLibrary.h"

GLTextureLibrary::GLTextureLibrary(OpenGLLibrary* parent)
	: TextureLibrary("GLTextureLibrary", parent)
{
}


GLTextureLibrary::~GLTextureLibrary()
{
	m_Textures.clear();
}

void GLTextureLibrary::Initialize()
{
	TextureLibrary::Initialize();
}

size_t GLTextureLibrary::LoadTexture(std::string const& file, DrawMode mode)
{
	size_t texID = m_Textures.size();

	GLuint newTexture;

	GlewHelper::Get()->CreateTexture(1, &newTexture);
	GlewHelper::Get()->BindTexture(newTexture);
	int w, h, c;
	uint8_t* imageData = STBIHelper::Get()->Load(file, &w, &h, &c);
	GlewHelper::Get()->SetTextureDimensions(imageData, w, h);
	STBIHelper::Get()->Free(imageData);
	
	if (mode == LINEAR)
		GlewHelper::Get()->SetTextureFilter(GL_LINEAR);
	else
		GlewHelper::Get()->SetTextureFilter(GL_NEAREST);

	GlewHelper::Get()->ResetTexture();

	m_Textures.push_back(newTexture);

	return texID;
}

void GLTextureLibrary::SelectTexture(int texID, GLenum const& target, int tex) const
{
	if (texID < 0 || texID >= m_Textures.size())
		return;

	GlewHelper::Get()->SetActiveTexture(target, tex);
	GlewHelper::Get()->BindTexture(m_Textures[texID]);
}