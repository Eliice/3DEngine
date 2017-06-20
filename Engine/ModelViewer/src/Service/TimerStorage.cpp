#include "Service\TimerStorage.h"

#include "Service\Timer.h"
#include "Service\ServiceLocator.h"

namespace tools
{
	namespace service
	{
		TimerStorage::TimerStorage()
		{
			Initialize();
		}


		TimerStorage::~TimerStorage()
		{
			Shutdown();
		}

		void TimerStorage::AddTimer(std::string const timerName)
		{
			Timer* timer = new Timer();
			if (m_timers[timerName] != nullptr)
				LOGGER->Debuglog("timer name already in used, it has been replaced by default", LogLevel::WARNING);
			m_timers[timerName] = timer;
		}

		void TimerStorage::RemoveTimer(std::string const timerName)
		{
				m_timers[timerName] = nullptr;
		}

		double TimerStorage::GetTimer(std::string const timerName)
		{
			std::unordered_map<std::string, Timer*>::iterator iter = m_timers.find(timerName);
			if (iter != m_timers.end())
			{
				return m_timers[timerName]->GetFrameTime();
			}
			else
			{
				LOGGER->Debuglog("timer not found, returning NULL", LogLevel::WARNING);
				return 0;
			}

		}

		void TimerStorage::UpdateTimer(std::string const timerName)
		{
			if (m_timers[timerName] != nullptr)
				m_timers[timerName]->UpdateTime();
			else
				LOGGER->Debuglog("tried to update non-existant timer : " + timerName, LogLevel::WARNING);
		}

		void TimerStorage::Initialize()
		{
			SetName("Timers");
			m_timers = std::unordered_map<std::string, Timer*>();
			SERVICE_LOCATOR.EnableService(ServiceType::LOGER);
		}

		void TimerStorage::Shutdown()
		{
			m_timers.clear();
		}
	}
}

