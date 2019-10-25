#include <iostream>

using namespace std;
int BinarySearch_R(int *a, const int x, const int left,const int right);
int main()
{
	int m[] = { 1,2,3,4,5,6,7,8,9,10 };
	int res;
	int num = 7;
	if ((res = BinarySearch_R(m, num, 0, 9)) < 0)
	{ 
		cout << "没找到" << endl;
	}
	else
	{
		cout << "在m[" << res << "]中找到" << num << endl;
	}
	cin.get();
	return 0;
}
//递归折半查找，每次都是折半查找
int BinarySearch_R(int *a, const int x, const int left, const int right)
{
	if (left <= right)
	{
		int middle = (left + right) / 2;
		if (x < a[middle]) return BinarySearch_R(a, x, left, middle - 1);//递归
		else if(x>a[middle]) return BinarySearch_R(a, x, middle+1,right);
		else return middle;
	}
	return -1;
}