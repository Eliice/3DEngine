#include <cassert>

#include "Helpers\GlewHelper.h"
#include "Service\ServiceLocator.h"
#include "Vector4.h"

std::unique_ptr<GlewHelper> GlewHelper::m_Instance = nullptr;

GlewHelper::GlewHelper()
{
}


GlewHelper::~GlewHelper()
{
}

GlewHelper* GlewHelper::Get()
{
	if (GlewHelper::m_Instance == nullptr)
		GlewHelper::m_Instance = std::make_unique<GlewHelper>();

	return GlewHelper::m_Instance.get();
}

void GlewHelper::Initialize()
{
	glewExperimental = GL_FALSE;
	GLenum status = glewInit();

	if (status != GLEW_OK)
		LOGGER->Debuglog("Glew Init error : " + std::to_string(status), tools::service::LogLevel::ERRORM);
}

#pragma region Buffers
void GlewHelper::CreateBuffer(int nb, GLuint* buffer) const
{
	if (buffer == nullptr)
		return;

	glGenBuffers(nb, buffer);
}

void GlewHelper::CreateRenderBuffer(int nb, GLuint* buffer) const
{
	if (buffer == nullptr)
		return;

	glGenRenderbuffers(nb, buffer);
}

void GlewHelper::CreateFrameBuffer(int nb, GLuint* buffer) const
{
	if (!buffer)
		return;

	glGenFramebuffers(nb, buffer);
}

void GlewHelper::BindBuffer(GLenum const& target, GLuint const& buffer) const
{
	glBindBuffer(target, buffer);
}

void GlewHelper::BindRenderBuffer(GLuint const& buffer) const
{
	glBindRenderbuffer(GL_RENDERBUFFER, buffer);
}

void GlewHelper::BindFrameBuffer(GLuint const& buffer) const
{
	glBindFramebuffer(GL_FRAMEBUFFER, buffer);
}

void GlewHelper::RenderBufferStorage(int width, int height) const
{
	glRenderbufferStorage(GL_RENDERBUFFER, GL_DEPTH_COMPONENT, width, height);
}

GLvoid* GlewHelper::MapBuffer(GLenum const& target, GLenum const& access) const
{
	return glMapBuffer(target, access);
}

void GlewHelper::ResetBuffer(GLenum const& target)
{
	glBindBuffer(target, 0);
}

void GlewHelper::ResetRenderBuffer()
{
	glBindRenderbuffer(GL_RENDERBUFFER, 0);
}

void GlewHelper::ResetFrameBuffer()
{
	glBindFramebuffer(GL_FRAMEBUFFER, 0);
}

void GlewHelper::UnmapBuffer(GLenum const& target) const
{
	glUnmapBuffer(target);
}

void GlewHelper::DeleteBuffer(GLuint* buffer)
{
	if (buffer == nullptr)
		return;

	glDeleteBuffers(1, buffer);
}

void GlewHelper::DeleteRenderBuffer(GLuint* buffer)
{
	if (!buffer)
		return;

	glDeleteRenderbuffers(1, buffer);
}

void GlewHelper::DeleteFrameBuffer(GLuint* buffer)
{
	if (!buffer)
		return;

	glDeleteFramebuffers(1, buffer);
}

void GlewHelper::FrameBufferRenderBuffer(GLuint const& renderBuffer) const
{
	glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, GL_RENDERBUFFER, renderBuffer);
}

void GlewHelper::AssertFrameBufferStatus() const
{
	GLenum status = glCheckFramebufferStatus(GL_FRAMEBUFFER);
	assert(status == GL_FRAMEBUFFER_COMPLETE);
}
#pragma endregion

#pragma region Textures
void GlewHelper::CreateTexture(int nb, GLuint* buffer) const
{
	if (!buffer)
		return;

	glGenTextures(nb, buffer);
}

void GlewHelper::BindTexture(GLuint const& buffer) const
{
	glBindTexture(GL_TEXTURE_2D, buffer);
}

void GlewHelper::SetTextureDimensions(uint8_t* imageData, int width, int height) const
{
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, imageData);
}

void GlewHelper::SetTextureFilter(GLint param) const
{
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, param);
}

void GlewHelper::FrameBufferTexture2D(GLuint const& texBuffer) const
{
	glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, texBuffer, 0);
}

void GlewHelper::SetActiveTexture(GLenum const& target, uint32_t offset) const
{
	glActiveTexture(target + offset);
}

void GlewHelper::ResetTexture()
{
	glBindTexture(GL_TEXTURE_2D, 0);
}

void GlewHelper::DeleteTexture(GLuint* texBuffer)
{
	glDeleteTextures(1, texBuffer);
}
#pragma endregion

