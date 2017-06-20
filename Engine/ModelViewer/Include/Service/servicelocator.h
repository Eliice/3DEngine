#pragma once

#include <unordered_map>

#include <memory>
#include "ServiceType.h"

#include "ErrorManager.h"
#include "Log.h"
#include "Service\FileLoader.h"
#include "TimerStorage.h"
#include "MeshStorage.h"
#include "Component\Renderer.h"
#include "Scene\SceneManager.h"
#include "Serializer.h"
#include "TextureStorage.h"
#include "ThreadPool.h"
#include "Service\PhysXWrapper.h"
#include "Service\LibraryManager.h"
#include "DllExport.h"


#define SERVICE_LOCATOR ServiceLocator::Get()
#define LOGGER dynamic_cast<tools::service::Log*>(tools::SERVICE_LOCATOR.GetService("Log"))
#define FILE_SYSTEM dynamic_cast<tools::service::FileSystem*>(tools::SERVICE_LOCATOR.GetService("FileSystem"))
#define ERROR_MANAGER dynamic_cast<tools::service::ErrorManager*>(tools::SERVICE_LOCATOR.GetService("ErrorManager"))
#define TIMERS dynamic_cast<tools::service::TimerStorage*>(tools::SERVICE_LOCATOR.GetService("Timers"))
#define FILE_LOADER dynamic_cast<tools::service::FileLoader*>(tools::SERVICE_LOCATOR.GetService("FileLoader"))
#define MESH_STORAGE dynamic_cast<tools::service::MeshStorage*>(tools::SERVICE_LOCATOR.GetService("MeshStorage"))
#define RENDERER dynamic_cast<tools::service::Renderer*>(tools::SERVICE_LOCATOR.GetService("Renderer"))
#define SERIALIZER dynamic_cast<tools::service::Serializer*>(tools::SERVICE_LOCATOR.GetService("Serializer"))
#define SCENE_MANAGER dynamic_cast<tools::service::SceneManager*>(tools::SERVICE_LOCATOR.GetService("SceneManager"))
#define TEXTURE_STORAGE dynamic_cast<tools::service::TextureStorage*>(tools::SERVICE_LOCATOR.GetService("TextureStorage"))
#define THREAD_POOL dynamic_cast<tools::service::ThreadPool*>(tools::SERVICE_LOCATOR.GetService("ThreadPool"))
#define LIBRARY_MANAGER dynamic_cast<tools::service::LibraryManager*>(tools::SERVICE_LOCATOR.GetService("LibraryManager"))
#define PHYSX dynamic_cast<tools::service::PhysXWrapper*>(tools::SERVICE_LOCATOR.GetService("PhysxWrapper"))

namespace tools
{
	class ServiceLocator final
	{
	public:
		ENGINE_DLL static ServiceLocator& Get();

		~ServiceLocator();

		void EnableService(service::ServiceType service_type);
		void SetService(service::Service* service);

		ENGINE_DLL service::Service* GetService(std::string const& service_type);

		void Shutdown();

	private:

		ServiceLocator() = default;

		ServiceLocator(ServiceLocator const&) = delete;
		ServiceLocator(ServiceLocator &&) = delete;

		ServiceLocator& operator=(ServiceLocator const &) = delete;
		ServiceLocator& operator=(ServiceLocator &&) = delete;

		std::unordered_map<std::string, service::Service*> m_serviceList;

		static std::unique_ptr<ServiceLocator> locator;
	};
}
