#pragma once

#include <unordered_map>

#include "Service.h"
#include "DllExport.h"

namespace tools {
namespace service
{
	class Timer;

	class TimerStorage final : public Service
	{
	public:
		TimerStorage();
		~TimerStorage();

		ENGINE_DLL void AddTimer(std::string const timerName);
		void RemoveTimer(std::string const timerName);
		double GetTimer(std::string const timerName);
		void UpdateTimer(std::string const timerName);
		void Initialize();
		void Shutdown();

	private:


		std::unordered_map<std::string, Timer*> m_timers;


	};
}
}

