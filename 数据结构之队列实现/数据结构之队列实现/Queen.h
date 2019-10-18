#pragma once
//使用模板类
template <class T>
class Queue
{	
public:
	Queue(int QueueCapacity = 10);
	~Queue();
	bool IsEmpty() const;
	T &Front() const;//查看队首的数据
	T &Rear() const;//查看队尾的数据
	void Push(const T &item);//在队尾插入数据
	void Pop();//删除队首数据
private:
	T *queue;
	int front;
	int rear;
	int capacity;
};

template <class T>
Queue<T>::Queue(int QueueCapacity):capacity(QueueCapacity)
{
	if (capacity < 1) throw "Quene capacity must be >0 ";
	queue = new T[capacity];
	front = rear = 0;//开始的时候队首队尾都指向0
}

template<class T>
inline Queue<T>::~Queue()
{
}
template<class T>

//判断是否为空
inline bool Queue<T>::IsEmpty() const
{
	return front==rear;
}
template<class T>

//查看队首+1的数据
inline T & Queue<T>::Front() const
{
	// TODO: 在此处插入 return 语句
	if (IsEmpty()) throw "queue is Empty ";
	//处理回绕
	return queue[(front+1)%capacity];
}
template<class T>
//读队尾数据

inline T & Queue<T>::Rear() const
{
	// TODO: 在此处插入 return 语句
	if (IsEmpty()) throw "queue is Empty ";
	return queue[rear];
}

template<class T>
//插入队列
void Queue<T>::Push(const T &item)
{
	//if (rear == capacity - 1)//如果是最后一个
	//{
	//	rear = 0;
	//}
	//else
	//{
	//	rear++;
	//}
	if ((rear + 1) % capacity == front)//判断队列是否已满
	{
		//加倍是重点，加倍是重点，加倍是重点
		T *newQueue = new T[2 * capacity];
		int start = (front + 1) % capacity;
		if (start < 2)//没有回转
			copy(queue + start, queue + start + capacity - 1, newQueue);
		else
		{
			copy(queue + start, queue + capacity, newQueue);
			copy(queue, queue + rear + 1, newQueue+capacity-start);
		}
		//重新设置队首
		front = 2 * capacity - 1;
		rear = capacity - 2;
		capacity *= 2;
		//删除原来的数组
		delete[] queue;
		//改变指针的指向
		queue = newQueue;
	}
	rear = (rear + 1) % capacity;
	queue[rear] = item;
}

template<class T>
//删除队首的数据
inline void Queue<T>::Pop()
{
	if (IsEmpty()) throw "queue is Empty ";
	front = (front + 1) % capacity;//高级
	queue[front].~T();
}