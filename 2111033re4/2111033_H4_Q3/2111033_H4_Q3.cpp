// 2111033_H4_Q3.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include<iostream>
using namespace std;
const int Maxn=1010;

class work {
public:
	int time;//work完成所需时间
	int ddl;//期限
	int temp;//排序临时变量
};

//按照期限将works重新排序
void sort(work* w, int n) {
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - i - 1; j++) {
			if (w[j + 1].ddl < w[j].ddl) {
				work temp = w[j];
				w[j] = w[j + 1];
				w[j + 1] = temp;
			}
		}
	}
}
int main() {
	work w[Maxn];
	int n;
	cin >> n;	
	for (int i = 0; i < n; i++) {
		cin >> w[i].time >> w[i].ddl;
	}
	sort(w, n);
	int time = 0;//当前时间
	int out = 0;//单个work的延期时间
	int lateness = 0;//总的lateness
	for (int i = 0; i < n; i++) {
		time += w[i].time;//当前任务完成后的时间
		out = time - w[i].ddl;
		if (out > 0)
		{
			lateness += out;
		}
	}	
	cout << "the lateness is:" << endl;
	cout << lateness;
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
