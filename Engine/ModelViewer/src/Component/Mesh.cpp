#include "Component\Mesh.h"
#include "Component\BasicShader.h"
#include "Service\ServiceLocator.h"
#include "Service\Tools.h"
#include "Scene\Scene.h"
#include "Scene\scenenode.h"
#include "Component\Transform.h"
#include "Component\Texture.h"
#include "Service/MeshObject.h"
#include <fstream>
#include <algorithm>

namespace component
{
	Mesh::Mesh(SceneNode* node)
		:Mesh(node, "Test Cube","../Ressources/cube.obj")
	{
	}

	Mesh::Mesh(SceneNode* node, std::string const& name, std::string const &path)
		: Component("Mesh")
	{
		m_Node = node;
		m_MeshName = name;
		m_MeshObject = MESH_STORAGE->LoadMesh(name, path);
		
		if (m_MeshObject)
			m_meshID = m_MeshObject->RegisterMesh(this);
	}

	Mesh::~Mesh()
	{
		m_MeshObject->RemoveMesh(m_meshID);
		m_MeshObject = nullptr;
	}

	void Mesh::AddTexture(component::Texture * newTexture)
	{
		m_texture = newTexture;
	}

	void Mesh::RemoveTexture()
	{
		m_texture = nullptr;
	}

	void Mesh::Draw() const
	{
		
	}
}
