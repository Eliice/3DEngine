#include "Scene\SceneManager.h"
#include "Scene\Scene.h"
#include "Scene\SceneNode.h"
#include "Component\Mesh.h"
#include "Service\ServiceLocator.h"
#include "Component\BasicShader.h"
#include "Service\Tools.h"
#include "Component\Transform.h"
#include "Scene\Camera.h"

namespace tools
{
	namespace service
	{
		SceneManager::SceneManager()
		{
			Initialize();
		}

		SceneManager::~SceneManager()
		{
			Shutdown();
		}

		void SceneManager::Initialize()
		{
			SetName("SceneManager");
		}

		void SceneManager::Shutdown()
		{
			m_ActiveScene.clear();
			m_OtherScene.clear();
		}

		void SceneManager::InitCamera()
		{
			m_Camera = new Camera();
			m_Camera->Initialize();
		}

		void SceneManager::Start()
		{
			int index = 0;
			while (Scene* scene = Tools::IterateMap<Scene>(m_ActiveScene, index))
			{
				scene->Start();
				++index;
			}
		}

		void SceneManager::UpdateScene()
		{
			m_Camera->Render();

			int index = 0;
			while (Scene* scene = Tools::IterateMap<Scene>(m_ActiveScene, index))
			{
				scene->Update();
				++index;
			}
		}

		void SceneManager::Update()
		{
			for (int i =0; i < m_ActiveScene.size(); ++i)
			{
				Scene* scene = Tools::IterateMap(m_ActiveScene, i);
				scene->Update();
			}
		}

		void SceneManager::LateUpdate()
		{
			for (int i = 0; i < m_ActiveScene.size(); ++i)
			{
				Scene* scene = Tools::IterateMap(m_ActiveScene, i);
				scene->LateUpdate();
			}
		}

		void SceneManager::Destroy()
		{
			int index = 0;
			while (Scene* scene = Tools::IterateMap<Scene>(m_ActiveScene, index))
			{
				scene->Destroy();
				++index;
			}
		}

		Scene* SceneManager::AddScene(std::string const& name, bool isActive)
		{
			Scene* newScene = new Scene(name);

			if (isActive)
				m_ActiveScene[name] = newScene;
			else
				m_OtherScene[name] = newScene;

			newScene->Initialize();

			return newScene;
		}

		void SceneManager::EnableScene(std::string scene_name)
		{
			std::unordered_map<std::string, Scene*>::iterator it = m_OtherScene.find(scene_name);
			
			if (it != m_OtherScene.end())
			{
				m_ActiveScene[scene_name] = it->second;
				m_OtherScene.erase(it);
				it->second->SetActive(true);
			}
			else
				LOGGER->Debuglog("Scene not found", tools::service::WARNING);
		}
		void SceneManager::EnableScene(int scene_index)
		{
			Scene* scene = Tools::IterateMap<Scene>(m_OtherScene, scene_index);

			if (scene)
			{
				m_ActiveScene[scene->GetName()] = scene;
				m_OtherScene.erase(scene->GetName());
			}
			else
				LOGGER->Debuglog("Scene index not found", tools::service::WARNING);
		}
		void SceneManager::DisableScene(std::string scene_name)
		{
			std::unordered_map<std::string, Scene*>::iterator it = m_ActiveScene.find(scene_name);

			if (it != m_ActiveScene.end())
			{
				m_OtherScene[scene_name] = it->second;
				m_ActiveScene.erase(scene_name);
				it->second->SetActive(false);
			}
			else
				LOGGER->Debuglog("Scene not found", tools::service::WARNING);
		}
		void SceneManager::DisableScene(int scene_index)
		{
			Scene* scene = Tools::IterateMap<Scene>(m_OtherScene, scene_index);

			if (scene)
			{
				m_OtherScene[scene->GetName()] = scene;
				m_ActiveScene.erase(scene->GetName());
			}
			else
				LOGGER->Debuglog("Scene index not found", tools::service::WARNING);
		}

