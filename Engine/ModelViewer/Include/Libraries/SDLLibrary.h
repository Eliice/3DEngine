#pragma once
#include "Libraries\Library.h"

class Window;

class SDLLibrary final : public Library
{
public:
	SDLLibrary(Window* window = nullptr);
	virtual ~SDLLibrary();

	virtual void Initialize() override;
	void InitWindowSubLib(Window* window);
	void InitPollEventSubLib();
};

