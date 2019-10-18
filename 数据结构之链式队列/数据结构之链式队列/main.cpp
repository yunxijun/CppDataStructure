#include <iostream>
#include"QueueList.h"
using namespace std;
int main()
{
	cout << "test" << endl;
	Queue <int> myQ;
	myQ.enqueue(10);
	myQ.enqueue(20);
	myQ.enqueue(30);
	cout<<myQ.dequeue()<<endl;
	cout<<myQ.getFront()<<endl;

	system("pause");
	return 0;
}