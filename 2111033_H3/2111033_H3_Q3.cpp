// 2111033_H3_Q3.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
const int N = 100010, M = 2 * N;
int h[N], e[M], ne[M], idx;
bool st[N];
int n, m, s;
int op = 0;
void add(int a, int b)
{
	e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}
void dfs(int u)
{
	//cout << u << ' ';
	st[u] = true;
	for (int i = h[u]; i != -1; i = ne[i])
	{
		int j = e[i];
		if (!st[j]) dfs(j);
	}
}
void bfs()
{
	queue<int> q;
	q.push(s);
	st[s] = true;
	while (q.size())
	{
		int t = q.front();
		q.pop();
		//cout << t << ' ';
		op++;
		for (int i = h[t]; i != -1; i = ne[i])
		{
			int j = e[i];
			if (st[j]) continue;
			st[j] = true;
			q.push(j);
		}
	}
	if (op == n)
	{
		cout << "Yes";

	}
	else
	{
		cout << "NO";
	}
	//cout << endl;
}
int main()
{
	cin >> n >> m >> s;
	memset(h, -1, sizeof h);
	while (m--)
	{
		int a, b;
		cin >> a >> b;
		add(a, b);
		add(b, a);
	}

	bfs();
	memset(st, false, sizeof st);
	dfs(s);
	cout << endl;
	return 0;
}
/*
6 5 1
0 2
1 3
0 1
4 5
4 5
*/

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
