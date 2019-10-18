#include <iostream>

using namespace std;
int SequentialSearch(int *a, const int n, const int x);
int main()
{
	int m[] = { 1,5,4,6,3,2,9,8,7,0 };
	int res;
	int num = 7;
	res = SequentialSearch(m, 10, num);
	if (res < 0)
		cout << "没找到" << endl;
	else
		cout << "在m[" << res << "]里找到" << num << endl;
	cin.get();
	return 0;
}
//针对没有排序的数据
int SequentialSearch(int *a, const int n, const int x)
{
	int i;
	for (i = 0; i < n; i++)
	{
		if (a[i] == x)
			return i;
	}
	if (i == n)
		return -1;
}