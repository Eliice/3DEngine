#pragma once
#include <vector>
#include "Libraries\RenderLibrary.h"
#include "Helpers\GlewHelper.h"
#include "Service\ServiceLocator.h"

class OpenGLLibrary;
class GLTextureLibrary;
class BasicShader;
class RenderCache;

namespace component
{
	class Mesh;
}

class GLRenderLibrary : public RenderLibrary
{
public:
	GLRenderLibrary(OpenGLLibrary* parent);
	virtual ~GLRenderLibrary();

	virtual void Initialize() override;

	void InitShaders();
	void InitVertexArray();
	void InitBuffer(GLenum const& target, GLuint* buffer);
	void InitUBO();
	
	void SetVertexArrays();

	void Render();
	void ResetRender() const;

	void ClearRenderWindow();
	void Draw(MeshObject* meshObject);
private:
	void RenderScene();
	void RenderSkybox();

	RenderCache* GetMeshData(MeshObject* mesh);
	void SetBufferData(RenderCache* cache);
	void SendMeshMatrixToShader(MeshObject* mesh);
	
	void RegisterMatrixData(std::vector<math::Mat4> const& worlds);

	void BindVAO() const;
	void BindVBO() const;
	void BindIBO() const;
	void BindUBO() const;

	void ResetVAO() const;
	void ResetVBO() const;
	void ResetUBO() const;
	void ResetIBO() const;

	

	std::unordered_map<std::string, RenderCache*> m_Cache;

	std::vector<float> m_BufferData;
	std::vector<uint16_t> m_Indices;

	std::vector<float> m_worldsData;

	GLTextureLibrary* m_glTextureLibrary = nullptr;

	///TODO: init this things
	BasicShader* m_MeshProgram = nullptr;
	BasicShader* m_SkyboxProgram = nullptr;

	uint32_t tex = 0;

	GLuint m_VBO;
	GLuint m_VAO;
	GLuint m_IBO;
	GLuint m_InstanceVBO;
	GLuint m_UBO;

	GLuint TexSkyBox;
};

