#include <iostream>
#include "ThreeLetteList.h"
using namespace std;

//复杂链表
class NodeB;
class NodeA
{
private:
	//数据域
	int data1;
	char data2;
	float data3;
	//节点指针
	NodeA *linka;
	NodeB *linkb;
};
class NodeB
{
private:
	int data;
	NodeB *link;
};

//单链表
class List;//前置声明
class Node
{
	friend class List;//友元类
private:
	int data;//节点里的数据
	Node *link;//指向下一个节点的指针
};
//链表
class List
{
public:
	void test();
	void show();
private:
	Node *first;//指向第一个节点的指针
};
int main()
{
	List a;
	a.test();//创建了3个节点
	a.show();
	ThreeLetterList l;
	l.test();
	l.show();
	system("pause");
	return 0;
}
void List::test()
{
	Node *f = new Node();//创建一个新的节点
	f->data = 44;//可以使用友元类或者嵌套类
	f->link = 0;
	first = f;

	f = new Node();
	f->data = 72;
	f->link = 0;

	first->link = f;

	f = new Node();
	f->data = 210;
	f->link = 0;

	first->link->link = f;
}

void List::show()
{
	cout << first->data << endl
		<< first->link->data << endl
		<< first->link->link->data<<endl;
}
