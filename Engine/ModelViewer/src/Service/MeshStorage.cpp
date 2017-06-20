#include "Service\MeshStorage.h"

#include "Component\Mesh.h"
#include "Service\ServiceLocator.h"
#include "Service\Tools.h"
#include "Service\MeshObject.h"

namespace tools
{
	namespace service
	{
		MeshStorage::MeshStorage()
		{
			OnNewMesh = new Event<std::unordered_map<std::string, component::Mesh*>>();
			Initialize();
		}


		MeshStorage::~MeshStorage()
		{
			Shutdown();

			delete OnNewMesh;
		}

		void MeshStorage::Initialize()
		{
			//meshStorage = std::unordered_map<std::string, component::Mesh*>();
			SERVICE_LOCATOR.EnableService(ServiceType::LOGER);
			SetName("MeshStorage");

			LoadDefaultMeshes();
		}

		void MeshStorage::Shutdown()
		{
			std::unordered_map<std::string, MeshObject*>::iterator iter = m_MeshObjects.begin();
			std::unordered_map<std::string, MeshObject*>::iterator end = m_MeshObjects.end();

			while (iter != end)
			{
				delete iter->second;
				++iter;
			}

			m_MeshObjects.clear();
		}

		void MeshStorage::LoadDefaultMeshes()
		{
			std::string fileContent = FILE_LOADER->LoadFile("../ModelViewer/Config/defaultmodels.cfg");

			std::vector<std::string> configs = Tools::Split(fileContent, '\n');

			for (int i = 0; i < configs.size(); i++)
			{
				std::vector<std::string> config = Tools::Split(configs[i], '=');
				m_MeshObjects[config[0]] = new MeshObject(config[0], "../Ressources/" + config[1]);
			}
		}

		MeshObject* MeshStorage::LoadMesh(std::string const& name, std::string const& path)
		{
			if (name.empty())
				return nullptr;

			std::unordered_map<std::string, MeshObject*>::const_iterator iter = m_MeshObjects.find(name);

			if (iter == m_MeshObjects.end())
				m_MeshObjects[name] = new MeshObject(name, path);

			return m_MeshObjects[name];
		}

		void MeshStorage::BindNewMeshEvent(EventCallback const& callback)
		{
			OnNewMesh->Bind(callback);
		}

/*		void MeshStorage::Draw()
		{
			std::unordered_map<std::string, component::Mesh*>::iterator start = meshStorage.begin();
			std::unordered_map<std::string, component::Mesh*>::iterator end = meshStorage.end();

			for (; start != end; ++start)
				start->second->Draw();

			//RENDERER->Draw();
		}*/
	}
}

