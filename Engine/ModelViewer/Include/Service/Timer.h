#pragma once

#include <ctime>


namespace tools 
{
namespace service
{
	class Timer
	{
	public:
		Timer();
		~Timer();

		void Initialize();
		void Shutdown();

		void UpdateTime();
		double GetFrameTime() {return m_frameTime;}

	private:

		std::clock_t m_start;
		double m_frameTime = 0;

		///TODO: add target time and function pointer or trigger an event.

	};


}
}

