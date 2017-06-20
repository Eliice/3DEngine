#pragma once
#include <functional>

template<typename... Args>
class EventReceiver
{
public:
	EventReceiver(std::function<void(Args...)> const& newCallback, int newID)
	{
		m_Callback = newCallback;
		m_ID = newID;
	}
	EventReceiver(EventReceiver const&) = delete;
	EventReceiver(EventReceiver&&) = delete;
	~EventReceiver() = default;

	EventReceiver& operator=(EventReceiver const&) = delete;
	EventReceiver& operator=(EventReceiver&&) = delete;

	int GetID() const { return m_ID; }

	void Execute(Args... args)
	{
		m_Callback(std::forward<Args>(args)...);
	}

private:
	std::function<void(Args...)> m_Callback;

	int m_ID = 0;
};

