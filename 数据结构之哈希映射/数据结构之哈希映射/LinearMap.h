#pragma once
#include <vector>

template<class Key,class Value>//线性映射--没用的东西
class LinearMap
{
public:
	LinearMap(int size = 101) :arr(size){
		currentSize = 0;
	}
	void Put(const Key & k, const Value & v)
	{
		arr[currentSize] = DataEntry(k, v);
		++currentSize;
	}
	Value get(const Key & k)
	{
		//线性查找
		for (size_t i = 0; i < currentSize; i++)
		{
			if (arr[i].key == k)
				return arr[i].value;
		}
		return Value();//    返回默认值	Value值
	}
private:
	struct DataEntry{
		Key key;
		Value value;
	    DataEntry(const Key & k=Key(), const Value & v=Value()):key(k), value(v) {}
	};
	std::vector <DataEntry> arr;
	int currentSize;
};