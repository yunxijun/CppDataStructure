#include <iostream>
#include "MaxHeap.h"

using namespace std;

int main()
{
	MaxHeap <int> h(100);
	int arr[] = { 62,12,45,81,15,5,48,47,24,24,15,48,45 };
	for (int i = 0; i < 13; i++)
	{
		h.Push(arr[i]);
	}
	for (int i = 0; i < 13; i++)
	{
		arr[i]=h.Top();
		h.Pop();
	}
	for (int i = 0; i < 13; i++)
	{
		cout << arr[i] << " ";
	}
	cout << "Ok" << endl;
	system("pause");
	return 0;
}