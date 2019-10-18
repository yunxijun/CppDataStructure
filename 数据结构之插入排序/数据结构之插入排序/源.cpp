#include <iostream>

using namespace std;
//函数模板声明
template <class T>
void InsertSort(T *a, int n);
template <class T>
void InsertSort_2(T *a, int n);
template <class T>
void Insert(const T &e, T *a, int i);
int main()
{
	double x[] = { 1.1,4.3,0.7,0.2,5,8.9,9,6.6,3,0 };
	//InsertSort(x, 10);
	InsertSort_2(x, 10);
	for (int i = 0; i < 10; i++)
	{
		cout << x[i]<<endl;
	}
	for (int i = 0; i < 10; i++)
	{
		cout << x[i] << endl;
	}
	cin.get();
	return 0;
}
//插入排序算法
template <class T>
void InsertSort(T *a, int n)
{
	int in, out;
	for (out = 1; out< n; ++out)
	{
		T temp = a[out];
		in = out;
		while (in > 0 && a[in - 1] >= temp)
		{
			a[in] = a[in - 1];
			--in;//继续比较
		}
		a[in] = temp;
	}
}
template <class T>
void InsertSort_2(T *a, int n)
{
	for (int j = 2; j <= n; j++)
	{
		T temp = a[j];
		Insert(temp, a, j - 1);
		//a[0] = temp;
		//int i = j - 1;
		//while (temp < a[i])
		//{
		//	a[i + 1] = a[i];
		//	i--;
		//}
		//a[i + 1] = temp;
	}
}
template <class T>
void Insert(const T &e, T *a, int i)
{
	a[0] = e;
	while (e < a[i])
	{
		a[i + 1] = a[i];
		i--;
	}
	a[i + 1] = e;
}
