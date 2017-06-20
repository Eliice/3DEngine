#pragma once

#include <memory>

#include "GL/glew.h"
#include "GL/freeglut.h"

class GlSkyBox
{
	public:
		GlSkyBox();
		~GlSkyBox();

		static GlSkyBox* Get();

		bool CreateSkyBox(const char* name, GLuint* TexSky);
		void BindSkyBoxTexture(GLuint* TexSky);

		void SetSkyBoxTexture(const char* name);

		void Renderer(GLint const& texSkyLocation, GLuint const& TexSky);

	private:
		static std::unique_ptr<GlSkyBox> m_Instance;
};

