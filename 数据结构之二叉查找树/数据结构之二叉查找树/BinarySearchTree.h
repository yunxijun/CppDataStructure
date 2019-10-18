#pragma once
#include <iostream>

enum boolean {FALSE,TRUE};

template <class Type>
class Element
{
public:
	Type Key;
	//添加更多的数据
};

template <class Type> class Bst;
//节点
template <class Type>
class BstNode
{
public:
	friend class Bst <Type>;
//private:
	Element <Type> data;//私有的数据只能在其或者友元类中访问
	BstNode *leftChild;
	BstNode *rightChild;
	void display(int i);
};

template <class Type>
class Bst
{
public:
	Bst(BstNode <Type> *init = 0)
	{
		root = init;
	}
	boolean Insert(const Element <Type> & x);
	BstNode <Type>* Search(const Element <Type> & x);
	BstNode <Type>* Search(BstNode <Type> *,const Element <Type> & x);
	BstNode <Type>* IterSearch(const Element <Type> & );//非递归方式
private:
	BstNode <Type> *root;
};

//显示当前节点数据，和左子树右子树所有的数据
template<class Type>
inline void BstNode<Type>::display(int i)
{
	//递归
	std::cout << "Position: " << i << ", data.key=" << data.Key<<"\n";
	if (leftChild) leftChild->display(2*i);
	if (rightChild) rightChild->display(2 * i + 1);
}

//插入
template<class Type>
inline boolean Bst<Type>::Insert(const Element<Type>& x)
{
	BstNode <Type> *p = root;
	BstNode <Type> *q = 0;//q指向当前节点的父节点
	//插入之前要查找
	while (p)
	{
		//保存p;
		q = p;
		//重复，失败
		if (x.Key == p->data.Key) 
			return FALSE;
		else if (x.Key < p->data.Key)
			p = p->leftChild;
		else
			p = p->rightChild;
	}
	//找到的位置就是q;
	p = new BstNode <Type>;
	p->leftChild =p->rightChild= 0;
	p->data = x;
	if (!root) root = p;
	else if (x.Key < q->data.Key) q->leftChild = p;
	else if (x.Key > q->data.Key) q->rightChild = p;
	return TRUE;
}

template<class Type>
inline BstNode<Type>* Bst<Type>::Search(const Element<Type>& x)
{
	return Search(root, x);
}

//开始递归查找
template<class Type>
inline BstNode<Type>* Bst<Type>::Search(BstNode<Type>* b, const Element<Type>& x)
{
	if (!b) return 0;
	if (x.Key == b->data.Key) return b;
	if (x.Key < b->data.Key) 
		return Search(b->leftChild,x);
	else
		return Search(b->rightChild, x);
}

//迭代查找方法
template<class Type>
inline BstNode<Type>* Bst<Type>::IterSearch(const Element<Type> & x)
{
	for (BstNode<Type> *t = root; t;)
	{
		if (x.Key == t->data.Key) 
			return t;
		if (x.Key < t->data.Key)
			t = t->leftChild;
		else
			t = t->rightChild;	
	}
	return 0;
}
