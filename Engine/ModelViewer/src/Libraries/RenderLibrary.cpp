#include "Libraries\RenderLibrary.h"
#include "Service\servicelocator.h"

RenderLibrary::RenderLibrary(std::string const& name, Library* parent)
	: Library(name, parent)
{
}


RenderLibrary::~RenderLibrary()
{
}

void RenderLibrary::Initialize()
{
	Library::Initialize();
	LIBRARY_MANAGER->SetActiveRenderLibrary(this);
}