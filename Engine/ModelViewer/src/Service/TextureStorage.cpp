#include "Service\TextureStorage.h"

#include "Component\Texture.h"
#include "Service\ServiceLocator.h"


namespace tools
{
namespace service
{
	TextureStorage::TextureStorage()
	{
		Initialize();
	}


	TextureStorage::~TextureStorage()
	{
	}
	void TextureStorage::Initialize()
	{
		m_Textures = std::unordered_map<std::string, component::Texture*>();
		SetName("TextureStorage");
	}
	void TextureStorage::Shutdown()
	{
		m_Textures.clear();
	}
	void TextureStorage::AddTexture(std::string const name, component::Texture *newTexture)
	{
		if (m_Textures[name] != nullptr)
			m_Textures[name] = newTexture;
		else
			LOGGER->Debuglog("name already used", LogLevel::WARNING);
	}
	component::Texture* TextureStorage::FindTexture(std::string const name)
	{
		if (m_Textures[name] != nullptr)
			return m_Textures[name];
		LOGGER->Debuglog("texture not found", LogLevel::WARNING);
		return nullptr;
	}
}
}

