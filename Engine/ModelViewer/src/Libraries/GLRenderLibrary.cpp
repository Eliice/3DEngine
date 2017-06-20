#include "Libraries\GLRenderLibrary.h"
#include "Libraries\OpenGLLibrary.h"
#include "Component\BasicShader.h"
#include "Helpers\GlewHelper.h"
#include "Component\Mesh.h"
#include "Component\RenderCache.h"
#include "Service\servicelocator.h"
#include "Service\Tools.h"
#include "Scene\camera.h"
#include "Libraries\GLTextureLibrary.h"
#include "Scene\Skybox.h"
#include "Plugins\Event.h"
#include "Service\MeshObject.h"

GLRenderLibrary::GLRenderLibrary(OpenGLLibrary* parent)
	: RenderLibrary("GLRender", parent)
{
	m_MeshProgram = new BasicShader();
	m_SkyboxProgram = new BasicShader();

	m_glTextureLibrary = parent->GetTextureLibrary();
}


GLRenderLibrary::~GLRenderLibrary()
{
	delete m_MeshProgram;
	delete m_SkyboxProgram;

	m_MeshProgram = nullptr;
	m_SkyboxProgram = nullptr;
	m_glTextureLibrary = nullptr;
}

void GLRenderLibrary::Initialize()
{
	RenderLibrary::Initialize();

	//GlewHelper::Get()->Enable(GL_FRAMEBUFFER_SRGB);

	InitShaders();
	InitVertexArray();
	InitBuffer(GL_ARRAY_BUFFER, &m_VBO);
	InitBuffer(GL_ELEMENT_ARRAY_BUFFER, &m_IBO);
	InitUBO();

	SetVertexArrays();
	ResetRender();
}

void GLRenderLibrary::InitShaders()
{
	m_MeshProgram->LoadAndCreateShaders("../ModelViewer/ShaderData/shader.vs", "../ModelViewer/ShaderData/shader.frag");
	m_SkyboxProgram->LoadAndCreateShaders("../ModelViewer/ShaderData/SkyboxLatLong.vs", "../ModelViewer/ShaderData/SkyboxLatLong.frag");
}

void GLRenderLibrary::InitVertexArray()
{
	GlewHelper::Get()->CreateVertexArray(1, &m_VAO);
	BindVAO();
}

void GLRenderLibrary::InitBuffer(GLenum const& target, GLuint* buffer)
{
	GlewHelper::Get()->CreateBuffer(1, buffer);
	GlewHelper::Get()->BindBuffer(target, *buffer);
}

void GLRenderLibrary::InitUBO()
{
	GlewHelper::Get()->CreateBuffer(1, &m_UBO);

	BindUBO();
	GlewHelper::Get()->SetBufferData(GL_UNIFORM_BUFFER, 128 * 64 * sizeof(float), nullptr);
	GlewHelper::Get()->BindUniformBlock(m_MeshProgram->Get(), "shaderData", m_UBO);
	ResetUBO();
}

void GLRenderLibrary::SetVertexArrays()
{
	uint16_t programID = m_MeshProgram->Get();
	ERROR_MANAGER->CheckReturn(programID);

	GlewHelper::Get()->SetVertexArray(programID, "a_Position", 3, GL_FLOAT, 9 * sizeof(float), 0);
	GlewHelper::Get()->SetVertexArray(programID, "a_Normal", 3, GL_FLOAT, 9 * sizeof(float), (void*)(3 * sizeof(float)));
	GlewHelper::Get()->SetVertexArray(programID, "a_TexCoords", 2, GL_FLOAT, 9 * sizeof(float), (void*)(6 * sizeof(float)));
}

void GLRenderLibrary::Render()
{
	ClearRenderWindow();

	//BindVAO();

	RenderScene();
	RenderSkybox();

	//ResetVAO();
}

void GLRenderLibrary::ResetRender() const
{
	ResetVAO();
	ResetVBO();
	ResetIBO();
}

void GLRenderLibrary::ClearRenderWindow()
{
	GlewHelper::Get()->Enable(GL_DEPTH_TEST);

	GlewHelper::Get()->ClearColor(1.0f, 0.0f, 0.0f);
	GlewHelper::Get()->Clear();
}

void GLRenderLibrary::Draw(MeshObject* meshObject)
{
	if (!meshObject || meshObject->GetInstanceCount() == 0)
		return;

	RenderCache* cache = GetMeshData(meshObject);
	SetBufferData(cache);

	BindVAO();

	SendMeshMatrixToShader(meshObject);

	BindIBO();
	const GLsizei indecesSize = cache->GetIndicesSize();// to verif
	GlewHelper::Get()->DrawElementsInstanced(GL_TRIANGLES, indecesSize, meshObject->GetInstanceCount());
	ResetIBO();
	ResetVAO();
}

