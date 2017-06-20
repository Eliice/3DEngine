#include "Service\ErrorManager.h"

#include "Service\servicelocator.h"
#include <assert.h>

namespace tools
{
	namespace service
	{
		ErrorManager::ErrorManager()
		{
			Initialize();
		}

		ErrorManager::~ErrorManager()
		{
		}

		void ErrorManager::Initialize()
		{
			this->SetName("ErrorManager");
		}

		void ErrorManager::Shutdown()
		{
		}

		void ErrorManager::Fatal()
		{
			assert(false);
		}

		void ErrorManager::Fatal(std::string const& error)
		{
			LOGGER->Debuglog(error, service::LogLevel::FATAL);
			assert(false);
		}

		void ErrorManager::CheckReturn(int system_return)
		{
			assert(system_return >= 0);
		}

		void ErrorManager::CheckPointer(void * ptr)
		{
			assert(ptr != nullptr);
		}
		void ErrorManager::CheckBool(bool verif)
		{
			assert(verif);
		}
	}

}