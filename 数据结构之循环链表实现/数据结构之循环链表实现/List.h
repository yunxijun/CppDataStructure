#pragma once
//循环链表-------------------------------------------------------
//循环链表-------------------------------------------------------
//循环链表-------------------------------------------------------
#include <iostream>
template <class Type> class List;//前置声明
template <class Type> class ListIterator;//一定要有前置声明
										 //类模板造出模板类
template <class Type>
//ListNode 类模板的名字
class ListNode
{
	friend class List<Type>;//后面要加<Type>
	friend class ListIterator <Type>;
private:
	Type data;//节点的数据
	ListNode *link;//指向下一个链表节点
	ListNode(Type);
	ListNode() {};//无参数的构造函数
};

template <class Type>
class List
{
	friend class ListIterator <Type>;
public:
	List() { first = new ListNode<Type>; first->link = first; }//表头
	void Insert(Type);
	void Delete(Type);
private:
	ListNode <Type> *first;
};

//迭代器
template <class Type>
class ListIterator
{
public:
	ListIterator(const List <Type> & l) :list(l), current(l.first->link) {};
	bool NotNull();//表明当前节点是不是空的
	bool NextNotNull();//表明当前节点的下一个节点是不是空的
	Type *first();//返回当前节点指针
	Type *next();//返回下一节点的指针
private:
	const List<Type> &list;//保存传入的链表
	ListNode <Type> *current;//指向当前的节点
};

template<class Type>
inline bool ListIterator<Type>::NotNull()
{
	if (current!=list.first)
		return true;
	else
		return false;
}

template <class Type>
inline bool ListIterator <Type>::NextNotNull()
{
	//用到别的类里面的成员
	if ((current->link)!= list.first)
		return true;
	else
		return false;
}

//返回当前节点指针
template <class Type>
inline Type *ListIterator<Type>::first()
{
	if (current!=list.first)
		return &current->data;
	else
		return 0;
}

//返回当前节点的下一个节点指针
template<class Type>
inline Type * ListIterator<Type>::next()
{
	current = current->link;
	if (current == list.first)
	{
		current = current->link;
		return &current->data;
	}
}

//插入
template <class Type>
void List <Type>::Insert(Type k)
{
	ListNode <Type> *newnode = new ListNode<Type>(k);//创建新的节点
	//在表头后面加节点
	newnode->link = first->link;
	first->link = newnode;
}

//删除
template<class Type>
inline void List<Type>::Delete(Type k)
{
	ListNode <Type> *Previous = first;//前一个指针
	ListNode <Type> *current;
	for (current = first->link; (current!=first)&&current&&current->data != k;
		Previous = current, current = current->link)
	{
		;//空循环：找到要被删除的节点
	}
	if (current!=first)
	{
		//if (Previous) Previous->link = current->link;
		//else first = first->link;
		Previous->link = current->link;
		delete current;//删除这个节点指针
	}
	else
	{
		std::cout << "链表中没有这个数据,谢谢";
	}
}
template <class Type>
ListNode <Type>::ListNode(Type element)
{
	data = element;
	link = 0;
}
