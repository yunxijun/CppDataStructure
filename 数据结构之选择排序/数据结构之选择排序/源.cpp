#include <iostream>

using namespace std;
void 梦(int *list, const int n);

int main()
{
	int x[] = { 1, 2, 5, 1, 4, 5, 7, 8, 9, 0 };
	cout << "排序之前" << endl;
	for (int i = 0; i < 10; i++)
	{
		cout << x[i] << endl;
	}
	梦(x, 10);
	cout << "排序之后" << endl;
	for (int i = 0; i < 10; i++)
	{
		cout << x[i] << endl;
	}
	cin.get();
	return 0;
}
void 梦(int *list, const int n)
{
	//改进 i<n-1
	for (int i = 0; i < n-1; i++)//找出最小
	{
		int min = i;//先假设第一个是最小的,min是下标，标记最小
		for (int j = i+1; j < n; j++)
		{
			if (list[j] < list[min])
				min = j;
		}
		swap(list[i], list[min]);//交换
	}
}