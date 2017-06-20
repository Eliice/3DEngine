#pragma once

#include <iostream>
#include <sstream>
#include <fstream>

#include "Service\Service.h"
#include "Service\servicelocator.h"
#include "Scene\Scene.h"

#include "DllExport.h"

class Scene;

namespace tools {

	namespace service {

		class Serializer final : public Service
		{
			public:
			
				Serializer();
				~Serializer();

				void Initialize();
				void Shutdown();

				ENGINE_DLL void Save(Scene* scene, std::string path);
				ENGINE_DLL Scene* Deserialize(std::string name);
				
			private:

		};
	}
}