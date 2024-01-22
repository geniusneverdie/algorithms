// 2111033_H9_Q1.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include<stdio.h>
#include<iostream>
using namespace std;
int b[110];   //用于储存已经排好的序列
bool used[110];  // 判断哪些数字已经排过
int n;     // 1-n 的全排列
int sum = 0;   // 统计有多少排列数
void output()  // 打印好排列数
{
	printf("第%d中组合:  \t", ++sum);
	for (int i = 1; i <= n; i++)
	{
		printf("%d", b[i]);
	}
	printf("\n");
}

void solve(int k) // 从第一个数开始排
{
	for (int i = 1; i <= n; i++)  // 把数字：1-n，填到数组前k个中
	{
		if (!used[i])
		{
			b[k] = i;
			used[i] = 1;
			if (k == n)     // 递归层数      //拍到第n个数后打印出来
			{
				output();
			}  // 打印出来
			else
			{
				solve(k + 1);
			}
			used[i] = 0;
		}
	}
}
int main()
{
	cin >> n;     // 从1到 n 的排列数 
	solve(1);
	return 0;
}



//#include<iostream>
//#include<stdio.h>
//
//using namespace std;
//
//int n, a[100];
//bool b[100] = { 0 };
//
//inline void scb()
//{
//	cout << "现b数组：\n";
//
//	for (int i = 1; i <= n; i++)
//		printf("%5d", b[i]);
//
//	cout << endl;
//}
//
//inline void sc()
//{
//	cout << "现a数组：\n";
//
//	for (int i = 1; i <= n; i++)
//		printf("%5d", a[i]);
//
//	cout << endl;
//}
//inline void search(int g) {
//	for (int i = 1; i <= n; i++)
//	{
//		if (!b[i])
//		{
//
//			cout << "检测到" << i << "并没有被填过(即b数组的" << i << "位置为0)\n";
//
//			a[g] = i;
//			cout << "现在在a数组的第" << g << "个位置填入" << i << "\n";
//			sc();
//			system("pause");
//			cout << '\n';
//
//			cout << "将" << i << "标记为已用过\n";
//			b[i] = 1;
//			scb();
//			system("pause");
//			cout << '\n';
//
//			if (g == n)cout << "\n最终答案如下：\n", sc(), system("pause"), cout << '\n';
//
//			else search(g + 1);
//
//			cout << "将" << i << "标记为没有用过\n";
//			b[i] = 0;
//			scb();
//
//		}
//	}
//}
//int main()
//{
//	cin >> n;
//
//	cout << "a数组初始化：\n"; sc();
//	cout << '\n';
//
//	cout << "b数组初始化：\n"; scb();
//	system("pause");
//	cout << '\n';
//
//	search(1);
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
