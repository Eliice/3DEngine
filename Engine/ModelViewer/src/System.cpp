#include "Service\ServiceLocator.h"

#include <future>

#include "Scene\Camera.h"
#include "System.h"
#include "Service\Tools.h"
#include "Helpers\GlutHelper.h"
#include "Helpers\FunctionBindHelper.h"
#include "Window.h"

#include "Libraries\InputLibrary.h"
#include "Libraries\SDLLibrary.h"
#include "Libraries\OpenGLLibrary.h"
#include "Service\ServiceLocator.h"
 
System::System(int argc, char* argv[])
{
	m_Argc = argc;
	m_Argv = argv;

	if (argc > 0)
		m_Window = new Window((std::string)m_Argv[1], std::stoi(m_Argv[2]), std::stoi(m_Argv[3]), std::stoi(m_Argv[4]), std::stoi(m_Argv[5]));
}


System::~System()
{
	StopSimulation();
	InputLibrary* inputLib = LIBRARY_MANAGER->GetInputLibrary();

	Event<>* OnQuitEvent = inputLib->GetQuitEvent();
	OnQuitEvent->Unbind(m_OnQuitEvent);

	delete m_Window;
}

void System::Initialize()
{
	InitServices();

	InitLibraries();
	SCENE_MANAGER->InitCamera();

	InitWindow();

	OpenGLLibrary* openglLib = new OpenGLLibrary();
	openglLib->Initialize();
	RENDERER->Initialize();

	SCENE_MANAGER->AddTestScene();

	TIMERS->AddTimer("FrameTimer");

	//StartSimulation();
}

void System::InitServices()
{
	tools::SERVICE_LOCATOR.EnableService(tools::service::ServiceType::LOGER);
	tools::SERVICE_LOCATOR.EnableService(tools::service::ServiceType::ERRORMANAGER);
	tools::SERVICE_LOCATOR.EnableService(tools::service::ServiceType::FILELOADER);
	tools::SERVICE_LOCATOR.EnableService(tools::service::ServiceType::TIMER);
	tools::SERVICE_LOCATOR.EnableService(tools::service::ServiceType::THREADPOOL);
	tools::SERVICE_LOCATOR.EnableService(tools::service::ServiceType::SCENEMANAGER);
	tools::SERVICE_LOCATOR.EnableService(tools::service::ServiceType::MESHSTORAGE);
	tools::SERVICE_LOCATOR.EnableService(tools::service::ServiceType::TEXTURESTORAGE);
	tools::SERVICE_LOCATOR.EnableService(tools::service::ServiceType::LIBRARYMANAGER);
	tools::SERVICE_LOCATOR.EnableService(tools::service::ServiceType::RENDER);
	tools::SERVICE_LOCATOR.EnableService(tools::service::ServiceType::PHYSC);
}

void System::InitLibraries()
{
	SDLLibrary* sdlLib = new SDLLibrary(m_Window);
	sdlLib->Initialize();

	InputLibrary* inputLib = LIBRARY_MANAGER->GetInputLibrary();

	Event<>* OnQuitEvent = inputLib->GetQuitEvent();
	m_OnQuitEvent = OnQuitEvent->Bind(FunctionBindHelper::Bind(this, &System::Stop));
}

void System::FixedLoop() 
{
	double timer = 0;
	double TargetTime = 0.04;
	while (m_simulationStart)
	{
		TIMERS->UpdateTimer("FixedUpdateTimer");
		timer += TIMERS->GetTimer("FixedUpdateTimer");
		if (timer > TargetTime)
		{
			PHYSX->PhysicLoop();
			OverlapCheck();
			std::unordered_map<std::string,Scene*>* activeScene = SCENE_MANAGER->GetActiveScene();
			for (int i = 0; i < activeScene->size(); i++)
			{
				Scene * scene = Tools::IterateMap(*activeScene, i);
				scene->FixedUpdate();
			}
			timer = 0;
		}
	}
}

void System::UpdateLoop() const
{
	SCENE_MANAGER->Update();
}

void System::LateUpdateLoop() const
{
	SCENE_MANAGER->LateUpdate();
}

void System::Start() const
{
	SCENE_MANAGER->Start();
}

void System::InitWindow()
{
	m_Window->Create();
}

void System::SimulationLoop() const
{
	UpdateLoop();
	m_Window->Swap();
	LateUpdateLoop();
}

void System::Run() const
{
	
	while (m_IsRunning)
	{
		TIMERS->UpdateTimer("FrameTimer");
		LIBRARY_MANAGER->Update();
		RENDERER->RenderLoop();
		if (m_simulationStart)
		{
			SimulationLoop();
		}
	}

}

void System::StartSimulation()
{
	m_simulationStart = true;
	TIMERS->AddTimer("FixedUpdateTimer");
	THREAD_POOL->AddToQueue(FunctionBindHelper::Bind(this,&System::FixedLoop));
	Start();
}

void System::StopSimulation()
{
	m_simulationStart = false;
	TIMERS->RemoveTimer("FixedUpdateTimer");
}

void System::Stop()
{
	m_IsRunning = false;
}

void System::Shutdown() const
{
	SCENE_MANAGER->Destroy();
	tools::SERVICE_LOCATOR.Shutdown();
}

void System::OverlapCheck()const 
{
	SCENE_MANAGER->OverlapCheck();
}
