#pragma once

#include <string>
#include "Service.h"

namespace tools
{
	namespace service
	{
		class ErrorManager final : public Service
		{
		public:
			ErrorManager();
			~ErrorManager();

			void Initialize();
			void Shutdown();
			void Fatal();
			void Fatal(std::string const& error_log);
			void CheckReturn(int system_return);
			void CheckPointer(void* ptr);
			void CheckBool(bool verif);
		private:

		};
	}
}
