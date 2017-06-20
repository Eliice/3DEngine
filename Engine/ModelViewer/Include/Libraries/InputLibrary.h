#pragma once
#include <string>

#include "Libraries\Library.h"
#include "Plugins\Event.h"

#include "Key.h"

class InputLibrary : public Library
{
public:
	InputLibrary(std::string const& name, Library* parent = nullptr);
	virtual ~InputLibrary();

	virtual void Initialize() = 0;
	virtual void Shutdown() = 0;

	Event<Key>* GetKeyDownEvent() { return m_OnKeyDownEvent; }
	Event<Key>* GetKeyUpEvent() { return m_OnKeyUpEvent; }
	Event<>* GetQuitEvent() { return m_OnQuitEvent; }

	virtual void Update();

protected:
	Event<Key>* m_OnKeyDownEvent;
	Event<Key>* m_OnKeyUpEvent;
	Event<>* m_OnQuitEvent;
};

