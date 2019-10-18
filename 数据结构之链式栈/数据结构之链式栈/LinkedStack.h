#pragma once
template <class T> class LinkedStack;//前置声明

template <class T>
class ChainNode 
{
	friend class LinkedStack <T>;
private:
	ChainNode(const T & theData, ChainNode *n = 0) 
		:data(theData), link(n) {}
	T data;
	ChainNode <T> *link;//指向下一个节点

};

template <class T>
class LinkedStack
{
public:
	LinkedStack() :topp(0) {}
	~LinkedStack() { makeEmpty(); }
	bool IsEmpty()const;
	T &top() const;//查看栈顶top和上面的变量重复了
	void Pop();//出栈
	void Push(const T &e);
	void makeEmpty();
private:
	ChainNode <T> *topp;

};

template<class T>
inline bool LinkedStack<T>::IsEmpty() const
{	
	return topp==0;
}

template<class T>
inline T & LinkedStack<T>::top() const
{
	// TODO: 在此处插入 return 语句
	if (this->IsEmpty())
		throw "堆栈是空的";
	else
		return topp->data;
}

template<class T>
inline void LinkedStack<T>::Pop()
{
	if (this->IsEmpty())
		throw "堆栈是空的，不能删除";
	ChainNode <T> *delNode = topp;
	topp = topp->link;
	delete delNode;//一定要有这个！
}

template<class T>
inline void LinkedStack<T>::makeEmpty()
{
	while (!IsEmpty())
		Pop();
}

template<class T>
inline void LinkedStack<T>::Push(const T & e)
{
	//模板类
	topp = new ChainNode <T> (e, topp);
}
