#include<iostream>



// 从左向右扫描数据，选择最大的数据，放在右边。
// 要点：比较相邻的两个数，如果左边大于右边
// 排序也是换值
using namespace std;
//函数声明
void BubbleSort(int list[], int n);
int main()
{
	int a[] = { 2,5,  4,2,9,1,0,4,8,10 };
	cout << "a[]" << a;
	cout << "排序之前" << endl;
	for (int m = 0; m < 10; m++)
	{
		cout<< a[m] <<endl;
	}
	BubbleSort(a, 10);
	cout << "排序之后" << endl;
	for (int k = 0; k < 10; k++)
	{
		cout << a[k] <<endl;
	}
	cin.get();
	return 0;
}
void BubbleSort(int list[], int n)
{
	//冒泡排序核心算法 10个数据扫描9次
	for (int i = 0; i < n - 1; i++)
	{
		//交换次数
		for (int j = 0; j < n-i-1 ; j++)
		{
			if (list[j] < list[j + 1])
			{
				swap(list[j], list[j + 1]);
			}
		}
	}
}