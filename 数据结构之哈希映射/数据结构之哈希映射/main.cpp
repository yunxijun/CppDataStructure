#include <iostream>
#include <map>  //二叉树映射，不是哈希映射,二叉红黑树
#include <string>
#include "LinearMap.h"
#include "HashMap.h"
#include <hash_map>//C++里面的做好的hash映射，微软做好的
using namespace std;
int main()
{
	map <string, int> m;
	m["bill"] = 98;
	m["Tom"] = 67;
	m["Mary"] = 100;
	//继续保存..1000万个
	//速度为O(log(n))
	cout << m["Tom"];

	LinearMap <string, int> lm;
	lm.Put("Bill", 99);
	lm.Put("Tom", 98);
	//...........放很多数据
	//速度为O(n)
	cout << "LinearMap: " << lm.get("Tom");

	//我的哈希映射
	cout << "我的哈希映射:" << endl;
	HashMap <string, int> myHashMap;
	//cout << myHashMap.hash("Bill") << endl;
	//cout << myHashMap.myhash("Billl") << endl;
	myHashMap.Put("Bill", 999);
	myHashMap.Put("Tom", 888);
	cout<<myHashMap.get("Tom");
	//系统的哈希映射hash_Map
	hash_map<string, int> hash;
	hash["Bill"] = 2;
	hash["Tom"] = 3;
	cout << hash["Bill"] << endl;

	system("pause");
	return 0;
}