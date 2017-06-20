#include "Service\Timer.h"

namespace tools
{
namespace service
{

	Timer::Timer()
	{
		Initialize();
	}

	void Timer::Initialize()
	{
		m_start = std::clock();
	}

	void Timer::Shutdown()
	{

	}

	void Timer::UpdateTime()
	{
		m_frameTime = (std::clock() - m_start) / (double)CLOCKS_PER_SEC;
		m_start = std::clock();
	}

	Timer::~Timer()
	{
		Shutdown();
	}

}
}

