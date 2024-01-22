// 2111033H2Q1.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include<iostream>
using namespace std;
int BinarySearch(int arr[], int l, int r, int x)
{
	while (l <= r)
	{
		int mid = l + (r - l) / 2;

		if (arr[mid] == x)
		{
			return mid;
		}
		if (arr[mid] > x)
		{
			l = mid - 1;
		}
		else
		{
			l = mid + 1;
		}
	}
	return -1;
}

int main()
{
	int arr[100];
	int x;
	int n;
	cout << "数组个数:" << endl;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	cout << "寻找数为：" << endl;
	cin >> x;
	int result = BinarySearch(arr, 0, n - 1, x);
	if (result == -1)
	{
		cout << "未含有该元素" << endl;
	}
	if (result != -1)
	{
		cout << "该元素位置" << result << endl;
	}
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
