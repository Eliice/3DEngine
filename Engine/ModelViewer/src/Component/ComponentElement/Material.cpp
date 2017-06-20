
#include "..\..\..\Include\Component\ComponentElement\Material.h"

component::Material::Material(float r, float g, float b, std::string n)
	:name(n)
{
	color.x = r;
	color.y = g;
	color.z = b;
}

component::Material::Material(Material * mat)
{
	color = mat->color;
	name = mat->name;
}

