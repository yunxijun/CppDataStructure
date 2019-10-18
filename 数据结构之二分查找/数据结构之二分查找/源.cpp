#include <iostream>

using namespace std;
int BinarySearch(int *a, const int x, const int n);
int main()
{
	int x[] = { 1,2,3,4,5,6,7,8,9,10 };
	int res,num=7;
	res = BinarySearch(x, 7, num);
	if (res < 0)
		cout << "没找到" << endl;
	else
		cout << "在x[" << res << "]找到" << num << endl;
	cin.get();
	return 0;
}
//二分查找算法速度很快，但是要求数据排序
int BinarySearch(int *a, const int x, const int n)
{
	int low, high, mid;
	low = 0, high = n - 1;
	while (low<=high)
	{
		mid = (low + high) / 2;
		if (a[mid]==x)
		{
			return mid;
		}
		else if (a[mid] < x)
		{
			low = mid + 1;
		}
		else if (a[mid] > x)
		{
			high = mid - 1;
		}
	}
	return -1;
}