#pragma once
//
//struct作为数据结构的实现体，它默认的数据访问控制是public的，
//而class作为对象的实现体，它默认的成员变量访问控制是private的
template <class Object>
class Queue
{
public:
	Queue();
	~Queue();

	bool isEmpty()const;
	const Object & getFront() const;//取出队首的数据
	void enqueue(const Object & x);//队尾入队列
	Object dequeue();//出队,从队首删除
	void makeEmpty();//清除队列
private:
	//节点：内部类
	struct ListNode
	{
		Object element;
		ListNode *next;
		ListNode(const Object & theElement, ListNode *n = 0)
			:element(theElement), next(n) {}
	};
	ListNode *front;
	ListNode *back;
};

//构造函数
template<class Object>
inline Queue<Object>::Queue()
{
	front = back = 0;
}

//析构函数、清空数据
template<class Object>
inline Queue<Object>::~Queue()
{
	makeEmpty();
}

//判断队列是否为空
template<class Object>
inline bool Queue<Object>::isEmpty() const
{
	return  front==0;
}

template<class Object>
inline const Object & Queue<Object>::getFront() const
{
	// TODO: 在此处插入 return 语句
	if (isEmpty())
		throw "空队列";
	else
		return front->element;
}

//入队
template<class Object>
inline void Queue<Object>::enqueue(const Object & x)
{
	if (isEmpty())
		back = front = new ListNode(x);
	else
		back = back->next = new ListNode(x);
}

//出队
template<class Object>
inline Object Queue<Object>::dequeue()
{
	Object frontItem = getFront();
	ListNode *old = front;
	front = front->next;
	delete old;
	return frontItem;
}

//makeEmpty()
template<class Object>
inline void Queue<Object>::makeEmpty()
{
	while (!isEmpty())
	{
		//出队列
		dequeue();
	}
}
