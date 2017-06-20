#pragma once
#include "Service.h"

#include <thread>
#include <mutex>
#include <vector>
#include <deque>
#include <condition_variable>



namespace tools {
	namespace service
	{
		class ThreadPool :
			public Service
		{
		public:

			ThreadPool();
			~ThreadPool();

			void Initialize();
			void Shutdown();


			void AddToQueue(std::function<void()> function);
		private:

			void Handler();


			std::deque<std::function<void() > > m_Task;

			std::vector<std::thread*> m_Pool;
			std::mutex m_queue_mutex;
			std::condition_variable m_condition;
			bool stop;

		};
}
}