		void SceneManager::AddTestScene()
		{
			//SERIALIZER->Deserialize(FILE_LOADER->LoadFile("../ModelViewer/Saves/test.json"));
			
			Scene* testScene = AddScene("DefaultScene", true);
			/*SceneNode* cube = testScene->AddCubeNode();


			SceneNode* capsule = testScene->AddCapsuleNode();


			SceneNode* cube2 = testScene->AddCubeNode();

			component::Transform* t2 = cube2->GetTransform();
			t2->Translate(math::Vector3(-20, 0, -30));


			SceneNode* sphere = testScene->AddSphereNode();

			component::Transform* t3 = sphere->GetTransform();
			t3->Translate(math::Vector3(-10, 5, 0));

			SceneNode* sphere2 = testScene->AddSphereNode();

			component::Transform* t4 = sphere2->GetTransform();
			t4->Translate(math::Vector3(0, 0, 0));*/


			/*component::Transform* t5 = capsule->GetTransform();
			t5->Translate(math::Vector3(0, 0, -1000));
			t5->ApplyTransform();*/

			//SERIALIZER->Save(testScene, "Saves/test.json");
		}

		void SceneManager::RemoveScene(std::string const& name)
		{
			std::unordered_map<std::string, Scene*>::iterator it = m_ActiveScene.find(name);

			if (it == m_ActiveScene.end())
				it = m_OtherScene.find(name);

			if (it != m_ActiveScene.end() && it != m_OtherScene.end())
				m_DeleteQueue.push_back(it->second);
			

		}

		void SceneManager::RemoveScene(std::string const& name, Scene* scene)
		{
			if (scene == nullptr)
				return;

			m_ActiveScene.erase(name);
			m_OtherScene.erase(name);
			m_DeleteQueue.push_back(scene);
		}

		void SceneManager::RemoveAllScenes()
		{
			RemoveScenesFromMap(m_ActiveScene);
			RemoveScenesFromMap(m_OtherScene);
		}

		void SceneManager::RemoveScenesFromMap(std::unordered_map<std::string, Scene*>& map)
		{
			int index = 0;
			while (Scene* scene = Tools::IterateMap<Scene>(map, index))
			{
				scene->SetActive(false);
				m_DeleteQueue.push_back(scene);
				++index;
			}

			map.clear();
		}

		void SceneManager::ClearDeleteQueue()
		{
			for (Scene* scene : m_DeleteQueue)
				delete scene;

			m_DeleteQueue.clear();
		}

		void SceneManager::CreateSceneNode(std::string const& name, Scene* parentScene, SceneNode* parentNode)
		{
			if (parentScene == nullptr)
				return;

			SceneNode* newNode = new SceneNode(name, parentNode);
			component::Transform* transform = new component::Transform();
			newNode->SetTransform(transform, newNode);
			parentScene->AddNewNode(newNode, parentNode);
		}

		void SceneManager::CreateMeshSceneNode(std::string const& meshName, std::string const& path, std::string const& name, Scene* parentScene, SceneNode* parentNode)
		{
			if (parentScene == nullptr)
				return;

			SceneNode* newNode = new SceneNode(name, parentNode);
			component::Transform* transform = new component::Transform();
			

		}

		void SceneManager::CreateCubeSceneNode(std::string const& name, Scene* parentScene, SceneNode* parentNode)
		{
			
		}

		Scene* SceneManager::GetScene(std::string const& name)
		{
			std::unordered_map<std::string, Scene*>::iterator it = m_ActiveScene.find(name);
			
			if (it != m_ActiveScene.end())
				return m_ActiveScene[name];

			return nullptr;
		}

		Skybox* SceneManager::GetSkyBox()
		{
			if (m_ActiveScene.empty())
				return nullptr;

			std::unordered_map<std::string, Scene*>::iterator it = m_ActiveScene.begin();
			
			return it->second->GetSkybox();
		}
		void SceneManager::OverlapCheck()
		{
			int i = 0;
			size_t size = m_ActiveScene.size();
			for (i; i < size; ++i)
			{
				Scene * scene = Tools::IterateMap(m_ActiveScene, i);
				scene->Overlap();
			}
		}
	}
}