#include "Libraries\OpenGLLibrary.h"
#include "Libraries\GLRenderLibrary.h"
#include "Libraries\GLTextureLibrary.h"
#include "Helpers\GlewHelper.h"

OpenGLLibrary::OpenGLLibrary()
	: Library("OpenGL")
{
}


OpenGLLibrary::~OpenGLLibrary()
{
	delete m_glRender;
	delete m_glTextureLibrary;

	m_glRender = nullptr;
	m_glTextureLibrary = nullptr;
}

void OpenGLLibrary::Initialize()
{
	m_glTextureLibrary = new GLTextureLibrary(this);
	m_glRender = new GLRenderLibrary(this);

	GlewHelper::Get()->Initialize();

	m_glRender->Initialize();
	m_glTextureLibrary->Initialize();
}