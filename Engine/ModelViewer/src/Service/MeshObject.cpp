#include "Service\MeshObject.h"
#include "Service\servicelocator.h"
#include "Service\Tools.h"
#include "Component\Mesh.h"
#include "Mat4.h"

MeshObject::MeshObject(std::string const& name)
{
	m_Name = name;
}

MeshObject::MeshObject(std::string const& name, std::string const& path)
{
	m_Name = name;
	LoadFromFile(path);
}


MeshObject::~MeshObject()
{
}

int MeshObject::RegisterMesh(component::Mesh* newMesh)
{
	if (!newMesh)
		return -1;

	int newID = m_lastID;
	m_InstancedMeshes[m_lastID] = newMesh;
	++m_lastID;

	return newID;
}

void MeshObject::RemoveMesh(int meshID)
{
	m_InstancedMeshes.erase(meshID);
}

size_t MeshObject::GetInstanceCount()
{
	return m_InstancedMeshes.size();
}

void MeshObject::CollectWorlds(std::vector<math::Mat4>& worlds) const
{
	if (m_InstancedMeshes.empty())
		return;

	std::unordered_map<int, component::Mesh*>::const_iterator iter = m_InstancedMeshes.begin();
	std::unordered_map<int, component::Mesh*>::const_iterator end = m_InstancedMeshes.end();

	while (iter != end)
	{
		SceneNode* node = iter->second->GetNode();
		if (node)
		{
			Scene* scene = node->GetCurrentScene();
			if (scene->IsActive() && node->IsVisible())
			{
				component::Transform* transform = node->GetTransform();
				math::Mat4 world = transform->GetWorld();

				worlds.push_back(world);
			}
		}
		++iter;
	}
}

void MeshObject::LoadFromFile(std::string const& path)
{
	if (path.empty())
		return;

	std::string content = FILE_LOADER->LoadFile(path);
	ParseFile(content);
}

void MeshObject::ParseFile(std::string const& content)
{
	if (content.empty())
		return;

	TempVertices tempVertices;

	std::istringstream contentStream = std::istringstream(content);

	std::string line;
	while (std::getline(contentStream, line))
	{
		switch (line[0])
		{
		case 'v':
		{
			switch (line[1])
			{
			case 't':
			{
				ParseTexture(tempVertices, line);
				break;
			}

			case 'n':
			{
				ParseNormal(tempVertices, line);
				break;
			}

			default:
			{
				ParseVertices(tempVertices, line);
				break;
			}
			}

			break;
		}

		case 'f':
		{
			ParseFace(tempVertices, line);
			break;
		}

		default: break;
		}
	}

	Build(tempVertices);
}

void MeshObject::CharCallback(std::string const& line, char key, LineCallback const& callback)
{
	if (line[0] == key)
		callback(line);
}

void MeshObject::StringCallback(std::string const& line, std::string const& key, LineCallback const& callback)
{
	std::istringstream stream = std::istringstream(line);
	std::string part;
	std::getline(stream, part, ' ');

	if (part == key)
		callback(line);
}

void MeshObject::ParseVertices(TempVertices& tempVertices, std::string const& line)
{
	if (line.empty())
		return;

	std::vector<float> values = Tools::SplitFloats(line);

	math::Vector3 vertice(values[1], values[2], values[3]);
	tempVertices.geometrieVertices.push_back(vertice);
}

void MeshObject::ParseNormal(TempVertices& tempVertices, std::string const& line)
{
	if (line.empty())
		return;

	std::vector<int> values = Tools::SplitInts(line);

	math::Vector3 normal(values[1], values[2], values[3]);
	tempVertices.normalVertices.push_back(normal);
}

void MeshObject::ParseTexture(TempVertices& tempVertices, std::string const& line)
{
	if (line.empty())
		return;

	std::vector<float> values = Tools::SplitFloats(line);

	math::Vector2 textureVertice(values[1], values[2]);
	tempVertices.textureVertices.push_back(textureVertice);
}

void MeshObject::ParseFace(TempVertices& tempVertices, std::string const& line)
{
	if (line.find_first_of('/') == std::string::npos)
	{
		std::vector<float> values = Tools::SplitFloats(line);
		math::Vector3 vValue(values[1], values[2], values[3]);

		AddFace(tempVertices, vValue);
	}
	else
	{
		std::vector<std::string> values = Tools::Split(line);
		SetDispatchedFaceData(tempVertices, values);
	}
}

void MeshObject::SetDispatchedFaceData(TempVertices& tempVertices, std::vector<std::string> const& values)
{
	// ..values[0] = Geo Vertices
	// ..values[1] = Textures
	// ..values[2] = Normals
	std::vector<int> Xvalues = Tools::SplitInts(values[1], '/');
	std::vector<int> Yvalues = Tools::SplitInts(values[2], '/');
	std::vector<int> Zvalues = Tools::SplitInts(values[3], '/');

	math::Vector3 geoVertices(Xvalues[0], Yvalues[0], Zvalues[0]);

	AddFace(tempVertices, geoVertices);
}

void MeshObject::AddFace(TempVertices& tempVertices, math::Vector3 const& geoVert, math::Vector3 const& norVert, math::Vector3 const& texVert)
{
	UnbuildFace face;
	face.geometrieVerticeIndex = geoVert;
	face.normalVerticeIndex = norVert;
	face.textureVerticeIndex = texVert;
	tempVertices.faces.push_back(face);
}

void MeshObject::Build(TempVertices const& tempVertices)
{
	int i = 0;
	size_t size = tempVertices.faces.size();
	std::string log;

	for (int i = 0; i < size; i++)
	{
		BuildFace * Finalface = new BuildFace();
		Finalface->geometrieVertice.part1 = tempVertices.geometrieVertices[tempVertices.faces[i].geometrieVerticeIndex.x - 1];
		Finalface->geometrieVertice.part2 = tempVertices.geometrieVertices[tempVertices.faces[i].geometrieVerticeIndex.y - 1];
		Finalface->geometrieVertice.part3 = tempVertices.geometrieVertices[tempVertices.faces[i].geometrieVerticeIndex.z - 1];
		/*
		Finalface->textureVertice.part1 = tempVertices.textureVertices[tempVertices.faces[i].textureVerticeIndex.x];
		Finalface->textureVertice.part2 = tempVertices.textureVertices[tempVertices.faces[i].textureVerticeIndex.y];
		Finalface->textureVertice.part3 = tempVertices.textureVertices[tempVertices.faces[i].textureVerticeIndex.z];*/

		Finalface->normalVertice.part1 = tempVertices.normalVertices[tempVertices.faces[i].normalVerticeIndex.x];
		Finalface->normalVertice.part2 = tempVertices.normalVertices[tempVertices.faces[i].normalVerticeIndex.y];
		Finalface->normalVertice.part3 = tempVertices.normalVertices[tempVertices.faces[i].normalVerticeIndex.z];

		m_BuildedFaces.push_back(Finalface);
	}
}