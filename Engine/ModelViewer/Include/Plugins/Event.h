#pragma once

#include <functional>
#include <vector>
#include <unordered_map>
#include <utility>
#include <iostream>
#include "EventReceiver.h"

template<typename... Args>
class Event
{
public:
	typedef std::function<void(Args...)> EventCallback;
	typedef EventReceiver<Args...> EventReceiver;

	Event() = default;
	Event(Event const&) = delete;
	Event(Event&&) = delete;
	~Event()
	{
		m_Callbacks.clear();
	}

	int Bind(EventCallback const& func)
	{
		int tempID = m_lastID;
		EventReceiver* receiver = new EventReceiver(func, tempID);
		m_Callbacks.push_back(receiver);

		++m_lastID;

		return tempID;
	}

	void Unbind(int receiverID)
	{
		EventReceiver* receiver = GetReceiverByID(receiverID);

		if (receiver != nullptr)
		{
			std::vector<EventReceiver*>::iterator it = std::find(m_Callbacks.begin(), m_Callbacks.end(), receiver);

			if (it != m_Callbacks.end())
				m_Callbacks.erase(it);
		}
	}

	EventReceiver* GetReceiverByID(int id)
	{
		for (int i = 0; i < m_Callbacks.size(); i++)
		{
			if (m_Callbacks[i]->GetID() == id)
				return m_Callbacks[i];
		}

		return nullptr;
	}

	void operator()(Args... args)
	{
		for (int i = 0; i < m_Callbacks.size(); i++)
		{
			m_Callbacks[i]->Execute(std::forward<Args>(args)...);
		}
	}

private:
	std::vector<EventReceiver*> m_Callbacks;

	int m_lastID = 0;
};

