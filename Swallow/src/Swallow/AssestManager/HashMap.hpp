#pragma once

#include "swpch.hpp"
#include "HashEntry.hpp"

template <typename T>
class HashEntry;

namespace SwallowEngine
{
	template <typename T>
	class HashMap
	{
	public:
		HashMap() {
			table = new HashEntry<T> * [TABLE_SIZE];
			for (int i = 0; i < TABLE_SIZE; i++)
				table[i] = NULL;
		}

		// HACK: Hacky
		void put(std::string key, T value)
		{
			for (int i = 0; i < TABLE_SIZE; i++)
			{
				if (table[i] == NULL)
				{
					table[i] = new HashEntry(key, value);
				}
			}
		}

		// HACK: Hacky
		T	get(std::string key)
		{
			for (int i = 0; i < TABLE_SIZE; i++)
			{
				if (table[i]->getKey() == key)
				{
					return table[i]->getValue();
				}
			}
			return nullptr;
		}

		~HashMap()
		{
			for (int i = 0; i < TABLE_SIZE; i++)
			{
				if (table[i] != NULL)
					delete table[i];
			}
			delete[] table;
		}
	private:
		const int TABLE_SIZE = 256;
		HashEntry<T>** table;
	};
}