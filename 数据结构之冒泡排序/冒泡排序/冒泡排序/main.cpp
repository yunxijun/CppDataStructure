#include<iostream>

using namespace std;
void BubbleSort(int list[], int n);
int main()
{
	int a[] = { 2,5,4,2,9,1,0,4,8,10 };
	cout << "ÅÅÐòÖ®Ç°" << endl;
	for (int m = 0; m < 10; m++)
	{
		cout<< a[m] <<endl;
	}
	BubbleSort(a, 10);
	cout << "ÅÅÐòÖ®ºó" << endl;
	for (int k = 0; k < 10; k++)
	{
		cout << a[k] <<endl;
	}
	cin.get();
	return 0;
}
void BubbleSort(int list[], int n)
{
	//Ã°ÅÝÅÅÐòºËÐÄËã·¨
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < n-i-1; j++)
		{
			if (list[j] > list[j + 1])
			{
				swap(list[j], list[j + 1]);
			}
		}
	}
}