#pragma once
#include <string>

#include "Libraries/Library.h"

enum DrawMode
{
	LINEAR,
	NEAREST
};

class TextureLibrary : public Library
{
public:
	TextureLibrary(std::string const& name, Library* parent);
	virtual ~TextureLibrary();

	virtual void Initialize() override;

	virtual size_t LoadTexture(std::string const& file, DrawMode mode) = 0;
};

