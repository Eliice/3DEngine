#pragma once

#include <vector>

#include "ComponentElement\Material.h"
#include "Vector3.h"
#include "ComponentElement\Material.h"
#include "Vector2.h"
#include "Mat4.h"
#include "Component.h"
#include "PxPhysics.h"

class MeshObject;
class SceneNode;

namespace component
{
	class Texture;

	struct PartFace
	{
		math::Vector3 part1;
		math::Vector3 part2;
		math::Vector3 part3;
	};

	struct BuildFace
	{

		PartFace geometrieVertice;
		PartFace textureVertice;
		PartFace normalVertice;
	};

	struct UnbuildFace
	{
		math::Vector3 geometrieVerticeIndex;
		math::Vector3 textureVerticeIndex;
		math::Vector3 normalVerticeIndex;
	};

	struct PhysxData
	{
		unsigned int Count;
		physx::PxVec3* Verts;
	};

	class Mesh : public Component
	{

	public:
		Mesh(SceneNode* node);
		Mesh(SceneNode* node, std::string const&, std::string const&);
		
		~Mesh();

		std::string GetMeshName() const { return m_MeshName; }
		SceneNode* GetNode() const { return m_Node; }

		void Store();


		void AddTexture(Texture* newTexture);
		void RemoveTexture();
		std::vector<math::Mat4> GetWorlds();

		inline auto GetData()->PhysxData { return m_physxData; } 

		virtual void Draw() const;

		void Mesh::LoadPhysxData();
	private:
		int m_meshID;

		void LoadMTL(std::string const&);

		void Build();

		std::string m_MeshName;

		MeshObject* m_MeshObject = nullptr;

		SceneNode* m_Node;
		component::Texture* m_texture;

		PhysxData m_physxData; 

		std::vector<Material*> m_materiaux;
	};
}
