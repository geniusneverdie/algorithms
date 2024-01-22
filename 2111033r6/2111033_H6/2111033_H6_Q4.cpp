// 2111033_H6_Q4.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <cstdio>
#include<iostream>
using namespace std;
const int Maxn = 1010;

int MergeSort(int s[], int left, int middle, int right)
{
    int i = left, j = middle;
    int b[Maxn];
    int index = 0;
    int sum = 0;
    int t = 0;    
    //核心代码
    while (i < middle && j <= right)
    {
        if (s[i] > s[j])
        {
            b[index++] = s[j++];//b作为遍历是移动的指针不断向后
            t++;//t的距离增加，交换时逆序对数量增加
        }
        if (s[i] <= s[j] || j == right + 1)
        {// j == right + 1是防止j已经到达最右边啦，i却没有
        //因此我们需要进入if语句中判断而不是直接跳出
            sum += t * (middle - i);
            b[index++] = s[i++];
            t = 0;//交换之后t的差距重置
        }
    }
    while (i < middle)
        b[index++] = s[i++];
    while (j <= right)
        b[index++] = s[j++];
    index = 0;
    for (int m = left; m <= right; m++)
        s[m] = b[index++];
    return sum;//最后返回给k值
}
int k = 0;
void Merge(int s[], int low, int high)
{
    if (low < high)
    {
        int mid = (low + high) / 2;
        Merge(s, low, mid);
        Merge(s, mid + 1, high);
        k += MergeSort(s, low, mid + 1, high);
    }
}
int main()
{
    int a[Maxn];
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    Merge(a, 0, n - 1);
    cout << "问题三的输出:" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << a[i]<<" ";
        //问题三的输出
    }
    cout << endl;
    cout << "问题四的输出" << endl;
    cout << k;//问题四的输出
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
