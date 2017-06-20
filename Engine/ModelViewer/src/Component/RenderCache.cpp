#include "Component\RenderCache.h"
#include "Service\MeshObject.h"

RenderCache::RenderCache(MeshObject* mesh)
{
	std::vector<BuildFace*> faces = mesh->GetBuildedFaces();
	uint16_t nbVertices = 0;

	for (uint16_t index = 0; index < faces.size(); ++index)
	{
		GetVerticesFromVector3(faces[index]->geometrieVertice.part1);
		GetVerticesFromVector3(faces[index]->normalVertice.part1);
		GetVerticesFromVector3(faces[index]->textureVertice.part1);

		m_Indices.push_back(nbVertices);
		++nbVertices;

		GetVerticesFromVector3(faces[index]->geometrieVertice.part2);
		GetVerticesFromVector3(faces[index]->normalVertice.part2);
		GetVerticesFromVector3(faces[index]->textureVertice.part2);

		m_Indices.push_back(nbVertices);
		++nbVertices;

		GetVerticesFromVector3(faces[index]->geometrieVertice.part3);
		GetVerticesFromVector3(faces[index]->normalVertice.part3);
		GetVerticesFromVector3(faces[index]->textureVertice.part3);

		m_Indices.push_back(nbVertices);
		++nbVertices;
	}
}

RenderCache::~RenderCache()
{
	m_BufferData.clear();
}

void RenderCache::GetVerticesFromVector2(math::Vector2 const& vec)
{
	m_BufferData.push_back(vec.x);
	m_BufferData.push_back(vec.y);
}

void RenderCache::GetVerticesFromVector3(math::Vector3 const& vec)
{
	m_BufferData.push_back(vec.x);
	m_BufferData.push_back(vec.y);
	m_BufferData.push_back(vec.z);
}