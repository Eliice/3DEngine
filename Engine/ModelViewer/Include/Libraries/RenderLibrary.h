#pragma once
#include <string>

#include "Libraries\Library.h"
class RenderLibrary :
	public Library
{
public:
	RenderLibrary(std::string const& name, Library* parent);
	virtual ~RenderLibrary();

	virtual void Initialize() = 0;
	virtual void Render() = 0;
};

