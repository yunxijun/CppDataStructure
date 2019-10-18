#include <iostream>
#include "MaxHeap.h"
using namespace std;

int main()
{
	MaxHeap <int> h(100);
	h.Push(20);
	h.Push(30);
	h.Push(40);
	h.Push(15);
	cout<<h.Top()<<endl;
	h.Pop();
	cout << h.Top() << endl;
	cout << h.IsEmpty() << endl;
	cout << "Ok" << endl;
	system("pause");
	return 0;
}