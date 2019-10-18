#pragma once
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
};

template <class Type>
class List
{
	friend class ListIterator <Type>;
public:
	List() { first = 0; };
	void Insert(Type);
	void Delete(Type);
	void Invert();//反转
	void Concatenate(List<Type>);//合并
	void show();
private:
	ListNode <Type> *first;
};
template <class Type>
class ListIterator
{
public:
	ListIterator(const List <Type> & l) :list(l), current(l.first) {};
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
	if (current) 
		return true;
	else
		return false;
}

template <class Type>
inline bool ListIterator <Type>::NextNotNull()
{
	if (current &&current->link) 
		return true;
	else
		return false;
}

//返回指针
template <class Type>
inline Type *ListIterator<Type>::first()
{
	if (list.first)
		return &list.first->data;
	else
		return 0;
}

template<class Type>
inline Type * ListIterator<Type>::next()
{
	if (current)
	{
		current = current->link;
		return &current->data;
	}
	else
	return NULL;
}

template <class Type>
void List <Type>::Insert(Type k)
{
	ListNode <Type> *newnode = new ListNode<Type>(k);
	newnode->link = first;
	first = newnode;
}

template<class Type>
inline void List<Type>::Delete(Type k)
{
	ListNode <Type> *Previous = 0;//前一个指针
	ListNode <Type> *current;
	for(current=first;current&&current->data!=k;
		Previous=current, current = current->link)
	{
		//空循环：找到要被删除的节点
	}
	if (current)
	{
		if (Previous) Previous->link = current->link;
		else first = first->link;
		delete current;//删除这个节点指针
	}
	else
	{
		std::cout << "链表中没有这个数据,谢谢";
	}
}

//反转
template<class Type>
inline void List<Type>::Invert()
{
	ListNode <Type> *p = first, *q = 0;
	while (p)
	{
		ListNode<Type> *r = q;
		q = p;
		p = p->link;
		q->link = r;
	}
	first = q;
}

//合并
template<class Type>
inline void List<Type>::Concatenate(List<Type> b)
{
	if (!first) { first = b.first; return; }
	if (b.first)
	{
		ListNode <Type> *p;
		for (p = first; p->link; p = p->link)
		{
			//找到最后一个节点
		}
		p->link = b.first;
	}
}

template<class Type>
inline void List<Type>::show()
{
	for (ListNode<Type> *current = first; current; current = current->link)
	{
		std::cout << current->data;
		if (current->link) std::cout << "->";
	}
	std::cout << std::endl;
}

template <class Type>
ListNode <Type>::ListNode(Type element)
{
	data = element;
	link = 0;
}