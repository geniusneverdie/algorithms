// 2111033_H7_Q1.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include<iostream>
#include<math.h>
#include<Windows.h>
using namespace std;
#define N 1005
int dp[N];
int n, m, v[N], w[N];

int main()
{
	DWORD start, end;
	start = GetTickCount();
	cout << "请输入物品的数量和背包的重量" << endl;
	cin >> m >> n;
	cout << "请分别输入物品" << endl;
	for (int i = 1; i <= n; i++)
	{
		cin >> v[i] >> w[i];
		for (int j = m; j >= v[i]; j--)
		{
			dp[j] = max(dp[j], dp[j - v[i]] + w[i]);
		}
	}
	cout << dp[m] << endl;	
	end = GetTickCount() - start;
	cout << end;
	return 0;
}

//#include<iostream>
//using namespace std;
//const int MaxN = 100;
//int n, weightBag;
//int weight[MaxN], value[MaxN];

//从第i个物品开始挑选总重小于j的部分


	//cin >> n >> m;
	//cout << m <<" " <<n << endl;
//for (int i = 1; i <= n; i++)
//cout << w[i] << " " << v[i] << endl;
//cin >> w[i];
//for (int i = 0; i < n; i++)
	//cin >> v[i];
	int result;
//cout << select(1, m) << endl;


// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
