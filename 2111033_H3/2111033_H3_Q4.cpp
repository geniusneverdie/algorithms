// 2111033_H3_Q4.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include<iostream>
using namespace std;

//有向边类
class line {
public:
    int adjvex;//边连接的结点
    line* nextline;//下一条边
};

//结点类
class node {
public:
    //int data;//结点数据
    line* firstline;//结点指向的第一条边
};

//图
class graph {
public:
    int vexnum, arcnum;
    int* in_index;
    int* out_index;
    node* nodes;

    graph(int vex, int arc);
    ~graph();
    void in_line(int x, int y);//输入有向边x->y
    void top();//拓扑排序
    void remove(int x);//去掉x结点的所有(出）边
};

graph::graph(int vex, int arc) {
    vexnum = vex;
    arcnum = arc;
    nodes = new node[vex];
    in_index = new int[vex];
    out_index = new int[vex];
    for (int i = 0; i < vex; i++) {
        nodes[i].firstline = nullptr;
    }

    for (int i = 0; i < vex; i++) {
        in_index[i] = 0;
        out_index[i] = 0;
    }
}

graph::~graph() {
    delete[] nodes;
    //在释放内存后将指针设置为nullptr。确保在后续代码中无法使用已经释放的指针。
    nodes = nullptr;
    delete[] in_index;
    in_index = nullptr;
    delete[] out_index;
    out_index = nullptr;
}

void graph::in_line(int x, int y) {
    if (nodes[x].firstline == nullptr) {
        line* line1 = new line;
        line1->adjvex = y;
        line1->nextline = nullptr;
        nodes[x].firstline = line1;
    }

    else if (nodes[x].firstline != nullptr) {
        line* line2 = nodes[x].firstline;
        while (line2->nextline) {
            line2 = line2->nextline;
        }
        line* line1 = new line;
        line1->adjvex = y;
        line1->nextline = nullptr;
        line2->nextline = line1;
    }
    in_index[y] += 1;
    out_index[x] += 1;
}

void graph::remove(int x) {
    if (in_index[x] != 0) {
        cout << "error：x结点有入度" << endl;
        return;
    }

    line* line1 = nodes[x].firstline;

    if (line1 != nullptr) {
        int v = line1->adjvex;
        in_index[v] -= 1;
        line1 = line1->nextline;
        for (; line1; line1 = line1->nextline) {
            in_index[line1->adjvex] -= 1;
        }
    }
}


int main() {
    int _vex, _arc;
    cin >> _vex >> _arc;
    
    graph g(_vex, _arc);
    
    for (int i = 0; i < g.arcnum; i++) {
        int x, y;
        cin >> x >> y;
        g.in_line(x, y);
    }   
    for (int i = 0; i < _vex; )
    {
            for (int j = 0; j < _vex; j++) {
                if (g.in_index[j] == 0) {
                    cout << j << " ";
                    g.remove(j);
                    g.in_index[j] = -1;
                    i++;
                }
            }
    }    
    return 0;
}

//#include <iostream>
//#include <cstring>
//#include <queue>
//using namespace std;
//const int n = 10010, m = 2 * n,p=100;
//int h[n], e[m], ne[m], idx;
//int s[n][p];
//bool st[n];
//int n, m;
//
//void add(int a, int b)
//{
//	e[idx] = b, ne[idx] = h[a], h[a] = idx++,s[a][b]=1;
//}
//void dfs(int u)
//{
//	cout << u << ' ';
//	st[u] = true;
//	for (int i = h[u]; i != -1; i = ne[i])
//	{
//		int j = e[i];
//		if (!st[j]) dfs(j);
//	}
//}
//void o(int u)
//{
//	if (st[u] != true)
//	{
//		cout << u << " ";
//		st[u] = true;
//		for (int i = h[u]; i != -1; i = ne[i])
//		{
//			int j = e[i];
//			if (!st[j]) {
//				o(j);
//			}
//	    }
//		for (int y = 0; y < 100; y++)
//		{
//			s[u][y] = 0;
//		}
//	}
//}
//int main()
//{
//	cin >> n >> m ;
//	int temp=0;
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = 0; j < n; j++)
//		{
//			s[i][j] = 0;
//		}
//	}
//	memset(h, -1, sizeof h);
//	while (m--)
//	{
//		int a, b;
//		cin >> a >> b;
//		add(a, b);
//	}
//	memset(st, false, sizeof st);
//	for (int i = 0; i < n; i++) {
//		if (st[i] == false)
//		{
//			for (int j = 0; j < n; j++)
//			{
//				temp += s[i][j];
//			}
//			if (temp == 0)
//			{
//				o(i);
//				i = 0;
//			}
//		}
//	}
//	cout << endl;
//	return 0;
//}



// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
