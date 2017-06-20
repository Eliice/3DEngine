#include "Service\ThreadPool.h"

#include "Service\ServiceLocator.h"


namespace tools
{
	namespace service
	{
		ThreadPool::ThreadPool()
		{
			Initialize();
		}


		ThreadPool::~ThreadPool()
		{
			Shutdown();
		}

		void ThreadPool::Initialize()
		{
			SetName("ThreadPool");
			stop = false;
			int maxThread = std::thread::hardware_concurrency();
			std::string log = std::string("generating " + maxThread) ;
			log += " Thread";
			LOGGER->Debuglog(log, LogLevel::INFO);
			for (size_t i = 0; i < maxThread; ++i)
			{
				std::function<void()> function([this]() {Handler();});
				std::function<void()> handler = function;
				std::thread * newThread = new std::thread(handler);
				m_Pool.push_back(newThread);
			}
		}

		void ThreadPool::Shutdown()
		{
			stop = true;
			m_condition.notify_all();

			for (size_t i = 0; i < m_Pool.size(); ++i)
			{
				m_Pool[i]->join();
			}
		}

		void ThreadPool::AddToQueue(std::function<void()> function)
		{
			{
				std::unique_lock<std::mutex> lock(m_queue_mutex);

				m_Task.push_back(function);
			}

			m_condition.notify_one();
		}

		void ThreadPool::Handler()
		{
			std::function<void()> task;
			while (true)
			{
				std::unique_lock<std::mutex> lock(m_queue_mutex);
				while (!stop && m_Task.empty())
				{
					m_condition.wait(lock);
				}
				if (stop)
					return;
				task = m_Task.front();
				m_Task.pop_front();
				task();
			}
			
		}

	}
}

