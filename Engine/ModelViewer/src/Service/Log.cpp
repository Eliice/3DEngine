#include "Service\Log.h"

#include <sys/stat.h>
#include <ctime>
#include <iostream>

namespace tools
{
	namespace service
	{
		Log::Log()
		{
			Initialize();
		}

		Log::~Log()
		{
			Shutdown();
		}

		void Log::Initialize()
		{
			std::string name = "Log";
			SetName(name);
		}

		void Log::Shutdown()
		{

		}

		void Log::Debuglog(std::string str, LogLevel const level)
		{
			std::string to_write = this->WriteLevel(level) + str;
			std::cout << to_write << std::endl;
		}

		std::string Log::WriteLevel(LogLevel const log_level)
		{
			switch (log_level)
			{
			case INFO:
				return WriteDate() + "[INFO]: ";
				break;

			case WARNING:
				return WriteDate() + "[WARNING]: ";
				break;

			case ERRORM:
				return WriteDate() + "[ERROR]: ";
				break;

			case DEBUG:
				return WriteDate() + "[DEBUG]: ";
				break;

			case FATAL:
				return WriteDate() + "[FATAL]: ";
				break;
			}
			return "";
		}


		std::string Log::WriteDate()
		{
			time_t rawTime;
			struct tm timeinfo;
			char buffer[20];

			time(&rawTime);
			localtime_s(&timeinfo, &rawTime);
			strftime(buffer, 20, "%a-%b-%d %H:%M:%S", &timeinfo);
			return buffer;
		}
	}
}