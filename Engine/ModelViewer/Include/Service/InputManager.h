#pragma once
#include <unordered_map>
#include <memory>

#include "Plugins\Event.h"
#include "Key.h"

class InputManager
{
	// TODO : Change this to a Service
	typedef Event<unsigned char, int, int>::EventCallback EventCallback;

	public:
		InputManager();
		~InputManager();

		static InputManager* Get();

		void Init();
		void Shutdown();

		Event<Key>* GetKeyDownEvent() { return m_OnKeyDown; }
		Event<Key>* GetKeyUpEvent() { return m_OnKeyUp; }

		void ExecuteKeyDownEvent(Key key);
		void ExecuteKeyUpEvent(Key key);

	private:
		static std::unique_ptr<InputManager> m_Instance;

		Event<Key>* m_OnKeyDown;
		Event<Key>* m_OnKeyUp;

		int m_OnLibKeyDownEvent = 0;
		int m_OnLibKeyUpEvent = 0;
};