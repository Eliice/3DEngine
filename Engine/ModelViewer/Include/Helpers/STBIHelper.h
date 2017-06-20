#pragma once

#include <memory>
#include <string>

class STBIHelper
{
public:
	STBIHelper();
	~STBIHelper();

	static STBIHelper* Get();

	uint8_t* Load(std::string const& file, int* width, int* height, int* comp);
	void Free(uint8_t* image);

private:
	static std::unique_ptr<STBIHelper> p_Instance;
};

