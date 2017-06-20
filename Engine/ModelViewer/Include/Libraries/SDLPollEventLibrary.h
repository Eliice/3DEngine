#pragma once
#include <SDL.h>
#include <vector>
#include <unordered_map>
#include <string>

#include "InputLibrary.h"
#include "Key.h"

class SDLPollEventLibrary final : public InputLibrary
{
public:
	SDLPollEventLibrary(Library* parent);
	virtual ~SDLPollEventLibrary();

	virtual void Initialize() override;
	virtual void Shutdown() override;

	virtual void Update() override;

private:
	void EventListener();
	std::vector<int> LoadKeyBindingFile() const;
	void InitKeyBinding();
	void ExecuteKeyEvent(Event<Key>* evt);

	std::unordered_map<SDL_Scancode, Key> m_keyBinding;

	SDL_Event m_Evt;

	std::string const m_ConfigFile;
};

