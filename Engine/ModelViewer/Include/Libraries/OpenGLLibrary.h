#pragma once
#include "Libraries\Library.h"

#include "DllExport.h"

class GLRenderLibrary;
class GLTextureLibrary;

class OpenGLLibrary : public Library
{
public:
	ENGINE_DLL OpenGLLibrary();
	ENGINE_DLL virtual ~OpenGLLibrary();

	virtual void Initialize() override;

	inline GLTextureLibrary* GetTextureLibrary() { return m_glTextureLibrary; }
private:
	GLRenderLibrary* m_glRender = nullptr;
	GLTextureLibrary* m_glTextureLibrary = nullptr;
};

