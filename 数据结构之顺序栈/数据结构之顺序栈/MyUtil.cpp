#include"MyUtil.h"
#include <iostream>
template <class T>
void ChangeSizeID(T *&a, const int oldSize, const int newSize)
{
	if (newSize < 0) throw "New length must be >=0";
	T *temp = new T[newSize];
	int number = min(oldSize, newSize);
	std::copy(a, a + number, temp);
	delete[] a;
	a = temp;
}