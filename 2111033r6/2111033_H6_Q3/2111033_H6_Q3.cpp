// 2111033_H6_Q3.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//


#include<iostream>
using namespace std;
const int Maxn = 1010;

void Merge(int a[], int low, int mid, int high) {
    //low为第1有序区的第1个元素，i指向第1个元素, mid为第1有序区的最后1个元素
    int i = low, j = mid + 1, k = 0; //mid+1为第2有序区第1个元素，j指向第1个元素
    int* temp = new(nothrow) int[high - low + 1]; //temp数组暂存合并的有序序列
    if (!temp) { //内存分配失败
        cout << "error";
        return;
    }
    while (i <= mid && j <= high) {
        if (a[i] <= a[j]) //较小的先存入temp中
            temp[k++] = a[i++];
        else
            temp[k++] = a[j++];
    }
    while (i <= mid)//若比较完之后，第一个有序区仍有剩余，则直接复制到t数组中
        temp[k++] = a[i++];
    while (j <= high)//同上
        temp[k++] = a[j++];
    for (i = low, k = 0; i <= high; i++, k++)//将排好序的存回a中low到high这区间
        a[i] = temp[k];
    delete []temp;//删除指针，由于指向的是数组，必须用delete []
}

//用递归应用二路归并函数实现排序——分治法
void MergeSort(int arr[], int low, int high) {
    if (low < high) {
        int mid = (low + high) / 2;
        MergeSort(arr, low, mid);
        MergeSort(arr, mid + 1, high);
        Merge(arr, low, mid, high);
    }
}

int main() {
    int n;
    int a[Maxn];
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    MergeSort(a, 0, n-1);
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
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
