#pragma once
#include <vector>

#include "Vector2.h"
#include "Vector3.h"

class MeshObject;

class RenderCache
{
public:
	RenderCache(MeshObject* mesh);
	~RenderCache();

	inline float* GetBufferAddress() { return &m_BufferData[0]; }
	inline uint16_t* GetIndicesAddress() { return &m_Indices[0]; }

	inline size_t GetBufferSize() const { return m_BufferData.size(); }
	inline size_t GetIndicesSize() const { return m_Indices.size(); }

private :
	void GetVerticesFromVector2(math::Vector2 const& vec);
	void GetVerticesFromVector3(math::Vector3 const& vec);

	std::vector<float> m_BufferData;
	std::vector<uint16_t> m_Indices;
};

