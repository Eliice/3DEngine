#include "Libraries\SDLPollEventLibrary.h"
#include "Helpers\SDLHelper.h"
#include "Service\servicelocator.h"
#include "Service\Tools.h"

SDLPollEventLibrary::SDLPollEventLibrary(Library* parent)
	: InputLibrary("SDLPollEvent", parent), m_ConfigFile("../ModelViewer/Config/Libraries/SDL/keybinding.cfg")
{
}


SDLPollEventLibrary::~SDLPollEventLibrary()
{
	m_keyBinding.clear();
}

void SDLPollEventLibrary::Initialize()
{
	InputLibrary::Initialize();
	InitKeyBinding();
}

void SDLPollEventLibrary::Shutdown()
{
}

std::vector<int> SDLPollEventLibrary::LoadKeyBindingFile() const
{
	std::string fileContent = FILE_LOADER->LoadFile(m_ConfigFile.c_str());

	std::vector<int> sdlKeyList;

	if (!fileContent.empty())
		sdlKeyList = Tools::SplitInts(fileContent, ',');
	else
		LOGGER->Debuglog("File " + m_ConfigFile + " is empty", tools::service::LogLevel::WARNING);

	return sdlKeyList;
}

void SDLPollEventLibrary::InitKeyBinding()
{
	std::vector<int> keyList = LoadKeyBindingFile();

	if (!keyList.empty())
	{
		for (int index = 0; index < Key::NB_KEY; ++index)
		{
			m_keyBinding[(SDL_Scancode)keyList[index]] = (Key)index;
		}
	}
}

void SDLPollEventLibrary::Update()
{
	EventListener();
}

void SDLPollEventLibrary::EventListener()
{

	while (SDLHelper::Get()->PollEvent(&m_Evt))
	{
		switch (m_Evt.type)
		{
		case SDL_QUIT:
			(*m_OnQuitEvent)();
			break;

		case SDL_KEYDOWN:
		{
			ExecuteKeyEvent(m_OnKeyDownEvent);
			break;
		}
		case SDL_KEYUP:
		{
			ExecuteKeyEvent(m_OnKeyUpEvent);
			break;
		}
		default: break;
		}
	}
}

void SDLPollEventLibrary::ExecuteKeyEvent(Event<Key>* evt)
{
	SDL_Scancode scancode = SDLHelper::Get()->GetScancode(m_Evt);
	std::unordered_map<SDL_Scancode, Key>::const_iterator iter = m_keyBinding.find(scancode);

	if (iter != m_keyBinding.end())
		(*evt)(m_keyBinding[scancode]);
}