void GlewHelper::BindUniformBlock(GLuint const& programID, std::string const& name, GLuint const& UBO, GLuint const& binding) const
{
	int blockIndex = glGetUniformBlockIndex(programID, name.c_str());
	glBindBufferBase(GL_UNIFORM_BUFFER, binding, UBO);
	glUniformBlockBinding(programID, blockIndex, binding);
}

void GlewHelper::SetBufferData(GLenum const& target, GLsizeiptr size, const GLvoid* data) const
{
	glBufferData(target, size, data, GL_STATIC_DRAW);
}

void GlewHelper::SetBufferSubData(GLenum const& target, GLintptr offset, GLsizei size, GLvoid const* data) const
{
	glBufferSubData(target, offset, size, data);
}

void GlewHelper::CreateVertexArray(int nb, GLuint * buffer) const
{
	if (buffer == nullptr)
		return;

	glGenVertexArrays(nb, buffer);
}

void GlewHelper::SetVertexArray(GLuint const& programID, std::string const& name, int size, GLenum const& type, GLsizei const& stride, GLvoid* startPoint)
{
	GLint attributeLocation = GetAttribLocation(programID, name);

	if (attributeLocation == -1)
		return;

	glVertexAttribPointer(attributeLocation, size, type, false, stride, startPoint);
	glEnableVertexAttribArray(attributeLocation);
}

void GlewHelper::SetMatrixVertexAttribPointer(GLuint const& programID, std::string const& name, math::Mat4 const& matrix)
{
	GLint attributeLocation = GetAttribLocation(programID, name);

	if (attributeLocation == -1)
		return;

	for (int i = 0; i < 4; i++)
	{
		glVertexAttribPointer(attributeLocation + i, 4, GL_FLOAT, GL_FALSE, sizeof(math::Mat4), (void *)(sizeof(math::Vector4) * i));
		glEnableVertexAttribArray(attributeLocation + i);
		glVertexAttribDivisor(attributeLocation + i, 1);
	}
}

void GlewHelper::BindVertexArray(GLuint const& vertex)
{
	glBindVertexArray(vertex);
}

void GlewHelper::ResetVertexArray()
{
	glBindVertexArray(0);
}

void GlewHelper::DeleteVertexArray(GLuint* vertex)
{
	if (vertex == nullptr)
		return;

	glDeleteVertexArrays(1, vertex);
}

GLint GlewHelper::GetAttribLocation(GLuint const& programID, std::string const& name)
{
	return glGetAttribLocation(programID, name.c_str());
}

GLint GlewHelper::GetUniformLocation(GLuint const& programID, std::string const& name)
{
	return glGetUniformLocation(programID, name.c_str());
}

void GlewHelper::SetUniform(GLint const& location, float value) const
{
	glUniform1f(location, value);
}

void GlewHelper::SetUniform(GLint const& location, double value) const
{
	glUniform1d(location, value);
}

void GlewHelper::SetUniform(GLint const& location, int value) const
{
	glUniform1i(location, value);
}

void GlewHelper::SetUniform(GLint const& location, uint32_t value) const
{
	glUniform1i(location, value);
}

void GlewHelper::SetUniformMatrix(GLint const& location, math::Mat4 const& value, GLsizei const& count) const
{
	glUniformMatrix4fv(location, count, GL_TRUE, value.m);
}

void GlewHelper::SetUniformMatrixArray(GLint const& location, std::vector<math::Mat4*> matrixPtrs) const
{
	std::vector<float> matrixes;

	for (int i = 0; i < matrixPtrs.size(); i++)
	{
		for (int j = 0; j < _countof(matrixPtrs[i]->m); j++)
		{
			matrixes.push_back(matrixPtrs[i]->m[j]);
		}
	}

	glUniformMatrix4fv(location, (GLsizei)matrixes.size(), GL_TRUE, &matrixes[0]);
	
}

void GlewHelper::Enable(GLenum const& param) const
{
	glEnable(param);
}

void GlewHelper::SetDepthFunc(GLenum const& func) const
{
	glDepthFunc(func);
}

void GlewHelper::SetDepthMask(bool enable) const
{
	if (enable)
		glDepthMask(GL_TRUE);
	else
		glDepthMask(GL_FALSE);
}

void GlewHelper::ClearColor(float r, float g, float b) const
{
	glClearColor(r, g, b, 1.0f);
}

void GlewHelper::Clear() const
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void GlewHelper::DrawArrays(GLenum const& mode, GLsizei const& count) const
{
	glDrawArrays(mode, 0, count);
}

void GlewHelper::DrawElements(GLenum const& mode, GLsizei const& count) const
{
	glDrawElements(mode, count, GL_UNSIGNED_SHORT, nullptr);
}

void GlewHelper::DrawElementsInstanced(GLenum const& mode, GLsizei const& count, GLsizei const& primcount) const
{
	glDrawElementsInstanced(mode, count, GL_UNSIGNED_SHORT, nullptr, primcount);
}