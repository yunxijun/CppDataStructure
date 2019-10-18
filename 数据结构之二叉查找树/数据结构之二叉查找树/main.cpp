#include <iostream>
#include"BinarySearchTree.h"

using namespace std;

int main()
{
	Bst<int> m;
	Element <int> a, b, c, d, e, f, g, h, i, j;
	a.Key = 5;
	b.Key = 3;
	c.Key = 11;
	d.Key = 3;
	e.Key = 15;
	f.Key = 2;
	g.Key = 8;
	h.Key = 22;
	i.Key = 20;
	j.Key = 9;

	cout << endl;
	cout << m.Insert(a) << endl;//a=5,¾ÍÊÇroot;
	cout << m.Insert(b) << endl;
	cout << m.Insert(c) << endl;
	cout << m.Insert(d) << endl;
	cout << m.Insert(e) << endl;
	cout << m.Insert(f) << endl;
	cout << m.Insert(g) << endl;
	cout << m.Insert(h) << endl;
	cout << m.Insert(i) << endl;
	cout << m.Insert(j) << endl;

	BstNode <int> *p = m.Search(f);
	cout << p->data.Key;

	BstNode <int> *p2 = m.IterSearch(f);
	cout << p2->data.Key;

	cout << "hello,²âÊÔ" << endl;
	system("pause");
	return 0;
}