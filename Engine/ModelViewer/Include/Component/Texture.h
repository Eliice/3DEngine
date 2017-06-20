#pragma once
#include <string>

#include "Helpers\GlutHelper.h"
#include "Libraries\TextureLibrary.h"
#include "Component.h"

namespace component
{
	class Texture : public Component
	{
	public:

		Texture();
		~Texture();

		void Load(std::string const& path, DrawMode const& drawMode = LINEAR);

		inline size_t GetID() { return m_ID; }

		void SetPath(std::string path);

		std::string Serialize() override;
		void Deserialize(std::string& data) override;

	private:
		std::string m_path;
		size_t m_ID = -1;
	};
}

