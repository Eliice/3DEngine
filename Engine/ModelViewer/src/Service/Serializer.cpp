#include "Service\Serializer.h"
#include "Service\servicelocator.h"

namespace tools {

	namespace service {

		Serializer::Serializer()
		{
			Initialize();
		}

		Serializer::~Serializer()
		{
			Shutdown();
		}

		void Serializer::Initialize()
		{
			SetName("Serializer");
		}

		void Serializer::Shutdown()
		{
		}

		void Serializer::Save(Scene * scene, std::string path)
		{
			if (!scene)
				return;

			std::string saveData;
			
			saveData = scene->Serialize();

			FILE_LOADER->Write(saveData, path);
		}

		Scene* Serializer::Deserialize(std::string name)
		{
			Scene* saveScene = SCENE_MANAGER->AddScene("test", true);

			saveScene->Deserialize(FILE_LOADER->LoadFile(name));

			return saveScene;
		}

	}
}