#include "Service\LibraryManager.h"
#include "Libraries\InputLibrary.h"
#include "Service\servicelocator.h"

namespace tools
{
	namespace service
	{
		LibraryManager::LibraryManager()
		{
			Initialize();
		}


		LibraryManager::~LibraryManager()
		{
			m_InputLibrary = nullptr;

			std::unordered_map<std::string, Library*>::iterator it = m_Libraries.begin();
			std::unordered_map<std::string, Library*>::iterator end = m_Libraries.end();

			while (it != end)
			{
				delete it->second;
				++it;
			}

			m_Libraries.clear();
		}

		void LibraryManager::Initialize()
		{
			SetName("LibraryManager");
		}

		void LibraryManager::Shutdown()
		{
			std::unordered_map<std::string, Library*>::iterator iter = m_Libraries.begin();
			std::unordered_map<std::string, Library*>::iterator end = m_Libraries.end();

			while (iter != end)
			{
				iter->second->Shutdown();
				++iter;
			}
		}

		void LibraryManager::RegisterLibrary(Library* newLib)
		{
			if (!newLib)
				return;

			std::string name = newLib->GetName();
			std::unordered_map<std::string, Library*>::iterator iter = m_Libraries.find(name);

			if (iter == m_Libraries.end())
				m_Libraries[name] = newLib;
			else
				ERROR_MANAGER->Fatal("The library " + name + " already exists");
		}

		void LibraryManager::SetActiveInputLibrary(InputLibrary* newLib)
		{
			if (!newLib)
				return;

			m_InputLibrary = newLib;
		}

		void LibraryManager::SetActiveTextureLibrary(TextureLibrary* newLib)
		{
			if (!newLib)
				return;

			m_TextureLibrary = newLib;
		}

		void LibraryManager::SetActiveRenderLibrary(RenderLibrary* newLib)
		{
			if (!newLib)
				return;

			m_RenderLibrary = newLib;
		}

		void LibraryManager::Update() const
		{
			if (m_InputLibrary)
				m_InputLibrary->Update();
		}
	}
}