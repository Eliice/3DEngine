#pragma once
#include <functional>

class FunctionBindHelper
{
public:
	FunctionBindHelper() = default;
	~FunctionBindHelper() = default;

	template<typename T, typename Ret, typename... Args>
	static std::function<Ret(Args...)> Bind(T* obj, Ret(T::*func)(Args...))
	{
		return [=](Args... args)
		{
			return (obj->*func)(std::forward<Args>(args)...);
		};
	}
};

