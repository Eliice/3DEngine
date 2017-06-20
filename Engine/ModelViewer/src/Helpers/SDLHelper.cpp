#include "Helpers/SDLHelper.h"
#include "Service\servicelocator.h"

SDLHelper* SDLHelper::m_Instance = nullptr;

SDLHelper::SDLHelper()
{
}


SDLHelper::~SDLHelper()
{
}

SDLHelper* SDLHelper::Get()
{
	if (SDLHelper::m_Instance == nullptr)
		SDLHelper::m_Instance = new SDLHelper();

	return SDLHelper::m_Instance;
}

void SDLHelper::Init(int flags)
{
	if (SDL_Init(flags) < 0)
		LOGGER->Debuglog("SDL_Init failed : " + GetError(), tools::service::LogLevel::WARNING);
}

void SDLHelper::SetEnvironment(std::string const& environment, std::string const& value, bool overwrite)
{
	int env = SDL_setenv(environment.c_str(), value.c_str(), overwrite);
	LOGGER->Debuglog(std::to_string(env), tools::service::LogLevel::DEBUG);
}

SDL_GLContext SDLHelper::CreateContext(SDL_Window* window)
{
	if (!window)
		return NULL;

	return SDL_GL_CreateContext(window);
}

void SDLHelper::DestroyWindow(SDL_Window* window)
{
	if (!window)
		return;

	SDL_DestroyWindow(window);
}

void SDLHelper::DestroyContext(SDL_GLContext& context)
{
	SDL_GL_DeleteContext(context);
}

int SDLHelper::PollEvent(SDL_Event* evt)
{
	return SDL_PollEvent(evt);
}

SDL_Scancode SDLHelper::GetScancode(SDL_Event const& evt)
{
	return evt.key.keysym.scancode;
}

SDL_Keycode SDLHelper::GetKeycode(SDL_Event const& evt)
{
	
	return evt.key.keysym.sym;
}

void SDLHelper::SwapWindow(SDL_Window* window)
{
	if (!window)
		return;

	SDL_GL_SwapWindow(window);
}

std::string SDLHelper::GetError() const
{
	return std::string(SDL_GetError());
}

void SDLHelper::Shutdown()
{
	SDL_Quit();
}

SDL_Window* SDLHelper::CreateWin(std::string const& title, int width, int height)
{
	return SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_OPENGL);
}

SDL_Window* SDLHelper::CreateWindowFrom(const void* data)
{
	return SDL_CreateWindowFrom(data);
}