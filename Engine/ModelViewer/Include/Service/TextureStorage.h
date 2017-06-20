#pragma once

#include <unordered_map>
#include "Service.h"

namespace component
{
	class Texture;
}

namespace tools
{
namespace service
{
	class TextureStorage : public Service
	{
	public:
		TextureStorage();
		~TextureStorage();

		void Initialize();
		void Shutdown();

		void AddTexture(std::string const name, component::Texture*);
		component::Texture* FindTexture(std::string const name);

	private:
		std::unordered_map<std::string, component::Texture*> m_Textures;
	};
}
}

