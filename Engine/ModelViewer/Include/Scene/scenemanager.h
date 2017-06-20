#pragma once
#include <memory>
#include <vector>
#include <unordered_map>
#include <string>


#include "DllExport.h"
#include "Service\Service.h"

class Scene;
class SceneNode;
class Camera;
class Skybox;

namespace tools
{
	namespace service
	{
		class SceneManager : public Service
		{
		public:
			SceneManager();
			~SceneManager();

			void Initialize();
			void Shutdown();
		
			ENGINE_DLL void InitCamera();

			void Start();
			void UpdateScene();
			void Update();
			void LateUpdate();
			ENGINE_DLL void Destroy();

			ENGINE_DLL Scene* AddScene(std::string const& name, bool isActive);
			ENGINE_DLL void AddTestScene();

			ENGINE_DLL void RemoveScene(std::string const& name);
			ENGINE_DLL void RemoveScene(std::string const& name, Scene* scene);
			ENGINE_DLL void RemoveAllScenes();
			ENGINE_DLL void ClearDeleteQueue();

			void CreateSceneNode(std::string const& name = "New node", Scene* parentScene = nullptr, SceneNode* parentNode = nullptr);
			void CreateMeshSceneNode(std::string const& meshName, std::string const& path, std::string const& name = "New node", Scene* parentScene = nullptr, SceneNode* parentNode = nullptr);
			void CreateCubeSceneNode(std::string const& name = "New node", Scene* parentScene = nullptr, SceneNode* parentNode = nullptr);

			void EnableScene(std::string scene_name);
			void EnableScene(int scene_index);

			void DisableScene(std::string scene_name);
			void DisableScene(int scene_index);

			inline std::unordered_map<std::string, Scene*>* GetActiveScene() { return &m_ActiveScene; }
			ENGINE_DLL Scene* GetScene(std::string const& name);
			inline Camera* GetCamera() const { return m_Camera; }
			Skybox* GetSkyBox();
			void OverlapCheck();
		private:
			void RemoveScenesFromMap(std::unordered_map<std::string, Scene*>& map);

			std::unordered_map<std::string, Scene*> m_ActiveScene;
			std::unordered_map<std::string, Scene*> m_OtherScene;

			std::vector<Scene*> m_DeleteQueue;

			Camera* m_Camera = nullptr;
		};
	}
}