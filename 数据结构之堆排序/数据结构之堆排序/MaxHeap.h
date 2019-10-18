#pragma once

template <class T>
class MaxHeap
{
public:
	MaxHeap(int max = 10);
	virtual ~MaxHeap();
	bool IsEmpty();
	void Push(const T &);
	void Pop();
	const T & Top() const;
	void trickleUp(int index);
	void trickleDown(int index);

private:
	T *heapArray;
	int maxSize;
	int currentSize;//当前的大小


};

template<class T>
inline MaxHeap<T>::MaxHeap(int max)
{
	if (max < 1) throw "max size must be >=1 ";
	maxSize = max;
	currentSize = 0;
	heapArray = new T[maxSize];
}

template<class T>
inline MaxHeap<T>::~MaxHeap()
{
	delete[] heapArray;
}

template<class T>
inline bool MaxHeap<T>::IsEmpty()
{
	return currentSize == 0;
}

template<class T>
inline void MaxHeap<T>::Push(const T & e)
{
	if (currentSize == maxSize) throw "堆已经满了。。";
	//从0开始
	heapArray[currentSize] = e;
	//向上渗透
	trickleUp(currentSize++);
}

//删除堆顶：向下渗透
template<class T>
inline void MaxHeap<T>::Pop()
{
	heapArray[0] = heapArray[--currentSize];
	trickleDown(0);
}

template<class T>
inline void MaxHeap<T>::trickleDown(int index)
{
	int largerChild;
	//保存临时的根
	T top = heapArray[index];
	while (index < currentSize / 2)
	{
		int leftChild = 2 * index + 1;
		int rightChild = leftChild + 1;
		if (rightChild < currentSize && heapArray[leftChild] < heapArray[rightChild])
			largerChild = rightChild;
		else
			largerChild = leftChild;
		if (top >= heapArray[largerChild])
			break;
		heapArray[index] = heapArray[largerChild];
		index = largerChild;
	}
	heapArray[index] = top;
}

//查看根节点
template<class T>
inline const T & MaxHeap<T>::Top() const
{
	// TODO: 在此处插入 return 语句
	return heapArray[0];
}

template<class T>
inline void MaxHeap<T>::trickleUp(int index)
{
	int parent = (index - 1) / 2;
	T bottom = heapArray[index];
	while (index>0 && heapArray[parent]<bottom)
	{
		heapArray[index] = heapArray[parent];
		index = parent;
		parent = (parent - 1) / 2;
	}
	heapArray[index] = bottom;
}

