#include "QtSystem.h"
#include "Window.h"
#include "Libraries\OpenGLLibrary.h"

QtSystem::QtSystem()
{
	m_Argc = 0;
	m_Argv = nullptr;

	m_Window = new Window("Game", 0, 0, 100, 100);
}


QtSystem::~QtSystem()
{
}

void QtSystem::Initialize()
{
	InitServices();

	InitLibraries();
	SCENE_MANAGER->InitCamera();

	OpenGLLibrary* openglLib = new OpenGLLibrary();
	openglLib->Initialize();
	RENDERER->Initialize();

	SCENE_MANAGER->AddTestScene();

	TIMERS->AddTimer("FrameTimer");

	//StartSimulation();
}