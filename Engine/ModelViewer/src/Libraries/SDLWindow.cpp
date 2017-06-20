#include "Libraries\SDLWindow.h"
#include "Libraries\SDLLibrary.h"
#include "Helpers\SDLHelper.h"
#include "Plugins\Event.h"
#include "Helpers/FunctionBindHelper.h"
#include "window.h"

SDLWindow::SDLWindow(Window* window, SDLLibrary* parent)
	: Library("SDLWindow", parent)
{
	m_Window = window;
}


SDLWindow::~SDLWindow()
{
	m_SDLWindow = nullptr;
	m_Window = nullptr;
}

void SDLWindow::BindWindowEvents()
{
	if (!m_Window)
		return;

	Event<std::string, int, int>* OnCreateWindow = m_Window->GetCreateWindowEvent();
	Event<>* OnCallSwap = m_Window->GetCallSwapWindowEvent();
	Event<>* OnDestroyWindowEvent = m_Window->GetDestroyEvent();

	m_CreateWindowEvent = OnCreateWindow->Bind(FunctionBindHelper::Bind(this, &SDLWindow::Create));
	m_CallSwapEvent = OnCallSwap->Bind(FunctionBindHelper::Bind(this, &SDLWindow::Swap));
	m_DestroyWindowEvent = OnDestroyWindowEvent->Bind(FunctionBindHelper::Bind(this, &SDLWindow::Destroy));

	if (m_SDLWindow)
		Destroy();
}

void SDLWindow::Initialize()
{
	Library::Initialize();

	BindWindowEvents();
}

void SDLWindow::Shutdown()
{
	Event<std::string, int, int>* OnCreateWindow = m_Window->GetCreateWindowEvent();
	Event<>* OnCallSwap = m_Window->GetCallSwapWindowEvent();
	Event<>* OnDestroyWindowEvent = m_Window->GetDestroyEvent();

	OnCreateWindow->Unbind(m_CreateWindowEvent);
	OnCallSwap->Unbind(m_CallSwapEvent);
	OnDestroyWindowEvent->Unbind(m_DestroyWindowEvent);
}

void SDLWindow::Create(std::string const& title, int width, int height)
{
	m_SDLWindow = SDLHelper::Get()->CreateWin(title, width, height);
	m_Context = SDLHelper::Get()->CreateContext(m_SDLWindow);
}

void SDLWindow::Swap()
{
	SDLHelper::Get()->SwapWindow(m_SDLWindow);
}

void SDLWindow::Destroy()
{
	SDLHelper::Get()->DestroyContext(m_Context);
	SDLHelper::Get()->DestroyWindow(m_SDLWindow);
	m_SDLWindow = nullptr;
}