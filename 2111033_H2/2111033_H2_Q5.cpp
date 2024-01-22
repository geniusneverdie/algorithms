// 2111033_H2_Q5.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

//O（n3）：
#include<iostream>
using namespace std;

int FindTarget(int arr[], int n, int sum)
{
	for (int i = 0; i < n - 2; i++)
	{
		for (int j = i + 1; j < n - 1; j++)
		{
			for (int k = j + 1; k < n; k++)
			{
				if (arr[i] + arr[j] + arr[k] == sum)
				{
					cout << arr[i] << " " << arr[j] << " " << arr[k] << endl;
					return 1;
				}
			}
		}
	}
	cout << "未发现匹配值" << endl;
	return 0;
}

int main()
{
	int n;
	int arr[100];
	cout << "数组个数：" << endl;
	cin >> n;
	int sum;
	cout << "要求总和：" << endl;
	cin >> sum;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	FindTarget(arr, n, sum);
	return 0;

}
//O(n2logn) :
#include<iostream>
	using namespace std;

int BinarySearch(int arr[], int L, int R, int x)
{
	while (L <= R)
	{
		int mid = L + (R - L) / 2;

		if (arr[mid] == x)
		{
			return mid;
		}
		if (arr[mid] > x)
		{
			R = mid - 1;
		}
		else
		{
			L = mid + 1;
		}
	}
	return -1;
}

int FindTraget(int arr[], int n, int sum)
{

	for (int i = 0; i < n - 2; i++)
	{
		for (int j = i + 1; j < n - 1; j++)
		{
			int k = BinarySearch(arr, j, n - 1, sum - arr[i] - arr[j]);
			if (k == -1)
			{
				continue;
			}
			if (arr[i] + arr[j] + arr[k] == sum)
			{
				cout << arr[i] << " " << arr[j] << " " << arr[k] << endl;
				return 1;
			}

		}
	}
	cout << "未发现匹配值" << endl;
	return 0;
}

int main()
{
	int n;
	int sum;
	int arr[100];
	cout << "数组个数：" << endl;
	cin >> n;
	cout << "要求总和：" << endl;
	cin >> sum;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	FindTraget(arr, n, sum);
	return 0;
}

//O（n2）：
#include<iostream>
#include<algorithm>
using namespace std;

int FindTraget(int arr[], int n, int sum)
{
	int L, R;
	sort(arr, arr + n);

	for (int i = 0; i < n - 2; i++)
	{
		L = i + 1;//左端
		R = n - 1;//右端

		while (L < R)
		{
			if (arr[i] + arr[L] + arr[R] == sum)
			{
				cout << arr[i] << " " << arr[L] << " " << arr[R] << endl;
				return 1;
			}
			else if (arr[i] + arr[L] + arr[R] < sum)
			{
				L++;
			}
			else
			{
				R--;
			}
		}

	}
	cout << "未发现匹配值" << endl;
	return 0;

}

int main()
{
	int n;
	int sum;
	int arr[100];
	cout << "数组个数：" << endl;
	cin >> n;
	cout << "要求总和：" << endl;
	cin >> sum;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	FindTraget(arr, n, sum);
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
