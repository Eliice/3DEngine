#pragma once
#include <memory>

#include "Component\Renderer.h"
#include "DllExport.h"

class Window;

class System
{
public:
	ENGINE_DLL System(int argc = 0, char* argv[] = nullptr);
	ENGINE_DLL virtual ~System();

	ENGINE_DLL virtual void Initialize();
	ENGINE_DLL void InitLibraries();
	ENGINE_DLL void InitServices();
	void InitWindow();
	ENGINE_DLL void Run() const;
	ENGINE_DLL void FrameUpdate() const;

	ENGINE_DLL void StartSimulation();
	ENGINE_DLL void StopSimulation();
	void Stop();

	void SimulationLoop() const;

	ENGINE_DLL void Shutdown() const;

protected:
	Window* m_Window;

	int m_Argc;
	char** m_Argv;
	void FixedLoop();
	void UpdateLoop() const;
	void LateUpdateLoop() const;
	void Start() const;
	void OverlapCheck() const;

private:
	int m_OnQuitEvent = 0;

	

	bool m_IsRunning = true;
	bool m_simulationStart = false;
};

