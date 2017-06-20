#pragma once
#include <string>
#include <unordered_map>

#include "Service.h"

class Library;
class InputLibrary;
class TextureLibrary;
class RenderLibrary;

namespace tools
{
	namespace service
	{
		class LibraryManager final : public Service
		{
		public:
			LibraryManager();
			virtual ~LibraryManager();

			virtual void Initialize();
			virtual void Shutdown();

			void RegisterLibrary(Library* newLib);
			void SetActiveInputLibrary(InputLibrary* newLib);
			void SetActiveTextureLibrary(TextureLibrary* newLib);
			void SetActiveRenderLibrary(RenderLibrary* newLib);

			InputLibrary* GetInputLibrary() { return m_InputLibrary; }
			TextureLibrary* GetTextureLibrary() { return m_TextureLibrary; }
			RenderLibrary* GetRenderLibrary() { return m_RenderLibrary; }

			void Update() const;

		private:
			std::unordered_map<std::string, Library*> m_Libraries;

			InputLibrary* m_InputLibrary = nullptr;
			TextureLibrary* m_TextureLibrary = nullptr;
			RenderLibrary* m_RenderLibrary = nullptr;

		};
	}
}