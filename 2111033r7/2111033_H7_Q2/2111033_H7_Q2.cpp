// 2111033_H7_Q2.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include<Windows.h>
#include <algorithm>
using namespace std;
const int N = 100;
int a[N] = { 0 };
int temp[N] = { 0 };

void BagProblem(int len, int* w, int* v, int capacity)
{
    int i, j, k;
    int maxValue = 0;
    int Value = 0;
    int Weight = 0;
    int flag = 0;
    long long  num = 1l << len; // num为2的len次方
    for (i = 0; i < num; i++)
    {
        j = i;
        k = 0;
        Value = 0;
        Weight = 0;
        flag = 0;
        while (j)
        {
            if (j & 1)
            {
                a[k] = 1;
                Value += v[k];
                Weight += w[k];
            }
            j >>= 1;
            k++;
        }
        if (Weight <= capacity && Value > maxValue)
        {
            maxValue = Value;
            flag = 1;
        }
        if (flag == 1)
        {
            for (int q = 0; q < len; q++)
            {
                temp[q] = a[q];
            }
        }
        for (int q = 0; q < len; q++)
        {
            a[q] = 0;
        }
    }
    for (int q = 0; q < len; q++)
    {
        //cout << temp[q] << " ";
    }
   // cout << endl;
    cout << maxValue << endl;
}

int main()
{
    DWORD start,end;
    start = GetTickCount();
    int n, c;
    cin >>c >> n;
    int w[N];
    int v[N];
    for (int i = 0; i < n; i++)
    {
        cin >> w[i]>>v[i];
    }   
    BagProblem(n, w, v, c);
    end = GetTickCount()-start;
    cout <<endl<< end;
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
