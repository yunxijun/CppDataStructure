#include "MyStack.h"
#include "MyUtil.h"

template <class T>
MyStack <T>::MyStack(int stackCapacity) :capacity(stackCapacity)
{
	if (capacity < 1) throw "stack capacity must be >0";
	stack = new T[capacity];
	top = -1;
}

template<class T>
MyStack<T>::~MyStack()
{
	delete[] stack;
}

template<class T>
bool MyStack<T>::IsEmpty() const
{
	return false;
}

template<class T>
T & MyStack<T>::Top() const
{
	// TODO: 在此处插入 return 语句
}

template<class T>
void MyStack<T>::Push(const T & item)
{
}

template<class T>
void MyStack<T>::Pop()
{
}
