#include "Helpers\STBIHelper.h"
#include "Helpers\GlewHelper.h"

#ifndef STB_IMAGE_IMPLEMENTATION
#define STB_IMAGE_IMPLEMENTATION
#include "..\stb\stb_image.h"
#endif

std::unique_ptr<STBIHelper> STBIHelper::p_Instance = nullptr;

STBIHelper::STBIHelper()
{
}


STBIHelper::~STBIHelper()
{
}

STBIHelper* STBIHelper::Get()
{
	if (STBIHelper::p_Instance == nullptr)
		STBIHelper::p_Instance = std::make_unique<STBIHelper>();

	return STBIHelper::p_Instance.get();
}

uint8_t* STBIHelper::Load(std::string const& file, int* width, int* height, int* comp)
{
	return stbi_load(file.c_str(), width, height, comp, STBI_rgb_alpha);
}

void STBIHelper::Free(uint8_t* image)
{
	stbi_image_free(image);
}