#include <iostream>
#include "LinkedStack.h"
using namespace std;

int main()
{
	cout << "²âÊÔ:"<<endl;
	LinkedStack <int> s;
	s.Push(10);
	s.Push(20);
	s.Push(30);
	s.Push(40);
	cout<<s.top()<<endl;
	s.Pop();
	cout << s.top() << endl;
	
	system("pause");
	return 0;
}