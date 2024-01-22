// 2111033_H6_Q5.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
// 分治算法求最近点对
#include<iostream>
#include<algorithm>
const int MAX = 10010;
using namespace std;

struct point {
	double x, y;
}
p[MAX];
int a[MAX];// 保存排序的索引
inline double dist(const point& a, const point& b) {
	return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
	//定义dist为两点距离的平方和，为比较和输出
}
int cmpy(int& a, int& b) {
	return p[a].y < p[b].y;
}
int cmpx(const point& a, const point& b) {
	return a.x < b.x;
}
inline double min(double a, double b) {
	return a < b ? a : b;
}
double closeset(int low, int high)
{
	if (low == high)//这两步用于遍历到最底
		return MAX;
	if (low + 1 == high)
		return dist(p[low], p[high]);
	int mid = (low + high) >> 1;//定义中间值为（low+high）/2，使左右两侧的点一样多
	double ans = min(closeset(low, mid), closeset(mid + 1, high));//定义递推公式
	int i, j, cnt = 0;
	for (i = low; i <= high; i++) {
		if (p[mid].x - ans <= p[i].x && p[i].x <= p[mid].x + ans)
			a[cnt++] = i;//找每个点的排序索引
	}
	sort(a, a + cnt, cmpy);
	for (i = 0; i < cnt; i++) {
		int k = i + 7 > cnt ? cnt : i + 7;
		for (j = i + 1; j < k; j++) {//在cnt和i+7内的范围遍历
			if (p[a[j]].y - p[a[i]].y > ans)
				break;//纵坐标大于原最小值，说明已经不可能更小，直接break跳出
			ans = min(dist(p[a[i]], p[a[j]]), ans);
		}
	}
	return ans;
}
int main() {
	int n;
	cin >> n;
	while (n) {
		for (int i = 0; i < n; i++)
			cin >> p[i].x >> p[i].y;
		sort(p, p + n, cmpx);
		cout << closeset(0, n - 1);
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
