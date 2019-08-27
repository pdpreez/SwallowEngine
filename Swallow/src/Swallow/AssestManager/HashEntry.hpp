#pragma once
#include "swpch.hpp"

namespace Swallow
{
	template <typename T>
	class HashEntry
	{
	public:
		HashEntry(std::string key, T value): key(key), value(value)
		{}

		~HashEntry(){}

		std::string getKey()
		{
			return key;
		}

		T getValue()
		{
			return value;
		}
	private:
		std::string key;
		T value;
};
}

