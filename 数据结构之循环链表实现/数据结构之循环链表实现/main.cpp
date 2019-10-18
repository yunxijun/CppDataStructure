#include <iostream>
#include <list> //STL中的链表
#include"List.h"
int main()
{
	List <int> intList;
	std::cout << "我的链表和迭代器:" << std::endl;
	//前面插入
	intList.Insert(5);
	intList.Insert(15);
	intList.Insert(25);
	intList.Insert(35);
	//intList.show();
	ListIterator <int> li(intList);
	if (li.NotNull())
	{
		std::cout << *li.first();
		while (li.NextNotNull())
			std::cout << "->" << *li.next();
		std::cout << std::endl;
	}
	std::cout << "测试一下循环";
	ListIterator <int> Iter(intList);
	std::cout << *Iter.first() << std::endl;
	std::cout << *Iter.next() << std::endl;
	std::cout << *Iter.next() << std::endl;
	std::cout << *Iter.next() << std::endl;
	std::cout << *Iter.next() << std::endl;
	std::cout << *Iter.next() << std::endl;
	std::cout << *Iter.next() << std::endl;
	std::cout << *Iter.next() << std::endl;
	std::cout << *Iter.next() << std::endl;
	std::cout << *Iter.next() << std::endl;
	std::cout << *Iter.next() << std::endl;
	std::cout << *Iter.next() << std::endl;
	std::cout << *Iter.next() << std::endl;
	std::cout << *Iter.next() << std::endl;
	std::cout << *Iter.next() << std::endl;
	system("Pause");
	return 0;
}