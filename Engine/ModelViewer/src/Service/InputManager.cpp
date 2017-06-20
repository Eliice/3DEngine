#include "Service\InputManager.h"
#include "Helpers\GlutHelper.h"
#include "Service\ServiceLocator.h"

#include "Libraries\InputLibrary.h"
#include "Helpers\FunctionBindHelper.h"

std::unique_ptr<InputManager> InputManager::m_Instance = nullptr;

InputManager::InputManager()
{
	m_OnKeyDown = new Event<Key>();
	m_OnKeyUp = new Event<Key>();
}

InputManager::~InputManager()
{
	delete m_OnKeyDown;
	delete m_OnKeyUp;
}

InputManager* InputManager::Get()
{
	if (InputManager::m_Instance == nullptr)
	{
		InputManager::m_Instance = std::make_unique<InputManager>();
		InputManager::m_Instance->Init();
	}

	return InputManager::m_Instance.get();
}

void InputManager::Init()
{
	//GlutHelper::Get()->SetKeyboardFunc(InputManager::SetKeyDown, InputManager::SetKeyUp);
	InputLibrary* inputLib = LIBRARY_MANAGER->GetInputLibrary();

	if (!inputLib)
		LOGGER->Debuglog("Input Library is not loaded for InputManager", tools::service::LogLevel::ERRORM);

	Event<Key>* OnKeyDown = inputLib->GetKeyDownEvent();
	Event<Key>* OnKeyUp = inputLib->GetKeyUpEvent();

	m_OnLibKeyDownEvent = OnKeyDown->Bind(FunctionBindHelper::Bind(this, &InputManager::ExecuteKeyDownEvent));
	m_OnLibKeyUpEvent = OnKeyUp->Bind(FunctionBindHelper::Bind(this, &InputManager::ExecuteKeyUpEvent));
}

void InputManager::Shutdown()
{
	InputLibrary* inputLib = LIBRARY_MANAGER->GetInputLibrary();

	Event<Key>* OnKeyDown = inputLib->GetKeyDownEvent();
	Event<Key>* OnKeyUp = inputLib->GetKeyUpEvent();

	OnKeyDown->Unbind(m_OnLibKeyDownEvent);
	OnKeyUp->Unbind(m_OnLibKeyUpEvent);
}

void InputManager::ExecuteKeyDownEvent(Key key)
{
	(*m_OnKeyDown)(key);
}

void InputManager::ExecuteKeyUpEvent(Key key)
{
	(*m_OnKeyUp)(key);
}