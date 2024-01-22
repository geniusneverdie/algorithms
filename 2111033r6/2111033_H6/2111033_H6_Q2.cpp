// 2111033_H6_Q2.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include<iostream>
#include<iomanip>
using namespace std;
const int Maxn = 1010;
struct HaffNode
{
	int weight;
	int parent;
	int lchild;
	int rchild;
};
struct HaffCode
{
	int bit[100];
	int start;
	int weight;
};
void Haffman(int w[], int n, HaffNode ht[], HaffCode hc[])
{
	int i, j, m1, m2, x1, x2;
	for (i = 0; i < 2 * n - 1; i++)
	{
		if (i < n)
			ht[i].weight = w[i];
		else
			ht[i].weight = 0;
		ht[i].parent = 0;
		ht[i].lchild = -1;
		ht[i].rchild = -1;
	}
	for (i = 0; i < n - 1; i++)
	{
		m1 = m2 = 1000;
		x1 = x2 = 0;
		for (j = 0; j < n + i; j++)
		{
			if (ht[j].weight < m1 && ht[j].parent == 0)
			{
				m2 = m1;
				x2 = x1;
				m1 = ht[j].weight;
				x1 = j;
			}
			else
				if (ht[j].weight < m2 && ht[j].parent == 0)
				{
					m2 = ht[j].weight;
					x2 = j;
				}
		}
		ht[x1].parent = n + i;
		ht[x2].parent = n + i;
		ht[n + i].weight = ht[x1].weight + ht[x2].weight;
		ht[n + i].lchild = x1;
		ht[n + i].rchild = x2;
	}
	//由哈夫曼树生成哈夫曼编码
	HaffCode cd;
	int child, parent;
	for (i = 0; i < n; i++)
	{
		cd.start = n - 1;
		cd.weight = ht[i].weight;
		child = i;
		parent = ht[child].parent;
		while (parent != 0)
		{
			if (ht[parent].lchild == child)
				cd.bit[cd.start] = 0;
			else
				cd.bit[cd.start] = 1;
			cd.start--;
			child = parent;
			parent = ht[child].parent;
		}
		for (j = cd.start + 1; j < n; j++)
			hc[i].bit[j] = cd.bit[j];
		hc[i].start = cd.start;
		hc[i].weight = cd.weight;
	}
}
int main()
{
	//int w[] = { 4,2,6,8,3,2,1 };
	//int n = 7, i, j;
	double s = 0;
	int n;
	int i, j;
	cin >> n;
	int w[Maxn];
	for (int r = 0; r < n; r++)
		cin >> w[r];
	HaffNode* ht = new HaffNode[2 * n - 1];
	HaffCode* hc = new HaffCode[n];
	Haffman(w, n, ht, hc);
	/*for (i = 0; i < n; i++)
	{
		cout << "weight=" << n - hc[i].start - 1 << endl;
		for (j = hc[i].start + 1; j < n; j++)
			cout << hc[i].bit[j];
	
		    cout << endl;
	}*/
	int q = 0;
	for (int r = 0; r < n;r++)
	{
		s += (n - hc[r].start - 1)*(r+1);
		q += w[r];
	}
	
	double l = s / q;
	cout << setprecision(3) << l;
	system("pause");
	return 0;
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
