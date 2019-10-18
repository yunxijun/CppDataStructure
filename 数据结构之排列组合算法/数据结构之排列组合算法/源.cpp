#include<iostream>

using namespace std;

void Pemutations(char *p, const int k, const int m);
void Pemutations(char *p, const int k, const int m)
{
	////a开头，后面跟着bc所有排列
	//swap(p[0], p[0]);
	//Pemutations(p, 1, 2);
	//swap(p[0], p[0]);
	////b开头，后面跟着ac所有排列
	//swap(p[0], p[1]);
	//Pemutations(p, 1, 2);
	//swap(p[0], p[1]);
	////c开头，后面跟着ab所有排列
	//swap(p[0], p[2]);
	//Pemutations(p, 1, 2);
	//swap(p[0], p[2]);
	if (k == m)
	{
		for (int i = 0; i <=m; i++)
		{
			cout << p[i];	
		}
		cout << endl;
	}
	else
	{
		for (int i = k; i <=m; i++)
		{
			swap(p[k], p[i]);
			Pemutations(p, k + 1, m);
			swap(p[k], p[i]);
		}
	}
}
int main()
{
	char s[] = "abc";
	Pemutations(s, 0, 2);
	system("pause");
	return 0;
}
