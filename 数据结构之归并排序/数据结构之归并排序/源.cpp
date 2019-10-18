//未完待续。。。。。。。。。。。。。。。。
#include <iostream>
#include<algorithm>
using namespace std;

template <class T>
void Merge(T *initList, T *mergedList, const int l, const int m, const int n);
template <class T>
void Merge(T *initList, T *mergedList, const int l, const int m, const int n)
{
	int i1, i2, iresult;
	for (i1 = 1, i2 = m + 1,iresult=1; i1 <= m&&i2 <= n; iresult++)
	{
		if (initList[i1] <= initList[i2])
		{
			mergedList[iresult] = initList[i1];
			i1++;
		}
		else
		{
			mergedList[iresult] = initList[i2];
			i2++;
		}
	}
	//copy(start,end,to_vector.begin())
	copy(initList + i1, initList + m+1, mergedList + iresult);
	copy(initList + i2, initList + n+1, mergedList + iresult);
}
template<class T>
void MergePass(T *initList, T *resultList, const int n, const int s)
{
	int i;
	for ( i = 1; i < =n-2*s+1; i+=2*s)
	{
		Merge(initList, resultList, i, i + s - 1, i + 2 * s - 1);
	}
	if ((i + s - 1) < n)
		Merge(initList, resultList, i, i + s - 1, n);
	else
		copy(initList + i, initList + n + 1, resultList+i);
}
int main()
{
	//a[0]不用
	int a[] = { 0,26,47,81,95,7,14,39,55,62,74 };//分成两个数组
	int b[11] = { 0 };
	Merge(a, b, 1, 4,10);
	for (int i = 1; i < 11; ++i)
	{
		cout << b[i] << " ";
	}
	int m[] = { 0,26,5,77,1,61,11,59,15,48,19 };
	int n[11] = { 0 };
	MergePass(m, n, 10, 1);
	for (int i = 0; i < 11; i++)
	{
		cout << n[i];
	}
	cout << endl;
	cin.get();
	return 0;
}