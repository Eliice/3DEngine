#include "Libraries\SDLLibrary.h"
#include "Libraries\SDLPollEventLibrary.h"
#include "Helpers\SDLHelper.h"
#include "Service\servicelocator.h"
#include "Libraries\SDLWindow.h"

SDLLibrary::SDLLibrary(Window* window)
	: Library("SDL")
{
	if (window)
		InitWindowSubLib(window);

	SDLPollEventLibrary* pollEventLib = new SDLPollEventLibrary(this);
	AddSubLibrary(pollEventLib);
}


SDLLibrary::~SDLLibrary()
{
	SDLHelper::Get()->Shutdown();
}

void SDLLibrary::Initialize()
{
	SDLHelper::Get()->Init(SDL_INIT_VIDEO);

	Library::Initialize();
}

void SDLLibrary::InitWindowSubLib(Window* window)
{
	if (!window)
		return;

	SDLWindow* sdlWindow = new SDLWindow(window, this);
	sdlWindow->Initialize();
}

void SDLLibrary::InitPollEventSubLib()
{
	SDLPollEventLibrary* pollEventLib = new SDLPollEventLibrary(this);
	pollEventLib->Initialize();
}