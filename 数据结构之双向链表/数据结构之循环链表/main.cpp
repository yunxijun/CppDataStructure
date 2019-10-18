#include <iostream>

using namespace std;

class DblList;//前置声明

class DblListNode
{
	friend class DblList;
public:
	int data;
	DblListNode *llink;
	DblListNode *rlink;
};
class DblList
{
public:
	DblList() 
	{
		first = new DblListNode();
		first->rlink=first->llink = first;
	};
	void Insert(DblListNode *, DblListNode *);//插入到节点右边
	void Delete(DblListNode *);
	DblListNode *first;//指向表头结构
};

//插入
void DblList::Insert(DblListNode *p, DblListNode *x)
{
	//最关键
	p->llink = x;
	p->rlink = x->rlink;
	x->rlink->llink = p;
	x->rlink = p;
}

void DblList::Delete(DblListNode *x)
{
	if (x ==first)
		cerr << "不可以删除表头." << endl;
	else
	{
		x->llink->rlink = x->rlink;
		x->rlink->llink = x->llink;
		delete x;
	}
}

int main()
{
	cout << "hello 双向链表" << endl;
	DblList intList;
	DblListNode *node1, *node2, *node3, *node4,*node5;
	node1 = new DblListNode();
	node2 = new DblListNode();
	node3 = new DblListNode();
	node4 = new DblListNode();
	node5 = new DblListNode();
	node1->data = 10;
	node2->data = 20;
	node3->data = 30;
	node4->data = 40;
	node5->data = 50;

	intList.Insert(node1, intList.first);
	intList.Insert(node2, intList.first);
	intList.Insert(node3, intList.first);
	intList.Insert(node4, intList.first);
	intList.Insert(node5, intList.first);
	intList.Delete(node3);

	cout << intList.first->rlink->data << endl;
	cout << intList.first->rlink->rlink->data << endl;
	cout << intList.first->rlink->rlink->rlink->data << endl;
	cout << intList.first->rlink->rlink->rlink->rlink->data << endl;
	cout << intList.first->rlink->rlink->rlink->rlink->llink->data << endl;
	cout << intList.first->rlink->rlink->rlink->rlink->llink->llink->data << endl;
	cout << intList.first->rlink->rlink->rlink->rlink->llink->llink->llink->data << endl;
	
	system("pause");
	return 0;
}
