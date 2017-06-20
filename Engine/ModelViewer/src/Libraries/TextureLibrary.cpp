#include "Libraries\TextureLibrary.h"
#include "Service\servicelocator.h"

TextureLibrary::TextureLibrary(std::string const& name, Library* parent)
	: Library(name, parent)
{
}


TextureLibrary::~TextureLibrary()
{
}

void TextureLibrary::Initialize()
{
	Library::Initialize();
	LIBRARY_MANAGER->SetActiveTextureLibrary(this);
}