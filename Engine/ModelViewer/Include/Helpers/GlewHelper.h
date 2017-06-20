#pragma once
#include <memory>
#include <string>
#include <vector>
#include "Mat4.h"

#include "GL/glew.h"

class GlewHelper
{
public:
	GlewHelper();
	~GlewHelper();

	static GlewHelper* Get();

	void Initialize();

#pragma region Buffers
	void CreateBuffer(int nb, GLuint* buffer) const;
	void CreateRenderBuffer(int nb, GLuint* buffer) const;
	void CreateFrameBuffer(int nb, GLuint* buffer) const;
	void BindBuffer(GLenum const& target, GLuint const& buffer) const;
	void BindRenderBuffer(GLuint const& buffer) const;
	void BindFrameBuffer(GLuint const& buffer) const;
	void RenderBufferStorage(int width, int height) const;
	GLvoid* MapBuffer(GLenum const& target, GLenum const& access) const;
	void ResetBuffer(GLenum const& target);
	void ResetRenderBuffer();
	void ResetFrameBuffer();
	void UnmapBuffer(GLenum const& target) const;
	void DeleteBuffer(GLuint* buffer);
	void DeleteRenderBuffer(GLuint* buffer);
	void DeleteFrameBuffer(GLuint* buffer);

	void FrameBufferRenderBuffer(GLuint const& renderBuffer) const;
	void AssertFrameBufferStatus() const;
#pragma endregion

#pragma region Textures
	void CreateTexture(int nb, GLuint* buffer) const;
	void BindTexture(GLuint const& buffer) const;
	void SetTextureDimensions(uint8_t* imageData, int width, int height) const;
	void SetTextureFilter(GLint param) const;
	void FrameBufferTexture2D(GLuint const& texBuffer) const;
	void SetActiveTexture(GLenum const& target, uint32_t offset = 0) const;
	void ResetTexture();
	void DeleteTexture(GLuint* texBuffer);
#pragma endregion

	void BindUniformBlock(GLuint const& programID, std::string const& name, GLuint const& UBO, GLuint const& binding = 0) const;

	void SetBufferData(GLenum const& target, GLsizeiptr size, const GLvoid* data) const;
	void SetBufferSubData(GLenum const& target, GLintptr offset, GLsizei size, GLvoid const* data) const;

#pragma region VertexArray
	void CreateVertexArray(int nb, GLuint* buffer) const;
	void SetVertexArray(GLuint const& programID, std::string const& name, int size, GLenum const& type, GLsizei const& stride, GLvoid* startPoint = nullptr);
	void SetMatrixVertexAttribPointer(GLuint const& programID, std::string const& name, math::Mat4 const& matrix);
	void BindVertexArray(GLuint const& vertex);
	void ResetVertexArray();
	void DeleteVertexArray(GLuint* vertex);
#pragma endregion

	GLint GetAttribLocation(GLuint const& programID, std::string const& name);
	GLint GetUniformLocation(GLuint const& programID, std::string const& name);

#pragma region Uniform
	void SetUniform(GLint const& location, float value) const;
	void SetUniform(GLint const& location, double value) const;
	void SetUniform(GLint const& location, int value) const;
	void SetUniform(GLint const& location, uint32_t value) const;
	void SetUniformMatrix(GLint const& location, math::Mat4 const& value, GLsizei const& count = 1) const;
	void SetUniformMatrixArray(GLint const& location, std::vector<math::Mat4*> matrixPtrs) const;
#pragma endregion

	void Enable(GLenum const& param) const;

	void SetDepthFunc(GLenum const& func) const;
	void SetDepthMask(bool enable) const;

#pragma region Rendering
	void ClearColor(float r, float g, float b) const;
	void Clear() const;

	void DrawArrays(GLenum const& mode, GLsizei const& count) const;
	void DrawElements(GLenum const& mode, GLsizei const& count) const;
	void DrawElementsInstanced(GLenum const& mode, GLsizei const& count, GLsizei const& primcount) const;
#pragma endregion

private:
	static std::unique_ptr<GlewHelper> m_Instance;
};

