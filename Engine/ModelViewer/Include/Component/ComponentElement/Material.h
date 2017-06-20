#pragma once

#include <vector>

#include "Vector4.h"

namespace component {

	class Material
	{
		public:
			Material(float r, float g, float b, std::string n);
			Material(Material *mat);
			~Material() = default;

			std::string name;
			math::Vector4 color;
	};
}