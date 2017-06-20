#pragma once

#include <string>
#include "Service.h"

namespace tools
{
	namespace service
	{

		enum LogLevel
		{
			INFO,
			WARNING,
			ERRORM,
			DEBUG,
			FATAL
		};

		class Log final : public Service
		{
		public:
			Log();
			~Log();

			void Initialize();
			void Shutdown();
			void Debuglog(std::string str, LogLevel const level);
		private:
			std::string m_Path;

			std::string WriteLevel(LogLevel const log_level);
			std::string WriteDate();
		};

	}
}
