#pragma once
#include <iostream>
#include <queue>

template <class T> class BinaryTree;

//子节点
template <class T> 
class TreeNode
{
public:
	TreeNode()
	{
		leftChild = nullptr;
		rightChild = nullptr;
	}
	T data;
	TreeNode <T> *leftChild;
	TreeNode <T> *rightChild;
};

//树
template <class T> 
class BinaryTree
{
public:
	TreeNode <T> *root;//指向根节点

	void InOrder();//中序遍历
	void InOrder(TreeNode <T> *currentNode);
	void PreOrder(TreeNode <T> *currentNode);//前序遍历
	void PreOrder();
	void PostOrder();//后序遍历
	void PostOrder(TreeNode <T> *currentNode);
	void levelOrder();//层序遍历
	void Visit(TreeNode <T> *currentNode);
	
};

//中序遍历：左子树-节点-右子树，对每一个节点
template <class T>
inline void BinaryTree<T>::InOrder()
{
	InOrder(root);
}

//中序遍历的核心:递归
template<class T>
inline void BinaryTree<T>::InOrder(TreeNode<T>* currentNode)
{
	if (currentNode)
	{
		InOrder(currentNode->leftChild);
		//显示当前节点
		Visit(currentNode);
		InOrder(currentNode->rightChild);
	}
}



//Visit()实现
template<class T>
inline void BinaryTree<T>::Visit(TreeNode<T>* currentNode)
{
	std::cout << currentNode->data<<" ";
}


//前序遍历：节点-左子树-右子树，对每一个节点
template<class T>
inline void BinaryTree<T>::PreOrder()
{
	PreOrder(root);
}

//前序遍历的核心:递归
template<class T>
inline void BinaryTree<T>::PreOrder(TreeNode<T>* currentNode)
{
	if (currentNode)
	{
		//显示当前节点
		Visit(currentNode);
		PreOrder(currentNode->leftChild);
		PreOrder(currentNode->rightChild);
	}
}

//后序遍历：左子树-右子树-节点，对每一个节点
template<class T>
inline void BinaryTree<T>::PostOrder()
{
	PostOrder(root);
}

//后序遍历的核心:递归
template<class T>
inline void BinaryTree<T>::PostOrder(TreeNode<T>* currentNode)
{
	if (currentNode)
	{
		//显示当前节点
		PreOrder(currentNode->leftChild);
		PreOrder(currentNode->rightChild);
		Visit(currentNode);
	}
}

//层序遍历 :用队列
template<class T>
inline void BinaryTree<T>::levelOrder()
{
	std::queue <TreeNode <T> * > q;
	TreeNode <T> *currentNode = root;
	while (currentNode)
	{
		Visit(currentNode);
		if (currentNode->leftChild)
			q.push(currentNode->leftChild);
		if (currentNode->rightChild)
			q.push(currentNode->rightChild);
		if (q.empty()) return;
		currentNode = q.front();
		q.pop();
	}
}

