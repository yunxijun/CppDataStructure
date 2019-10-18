#include <iostream>
#include <list>
using namespace std;

//自定义数据类型
class Vertex
{
public:
	char label;
	Vertex(char lab) { label = lab; }
};
//重载
//Vertex v;
//cout << v;
ostream & operator <<(ostream &out, const Vertex &v)
{
	cout << v.label;
	return out;
}

template <class T>
class Graph
{
public:
	Graph(const int vertex) :n(vertex)
	{
		//VertexList = new T[n];
		VertexList = new T *[n];//第一个数组：用指针指向5个顶点,这里可以避免重新实现[]操作符
		HeadNodes = new list<int>[n];//第二个数组，保存5个链表
		nVerts = 0;
	}
	~Graph()
	{
		delete[] VertexList;
		delete[] HeadNodes;
	}
	//void addVertex(T & v);
	void addVertex(T * v);
	void addEdge(int start, int end);
	void printVertex();
	void printAdjList();
private:
	//T *VertexList;
	T **VertexList;
	list <int> *HeadNodes;
	int n;//最多n个点
	int nVerts;//实际顶点数
};

template<class T>
void Graph<T>::addVertex(T * v)
{
	VertexList[nVerts++] = v;
}
template<class T>
void Graph<T>::addEdge(int start, int end)
{
	HeadNodes[start].push_back(end);
}

template<class T>
void Graph<T>::printVertex()
{
	for (int i = 0; i <nVerts; i++)
	{
		cout << *VertexList[i]<<" ";
		//cout << VertexList[i] << " ";
		cout << endl;
	}
}
template<class T>
void Graph<T>::printAdjList()
{
	for (int i = 0; i < nVerts; i++)
	{
		cout << i << "->";
		for (list<int >::iterator iter=HeadNodes[i].begin();iter!=HeadNodes[i].end();iter++)
		{
			cout << *iter << "->";	
		}
		cout << "end" << endl;
	}
}
int main()
{
	//Graph <char> g(5);
	//char a = 'A';
	//char b = 'B';
	//char c = 'C';
	//char d = 'D';
	//char e = 'E';
	Graph <Vertex> g(5);
	Vertex a('A');
	Vertex b('B');
	Vertex c('C');
	Vertex d('D');
	Vertex e('E');
	g.addVertex(&a);
	g.addVertex(&b);
	g.addVertex(&c);
	g.addVertex(&d);
	g.addVertex(&e);
	//g.addVertex(a);
	//g.addVertex(b);
	//g.addVertex(c);
	//g.addVertex(d);
	//g.addVertex(e);
	g.printVertex();

	g.addEdge(0, 1);
	g.addEdge(0, 3);
	g.addEdge(1, 0);
	g.addEdge(1, 4);
	g.addEdge(2, 4);
	g.addEdge(3, 0);
	g.addEdge(3, 4);
	g.addEdge(4, 1);
	g.addEdge(4, 2);
	g.addEdge(4, 3);
	g.printAdjList();

	system("pause");
	return 0;
}
