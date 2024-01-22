//// 2111033_H10_Q1.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
#include<iostream>
#include<queue>
using namespace std;
#define INF 0x3f3f3f3f
const int MAXN = 101;
struct Node		//队列结点类型
{
    int no;			    //结点编号
    int i;			    //表示当前结点属于解空间的第i层（根节点的层次为0），即准备为人员i分配任务
    int x[MAXN];		//x[i]为人员i分配的任务编号
    bool worker[MAXN];	//worker[i]=true表示任务i已经分配
    int cost;			//已经分配任务所需要的成本
    int l;			    //下界
    bool operator<(const Node& s) const	//重载<关系函数>
    {
        return l > s.l;   
    }
};
//问题表示
int bestx[MAXN];		//最优分配方案
int mincost = INF;		//最小成本
int total = 1;			//结点个数累计
int n;
int c[MAXN][MAXN];
void bound(Node& e)     //求结点e的限界值
{
    int minsum = 0;
    for (int i1 = e.i + 1; i1 <= n; i1++)      //寻找每一行的最小值
    {                                        //如果找到e这个节点，如果说他选择了某个任务的话
                                             //就不能选择那一列的值了
        int minc = INF;
        for (int j1 = 1; j1 <= n; j1++)
            if (e.worker[j1] == false && c[i1][j1] < minc)
                minc = c[i1][j1];
        minsum += minc;
    }
    e.l = e.cost + minsum;          //e.cost代表选择的结点成本+剩下的最小的成本
    //cout << e.lb << " ";           //可以自行选择输出不输出
}
void bfs()
{
    int j;
    Node e, e1;                  //e,e1相当于两个儿，帮忙运进队列的
    priority_queue<Node> qu;
    memset(e.x, 0, sizeof(e.x));               //解向量
    memset(e.worker, 0, sizeof(e.worker));     //任务是否分配
    e.i = 0;                      //根节点也是虚结点
    e.cost = 0;
    bound(e);
    e.no = total++;
    qu.push(e);
    while (!qu.empty())
    {
        e = qu.top();
        qu.pop();
        if (e.i == n)
        {
            if (e.cost < mincost)
            {
                mincost = e.cost;
                for (j = 1; j <= n; j++)
                    bestx[j] = e.x[j];
            }
        }
        e1.i = e.i + 1;         //相当于在根节点的情况下开始拓展进行下一个节点
        for (j = 1; j <= n; j++)
        {
            if (e.worker[j])     //查看任务j是否分配
                continue;
            for (int i1 = 1; i1 <= n; i1++)
                e1.x[i1] = e.x[i1];         //相当于对e1初始化（1）
            e1.x[e1.i] = j;
            for (int i2 = 1; i2 <= n; i2++)
                e1.worker[i2] = e.worker[i2];     //相当于对e1初始化（2)  
            //:::(1)(2)就相当于创建了一个新的结点并且对他初始化
            e1.worker[j] = true;           //这个代表的是它的第几个任务被选择
            e1.cost = e.cost + c[e1.i][j];
            bound(e1);
            e1.no = total++;
            if (e1.l <= mincost)     //剪枝
                qu.push(e1);
        }
    }
}
int main()
{    
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> c[i][j];
        }
    }
    bfs();
    cout << "最优方案：" << endl;
    for (int k = 1;k <= n;k++)
    {
        cout << "第" << k << "个人员分配第" << bestx[k] << "个任务" << endl;
    }
    cout << "总成本" << mincost;
    return 0;
}

//// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
//// 调试程序: F5 或调试 >“开始调试”菜单
//
//// 入门使用技巧: 
////   1. 使用解决方案资源管理器窗口添加/管理文件
////   2. 使用团队资源管理器窗口连接到源代码管理
////   3. 使用输出窗口查看生成输出和其他消息
////   4. 使用错误列表窗口查看错误
////   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
////   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
