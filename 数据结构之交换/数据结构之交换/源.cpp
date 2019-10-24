#include <iostream>

using namespace std;

int main()
{
	//交换的是值，不是地址
	int a, b, temp;
	a = 1;
	b = 10;
	cout << "a= "<< a << ", "<<"b= " << b << endl;
	cout << "a 地址：" << &a << endl << "b 地址：" << &b<<endl;
	temp = a;
	a = b;
	b = temp;
	cout << "a= " << a << ", " << "b= " << b << endl;
	cout << "a 地址：" << &a << endl << "b 地址：" << &b<<endl;
	return 0;
} 