void GLRenderLibrary::RenderScene()
{
	m_MeshProgram->Bind();

	Camera* cam = SCENE_MANAGER->GetCamera();
	GLint viewLocation = GlewHelper::Get()->GetUniformLocation(m_MeshProgram->Get(), "u_View");
	GlewHelper::Get()->SetUniformMatrix(viewLocation, cam->GetView());

	std::unordered_map<std::string, MeshObject*> allMeshes = MESH_STORAGE->GetAll();
	for (int i = 0; i < allMeshes.size(); ++i)
	{
		Draw(Tools::IterateMap(allMeshes, i));
	}
}

void GLRenderLibrary::RenderSkybox()
{
	GlewHelper::Get()->SetDepthFunc(GL_LEQUAL);
	GlewHelper::Get()->SetDepthMask(false);

	m_SkyboxProgram->Bind();
	uint16_t skyboxLocation = m_SkyboxProgram->Get();

	Camera* cam = SCENE_MANAGER->GetCamera();
	GLint viewLocation = GlewHelper::Get()->GetUniformLocation(m_MeshProgram->Get(), "u_View");
	GlewHelper::Get()->SetUniformMatrix(viewLocation, cam->GetView());

	GLint SkyLocation = GlewHelper::Get()->GetUniformLocation(skyboxLocation, "u_SkyTexture");



	Skybox* skybox = SCENE_MANAGER->GetSkyBox();
	m_glTextureLibrary->SelectTexture(skybox->GetTextureID(), GL_TEXTURE1);
	GlewHelper::Get()->SetUniform(SkyLocation, 1);

	GlewHelper::Get()->ResetVertexArray();
	GlewHelper::Get()->ResetBuffer(GL_ARRAY_BUFFER);

	GlewHelper::Get()->DrawArrays(GL_TRIANGLE_STRIP, 4);
	GlewHelper::Get()->SetDepthFunc(GL_LESS);
	GlewHelper::Get()->SetDepthMask(true);
}

RenderCache* GLRenderLibrary::GetMeshData(MeshObject* mesh)
{
	if (!mesh)
		return nullptr;

	std::string meshName = mesh->GetMeshName();
	std::unordered_map<std::string, RenderCache*>::iterator iter = m_Cache.find(meshName);

	if (iter == m_Cache.end())
		m_Cache[meshName] = new RenderCache(mesh);

	return m_Cache[meshName];
}

void GLRenderLibrary::SetBufferData(RenderCache* cache)
{
	if (!cache)
		return;

	BindVAO();
		GlewHelper::Get()->BindBuffer(GL_ARRAY_BUFFER, m_VBO);
		GlewHelper::Get()->SetBufferData(GL_ARRAY_BUFFER, cache->GetBufferSize() * sizeof(float), cache->GetBufferAddress());
		GlewHelper::Get()->BindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_IBO);
		GlewHelper::Get()->SetBufferData(GL_ELEMENT_ARRAY_BUFFER, cache->GetIndicesSize() * sizeof(uint16_t), cache->GetIndicesAddress());
	ResetVAO();
}

void GLRenderLibrary::SendMeshMatrixToShader(MeshObject* mesh)
{
	if (!mesh)
		return;

	std::vector<math::Mat4> worlds;
	mesh->CollectWorlds(worlds);

	if (!worlds.empty())
	{
		BindUBO();
		m_worldsData.clear();
		RegisterMatrixData(worlds);
		GlewHelper::Get()->SetBufferSubData(GL_UNIFORM_BUFFER, 0, (GLsizei)m_worldsData.size() * sizeof(float), &m_worldsData[0]);
		ResetUBO();
	}
}

void GLRenderLibrary::RegisterMatrixData(std::vector<math::Mat4> const& worlds)
{
	for (int index = 0; index < worlds.size(); index++)
	{
		math::Mat4 revertedWorldMat = worlds[index].GetRevertedMatrix();

		for (int j = 0; j < _countof(worlds[index].m); j++)
			m_worldsData.push_back(revertedWorldMat.m[j]);
	}
}

void GLRenderLibrary::BindVAO() const
{
	GlewHelper::Get()->BindVertexArray(m_VAO);
}

void GLRenderLibrary::BindVBO() const
{
	GlewHelper::Get()->BindBuffer(GL_ARRAY_BUFFER, m_VBO);
}

void GLRenderLibrary::BindIBO() const
{
	GlewHelper::Get()->BindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_IBO);
}

void GLRenderLibrary::BindUBO() const
{
	GlewHelper::Get()->BindBuffer(GL_UNIFORM_BUFFER, m_UBO);
}

void GLRenderLibrary::ResetVAO() const
{
	GlewHelper::Get()->ResetVertexArray();
}

void GLRenderLibrary::ResetVBO() const
{
	GlewHelper::Get()->ResetBuffer(GL_ARRAY_BUFFER);
}

void GLRenderLibrary::ResetUBO() const
{
	GlewHelper::Get()->ResetBuffer(GL_UNIFORM_BUFFER);
}

void GLRenderLibrary::ResetIBO() const
{
	GlewHelper::Get()->ResetBuffer(GL_ELEMENT_ARRAY_BUFFER);
}