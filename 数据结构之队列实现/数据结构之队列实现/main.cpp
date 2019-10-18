#include <iostream>
#include "Queen.h"
using namespace std;

int main()
{
	cout << "²âÊÔË³Ðò¶ÓÁÐ:"<<endl;
	Queue <int> q(2);
	q.Push(8);
	q.Push(9);
	q.Push(10);
	
	cout << q.Front()<<endl;
	cout << q.Rear()<<endl;
	cin.get();
	return 0;
}