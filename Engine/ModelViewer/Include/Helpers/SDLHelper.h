#pragma once
#include <SDL.h>
#include <string>

#include "DllExport.h"


class SDLHelper
{
public:
	SDLHelper();
	~SDLHelper();

	ENGINE_DLL static SDLHelper* Get();

	void Init(int flags);

	ENGINE_DLL void SetEnvironment(std::string const& environment, std::string const& value, bool overwrite = true);

	SDL_Window* CreateWin(std::string const& title, int width, int height);
	ENGINE_DLL SDL_Window* CreateWindowFrom(const void* data);
	ENGINE_DLL SDL_GLContext CreateContext(SDL_Window* window);

	void DestroyWindow(SDL_Window* window);
	void DestroyContext(SDL_GLContext& context);

	int PollEvent(SDL_Event* evt);
	SDL_Scancode GetScancode(SDL_Event const& evt);
	SDL_Keycode GetKeycode(SDL_Event const& evt);

	void SwapWindow(SDL_Window* window);

	std::string GetError() const;

	void Shutdown();

private:
	static SDLHelper* m_Instance;
};

