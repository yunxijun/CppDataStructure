#include <iostream>

using namespace std;

#define SWAP(x,y,t) ((t)=(x),(x)=(y),(y)=(t))

void swap(int x, int y);
void swap_ref(int &, int &); //
void swap_poi(int *x, int *y);

int main()
{
	int a, b,t;
	a = 1;
	b = 10;
	cout << "swap:" << endl;
	cout << "a= " << a << ", " << "b= " << b << endl;
	cout << "a 地址：" << &a << endl << "b 地址：" << &b << endl;
	//不成功 
	swap(a, b);//传递参数的方式影响，把a，b拷贝一个，传进去，传拷贝
	cout << "a= " << a << ", " << "b= " << b << endl;
	cout << "a 地址：" << &a << endl << "b 地址：" << &b << endl;
	cout << "swap_ref:" << endl;
	swap_ref(a, b);//传递参数的方式影响，把a，b拷贝一个，传进去，传拷贝
	cout << "a= " << a << ", " << "b= " << b << endl;
	cout << "a 地址：" << &a << endl << "b 地址：" << &b << endl;
	cout << "swap_pointer:" << endl;
	swap_poi(&a, &b);//传递参数的方式影响，把a，b拷贝一个，传进去，传拷贝
	cout << "a= " << a << ", " << "b= " << b << endl;
	cout << "a 地址：" << &a << endl << "b 地址：" << &b << endl;
	cout << "宏函数:" << endl;
	SWAP(a, b,t);//传递参数的方式影响，把a，b拷贝一个，传进去，传拷贝
	cout << "a= " << a << ", " << "b= " << b << endl;
	cout << "a 地址：" << &a << endl << "b 地址：" << &b << endl;
	cout << "模板函数:" << endl;
	SWAP(a, b, t);//传递参数的方式影响，把a，b拷贝一个，传进去，传拷贝
	cout << "a= " << a << ", " << "b= " << b << endl;
	cout << "a 地址：" << &a << endl << "b 地址：" << &b << endl;
	system("pause");
	return 0;
}

//此方法不能交换
void swap(int x, int y)
{
	int temp;
	temp = x;
	x = y;
	y = temp;
}
//传指针
void swap_poi(int *x, int *y)
{
	int temp;
	temp = *x;
	*x = *y;
	*y = temp;
}
//传引用
void swap_ref(int &x, int &y)
{
	int temp;
	temp = x;
	x = y;
	y = temp;
}