#pragma once

//	Œp³æ‚ÅƒtƒŒƒ“ƒhw’è‚·‚é


template <typename T>
class Singleton
{

	Singleton()noexcept
		= default;
	~Singleton()noexcept
		= default;

public:

	static T& Instance()
	{
		static T instance;
		return instance;
	}
	Singleton(const Singleton&) = delete;
	Singleton& operator=(const Singleton&) = delete;

};