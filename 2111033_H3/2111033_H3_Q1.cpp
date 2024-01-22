// 2111033_H3_Q1.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <cstring>
using namespace std;
const int N = 100010, M = N * 2;
int h[N], e[M], ne[M], idx;
int q[N];
int dist[N];
bool st[N];
int n, m, s;
void add(int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}
void bfs()
{
    int hh = 0, tt = -1;
    memset(dist, 0x3f, sizeof dist);
    q[++tt] = s;
    dist[s] = 0;
    st[s] = true;

    while (hh <= tt)
    {
        int t = q[hh++];
        for (int i = h[t]; i != -1; i = ne[i])
        {
            int j = e[i];
            if (st[j]) continue;
            st[j] = true;
            if (dist[t] + 1 < dist[j])
            {
                dist[j] = dist[t] + 1;
                q[++tt] = j;
            }
        }
    }
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
    for (int i = 0; i < n; i++)
        printf("%d ", dist[i]);
    printf("\n");
    return 0;
}
/*
5 5 1
0 1
0 2
0 4
1 3
3 4
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
