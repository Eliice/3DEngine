#pragma once

#include <functional>
#include <vector>
#include <unordered_map>
#include "Vector2.h"
#include "Vector3.h"

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

struct TempVertices
{
	std::vector<math::Vector3> geometrieVertices;
	std::vector<math::Vector3> normalVertices;
	std::vector<math::Vector2> textureVertices;
	std::vector<UnbuildFace> faces;
};

namespace component
{
	class Mesh;
}

class MeshObject
{
	typedef std::function<void(std::string const&)> LineCallback;

public:
	MeshObject(std::string const& name);
	MeshObject(std::string const& name, std::string const& path);
	~MeshObject();

	int RegisterMesh(component::Mesh* newMesh);
	void RemoveMesh(int meshID);

	size_t GetInstanceCount();

	void CollectWorlds(std::vector<math::Mat4>& worlds) const;

	std::vector<BuildFace*> GetBuildedFaces() { return m_BuildedFaces; }
	std::string GetMeshName() const { return m_Name; }

private:
	void LoadFromFile(std::string const& path);
	void ParseFile(std::string const& content);

	void CharCallback(std::string const& line, char key, LineCallback const& callback);
	void StringCallback(std::string const& line, std::string const& key, LineCallback const& callback);

	void ParseVertices(TempVertices& tempVertices, std::string const& line);
	void ParseTexture(TempVertices& tempVertices, std::string const& line);
	void ParseNormal(TempVertices& tempVertices, std::string const& line);
	void ParseFace(TempVertices& tempVertices, std::string const& line);
	void SetDispatchedFaceData(TempVertices& tempVertices, std::vector<std::string> const& values);

	void AddFace(TempVertices& tempVertices, math::Vector3 const& geoVert = math::Vector3(), math::Vector3 const& norVert = math::Vector3(), math::Vector3 const& texVert = math::Vector3());

	void Build(TempVertices const& tempVertices);

	std::unordered_map<int, component::Mesh*> m_InstancedMeshes;
	std::vector<BuildFace*> m_BuildedFaces;

	std::string m_Name;

	int m_lastID = 0;
};

