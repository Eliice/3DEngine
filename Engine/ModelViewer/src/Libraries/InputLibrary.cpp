#include "Libraries\InputLibrary.h"
#include "Service\servicelocator.h"


InputLibrary::InputLibrary(std::string const& name, Library* parent)
	: Library(name, parent)
{
	m_OnKeyDownEvent = new Event<Key>();
	m_OnKeyUpEvent = new Event<Key>();
	m_OnQuitEvent = new Event<>();
}


InputLibrary::~InputLibrary()
{
	delete m_OnKeyDownEvent;
	delete m_OnKeyUpEvent;
	delete m_OnQuitEvent;
}

void InputLibrary::Initialize()
{
	Library::Initialize();
	LIBRARY_MANAGER->SetActiveInputLibrary(this);
}

void InputLibrary::Shutdown()
{
}

void InputLibrary::Update()
{
}