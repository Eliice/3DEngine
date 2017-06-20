#include "Component\Texture.h"
#include "Service\servicelocator.h"

namespace component
{
	Texture::Texture()
		:Component(m_Name)
	{

	}
	Texture::~Texture()
	{
	}

	void Texture::Load(std::string const& path, DrawMode const& drawMode)
	{
		//GlTexturing::Get()->Initialize("dragon.png");
		TextureLibrary* texLib = LIBRARY_MANAGER->GetTextureLibrary();

		m_ID = texLib->LoadTexture(path, drawMode);
	}

	void Texture::SetPath(std::string path)
	{
		m_path = path;
	}
	std::string Texture::Serialize()
	{
		std::string data;
		data = "{\n texture : " + m_path + "\n },\n";
		return data;
	}

	void Texture::Deserialize(std::string& data)
	{
		std::string str;
		str = data.substr(data.find("{\n texture : "), data.find("\n },\n"));
		m_path = str;
	
	}
}