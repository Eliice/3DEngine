#pragma once
#include "Service\ServiceLocator.h"
#include "Plugins\Event.h"

#include "DllExport.h"

class Window
{
public:
	ENGINE_DLL Window(std::string const title, int x, int y, int width, int height);
	ENGINE_DLL virtual ~Window();

	Event<std::string, int, int>* GetCreateWindowEvent() { return m_OnCreateWindow; }
	Event<>* GetCallSwapWindowEvent() { return m_OnCallSwapWindow; }
	Event<>* GetDestroyEvent() { return m_OnDestroy; }

	ENGINE_DLL virtual void Create();
	void Swap();
private:
	Event<std::string, int, int>* m_OnCreateWindow;
	Event<>* m_OnCallSwapWindow;
	Event<>* m_OnDestroy;

	std::string m_Title;

	int m_PosX = 0;
	int m_PosY = 0;
	int m_Width = 0;
	int m_Height = 0;
};

