#pragma once
#include <string>
#include "Helpers\GlewHelper.h"

class Skybox
{
public:
	Skybox(std::string const& name);
	//Skybox(Skybox const&) = delete;
	//Skybox(Skybox&&) = delete;
	~Skybox();

	inline int GetTextureID() const { return m_TextureID; }

	void Initialize();

	void SetName(std::string value);

	std::string Serialize();
	void Deserialize(std::string& data);

private:
	std::string m_Name;
	GLuint m_Texture;

	int m_TextureID = -1;
};

