#pragma once
#include <SDL.h>
#include <string>

#include "Libraries/Library.h"

class Window;
class SDLLibrary;

class SDLWindow : public Library
{
public:
	SDLWindow(Window* window, SDLLibrary* parent);
	virtual ~SDLWindow();

	virtual void Initialize() override;
	virtual void Shutdown() override;

	void Create(std::string const& title, int width, int height);
	void Swap();
	void Destroy();

private:
	void BindWindowEvents();

	SDL_Window* m_SDLWindow = nullptr;
	Window* m_Window = nullptr;

	SDL_GLContext m_Context;

	int m_CreateWindowEvent;
	int m_CallSwapEvent;
	int m_DestroyWindowEvent;
};

