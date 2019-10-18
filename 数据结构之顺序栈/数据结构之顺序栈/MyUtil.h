//#pragma once
#include <algorithm>
#ifndef _MYUTIL_H
#define _MYUTIL_H
template <class T>
void ChangeSizeID(T *&a, const int oldSize, const int newSize);

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
#endif // !_MYUTIL_H
