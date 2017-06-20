#include "Window.h"

#include "Helpers\GlutHelper.h"



Window::Window(std::string const title, int x, int y, int width, int height)
	: m_Title(title), m_PosX(x), m_PosY(y), m_Width(width), m_Height(height)
{
	m_OnCreateWindow = new Event<std::string, int, int>();
	m_OnCallSwapWindow = new Event<>();
	m_OnDestroy = new Event<>();

	LOGGER->Debuglog("Init window", tools::service::LogLevel::INFO);
}

Window::~Window()
{
	(*m_OnDestroy)();

	delete m_OnCreateWindow;
	delete m_OnCallSwapWindow;
	delete m_OnDestroy;
}

void Window::Create()
{
	(*m_OnCreateWindow)(m_Title, m_Width, m_Height);
}

void Window::Swap()
{
	(*m_OnCallSwapWindow)();
}