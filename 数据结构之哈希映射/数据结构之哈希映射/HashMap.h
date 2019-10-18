#pragma once
#define _SILENCE_STDEXT_HASH_DEPRECATION_WARNINGS 1
#include <vector>

template<class Key, class Value>//哈希映射--很有用的东西
class HashMap
{ 
public:
	HashMap(int size = 101) :arr(size) {
		currentSize = 0;
	}
	void Put(const Key & k, const Value & v)
	{
		int pos = myhash(k);
		arr[pos] = DataEntry(k, v);
		++currentSize;
	}
	Value get(const Key & k)
	{
		int pos = myhash(k);
		if (arr[pos].key == k)
			return arr[pos].value;
		else
			return Value();//返回默认值
	}
	unsigned hash(const Key & k) const
	{
		unsigned int hashVal = 0;
		const char *keyp = reinterpret_cast<const char *>(&k);
		for (size_t i = 0; i < sizeof(Key); i++)
		{
			hashVal = 37 * hashVal+keyp[i];
		}
		return hashVal;
	}
	int myhash(const Key & k) const
	{
		unsigned hashVal = hash(k);
		hashVal %= arr.size();
		return hashVal;
	}
private:
	struct DataEntry {
		Key key;
		Value value;
		DataEntry(const Key & k = Key(), const Value & v = Value()) :key(k), value(v) {}
	};
	std::vector <DataEntry> arr;
	int currentSize;
};