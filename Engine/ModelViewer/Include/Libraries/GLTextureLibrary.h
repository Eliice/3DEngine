#pragma once
#include <vector>

#include "Helpers\GlewHelper.h"
#include "TextureLibrary.h"

class OpenGLLibrary;

class GLTextureLibrary : public TextureLibrary
{
public:
	GLTextureLibrary(OpenGLLibrary* parent);
	virtual ~GLTextureLibrary();

	virtual void Initialize() override;

	virtual size_t LoadTexture(std::string const& file, DrawMode mode = LINEAR) override;

	void SelectTexture(int texID, GLenum const& target = GL_TEXTURE0, int tex = 0) const;

private:
	std::vector<GLuint> m_Textures;

	GLuint m_TextureBuffer;
};

