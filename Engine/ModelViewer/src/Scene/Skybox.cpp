#include "Scene\Skybox.h"
#include "Service\servicelocator.h"
#include "Libraries\TextureLibrary.h"

Skybox::Skybox(std::string const& name)
{
	m_Name = name;
}


Skybox::~Skybox()
{
}

void Skybox::Initialize()
{
	//GlSkyBox::Get()->CreateSkyBox(m_Name.c_str(), &m_Texture);
	TextureLibrary* texLib = LIBRARY_MANAGER->GetTextureLibrary();

	m_TextureID = texLib->LoadTexture(m_Name, LINEAR);
}

void Skybox::SetName(std::string value)
{
	m_Name = value;
}

std::string Skybox::Serialize()
{
	return " \t Skybox: \n\t { \n\t\t name: " + m_Name + ",\n\t },\n";
}

void Skybox::Deserialize(std::string& data)
{
	std::string str;

	data.erase(0, data.find_first_of(":") + 2);
	data.erase(0, data.find_first_of(":") + 2);
	str = data.substr(0, data.find_first_of(","));

	m_Name = str;
}
