#include <iostream>

using namespace std;
int BinarySearch_I(int *a, const int x, const int left,const int right);
int main()
{
	int m[] = { 1,2,3,4,5,6,7,8,9,10 };
	int res;
	int num = 7;
	if ((res = BinarySearch_I(m, num, 0, 9)) < 0)
	{ 
		cout << "û�ҵ�" << endl;
	}
	else
	{
		cout << "��m[" << res << "]���ҵ�" << num << endl;
	}
	cin.get();
	return 0;
}
//�ݹ��۰����
int BinarySearch_I(int *a, const int x, const int left, const int right)
{
	if (left <= right)
	{
		int middle = (left + right) / 2;
		if (x < a[middle]) return BinarySearch_I(a, x, left, middle - 1);//�ݹ�
		else if(x>a[middle]) return BinarySearch_I(a, x, middle+1,right);
		else return middle;
	}
	return -1;
}