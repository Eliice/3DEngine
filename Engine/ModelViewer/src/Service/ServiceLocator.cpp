#include "Service\ServiceLocator.h"

#include "Service\ErrorManager.h"
#include "Service\Serializer.h"
#include "Service\Log.h"
#include "Service\TimerStorage.h"
#include "Service\FileLoader.h"
#include "Service\MeshStorage.h"
#include "Component\Renderer.h"
#include "Scene\SceneManager.h"
#include "Service\TextureStorage.h"
#include "Service\ThreadPool.h"
#include "Service\LibraryManager.h"

namespace tools
{
	std::unique_ptr<ServiceLocator> ServiceLocator::locator;

	ServiceLocator& ServiceLocator::Get()
	{
		if (!locator)
		{
			locator.reset(new ServiceLocator);
		}
		return *locator;
	}

	ServiceLocator::~ServiceLocator()
	{
		std::unordered_map<std::string, service::Service*>::iterator iter = m_serviceList.begin();
		std::unordered_map<std::string, service::Service*>::iterator end = m_serviceList.end();

		while (iter != end)
		{
			delete iter->second;
			++iter;
		}

		m_serviceList.clear();
	}

	void ServiceLocator::EnableService(service::ServiceType service_type)
	{
		switch (service_type)
		{
		case service::ServiceType::LOGER:
		{
			service::Log * log = new service::Log();
			SetService(log);
			break;
		}
		case service::ServiceType::ERRORMANAGER:
		{
			service::ErrorManager * error_manager = new service::ErrorManager();
			SetService(error_manager);
			break;
		}
		case service::ServiceType::TIMER:
		{
			service::TimerStorage* timer_storage = new service::TimerStorage();
			SetService(timer_storage);
			break;
		}
		case service::ServiceType::FILELOADER:
		{
			service::FileLoader* file_loader = new service::FileLoader();
			SetService(file_loader);
			break;
		}
		case service::ServiceType::MESHSTORAGE:
		{
			service::MeshStorage* meshStorage = new service::MeshStorage();
			SetService(meshStorage);
			break;
		}
		case service::ServiceType::TEXTURESTORAGE:
		{
			service::TextureStorage* textureStorage = new service::TextureStorage();
			SetService(textureStorage);
			break;
		}
		case service::ServiceType::RENDER:
		{
			service::Renderer* renderer = new service::Renderer();
			SetService(renderer);
			break;
		}

		case service::ServiceType::SCENEMANAGER:
		{
			service::SceneManager* sceneManager = new service::SceneManager();
			SetService(sceneManager);
			break;
		}
		case service::ServiceType::THREADPOOL:
		{
			service::ThreadPool* pool = new service::ThreadPool();
			SetService(pool);
			break;
		}
		case service::ServiceType::SERIALIZE:
		{
			service::Serializer* serialize = new service::Serializer();
			SetService(serialize);
			break;
		}
		case service::ServiceType::LIBRARYMANAGER:
		{
			service::LibraryManager* lib = new service::LibraryManager();
			SetService(lib);
			break;
		}
		case service::ServiceType::PHYSC:
		{
			service::PhysXWrapper* physx = new service::PhysXWrapper();
			SetService(physx);
			break;
		}
		}
	}

	void ServiceLocator::Shutdown()
	{
		std::unordered_map<std::string, service::Service*>::iterator iter = m_serviceList.begin();
		std::unordered_map<std::string, service::Service*>::iterator end = m_serviceList.end();

		while (iter != end)
		{
			iter->second->Shutdown();
			++iter;
		}
	}

	void ServiceLocator::SetService(service::Service* service)
	{
		m_serviceList[service->GetName()] = service;
	}

	service::Service* ServiceLocator::GetService(std::string const& service_type)
	{
		std::unordered_map<std::string, service::Service*>::iterator iter = m_serviceList.find(service_type);

		if (iter != m_serviceList.end())
			return m_serviceList[service_type];

		return nullptr;
	}
}