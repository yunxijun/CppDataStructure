//#pragma once
#include "MyUtil.h"
#ifndef _MYSTACK_H
#define _MYSTACK_H
//类模板
template <class T>
class MyStack
{
public:
	MyStack(int stackCapacity = 10);
	~MyStack();
	inline bool IsEmpty() const;
	T &Top()const;
	void Push(const T &item);
	inline void Pop();

private:
	T *stack;
	int top;//记录栈顶的位置
	int capacity;
};
//实现
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
//内联函数
inline bool MyStack<T>::IsEmpty() const
{
	return top == -1;
}

template<class T>
inline T & MyStack<T>::Top() const
{
	// TODO: 在此处插入 return 语句
	if (IsEmpty()) throw "stack is empty";
	return stack[top];
}

template<class T>
void MyStack<T>::Push(const T & item)
{
	if (top == capacity - 1)
	{
		ChangeSizeID(stack, capacity, 2 * capacity);
		capacity = 2 * capacity;
	}
	stack[++top] = item;
}
template<class T>
//删除栈顶
void MyStack<T>::Pop()
{
	if (IsEmpty()) throw "stack is empty. Cannot delete";
	//如果是对象，删除之后要析构
	//stack[top--].~MyStack();
	stack[top--].~T();//这也行。。
}
#endif // !_MYSTACK_H
