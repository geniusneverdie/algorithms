// 2111033_H5_Q2.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include<iostream>
using namespace std;
#define MaxNum 110 
class DirectedGraphWithWeight {
public:
	int vexnum, arcnum;
	int EdgeWithWeight[MaxNum][MaxNum];
	DirectedGraphWithWeight(int vexnum, int arcnum) 
	{
		this->arcnum = arcnum;
		this->vexnum = vexnum;
		for (int i = 0; i < vexnum; i++) {
			for (int j = 0; j < vexnum; j++) {
				EdgeWithWeight[i][j] = 0;
			}
		}
		for (int i = 0; i < arcnum; i++) {
			int vex, adj, length;
			cin >> vex >> adj >> length;
			EdgeWithWeight[vex - 1][adj - 1] = length;
		}
	}
};
//void Dijkstra(DirectedGraphWithWeight G, int source_node) {
//	source_node存在source_node-1的位置
//	bool* exploredS = new bool[G.vexnum];
//	用来标记各顶点是否已经探索过了，即是否已经找到了从source_node到它的最短路径
//	初始时source_node到自己是已经找到了最短路径的，即为true
//	int* shortestD = new int[G.vexnum];//用来记录从source_node到各点的最短路径
//	若此时存在一条可以由S中的顶点到达的最小路径，则记录；
//	 若此时通过S中的顶点无法到达某个顶点，则记为无穷，用int的最大值表示
//	初始化时若从source_node到某个顶点之间有路径，则记录；否则记为int的最大值
//	int* pred = new int[G.vexnum];//用来记录找到该顶点最短路径的直接前驱是哪个顶点
//	利用pred可以找到每一条所求的source_node到某顶点的最短路径，虽然本题没有要求，但此处一并实现
//	int source_pos = source_node - 1;
//	source_node到自己记为-1，还未找到最短路径的也记为-1
//	exploredS[source_pos] = true;
//	shortestD[source_pos] = 0;
//	for (int i = 0; i < G.vexnum; i++) {//exploredS的初始化
//		if (i != source_pos)
//		{
//			exploredS[i] = false;
//		}
//	}
//	for (int i = 0; i < G.vexnum; i++) {//shortestD和pred的初始化
//		if (G.EdgeWithWeight[source_pos][i] != 0) 
//		{
//			shortestD[i] = G.EdgeWithWeight[source_pos][i];
//			pred[i] = source_pos;//直接前驱为source_node
//		}
//		else {//若图中不存在source_node到i+1（存在的位置是i，但数据是i+1)的边
//			pred[i] = -1;
//			if (i == source_pos)//若是i到source_node不存在，有可能是因为不存在自己到自己的路径
//				continue;
//			else 
//			{
//				shortestD[i] = INT_MAX;//若此时通过S中的顶点无法到达某个顶点，则记为无穷，用int的最大值表示
//			}
//		}
//	}
//	while (1) {
//		bool flag = true;
//		int min_dis = INT_MAX;
//		int min_dis_pos = -1;
//		for (int i = 0; i < G.vexnum; i++) {//第一步：选出未被探索过，且shortestD最小的顶点
//			if (exploredS[i] == false) {//若未被探索过
//				if (shortestD[i] < min_dis) {
//					min_dis = shortestD[i];
//					min_dis_pos = i;
//				}
//				flag = false;
//			}
//		}
//		if (flag) {//若此时没有顶点没被探索过了，则直接输出结果
//			for (int i = 0; i < G.vexnum; i++) {
//				if (i == G.vexnum - 1)
//					cout << shortestD[i] << endl;
//				else
//					cout << shortestD[i] << " ";
//			}
//			return;
//		}
//		else {//若此时还有顶点未被探索过,即min_dis_pos位置的顶点min_dis_pos+1
//			exploredS[min_dis_pos] = true;
//			for (int i = 0; i < G.vexnum; i++) {
//				if (exploredS[i] == false && G.EdgeWithWeight[min_dis_pos][i] != 0) {//检查所有未被探索过不在S中，并且和min_dis_pos+1相邻接的顶点，更新它们的shortestD和pred值
//					if (shortestD[min_dis_pos] + G.EdgeWithWeight[min_dis_pos][i] < shortestD[i]) {//若存在更小的shortestD
//						shortestD[i] = shortestD[min_dis_pos] + G.EdgeWithWeight[min_dis_pos][i];
//						pred[i] = min_dis_pos;
//					}
//				}
//			}
//		}
//	}
//}
int main() 
{
	int n, e, source_node;
	cin >> n >> e >> source_node;
	DirectedGraphWithWeight G(n, e);
	bool* exploredS = new bool[G.vexnum];
	//用来标记各顶点是否已经探索过了，即是否已经找到了从source_node到它的最短路径
	//初始时source_node到自己是已经找到了最短路径的，即为true
	int* shortestD = new int[G.vexnum];//用来记录从source_node到各点的最短路径
	//若此时存在一条可以由S中的顶点到达的最小路径，则记录；
	// 若此时通过S中的顶点无法到达某个顶点，则记为无穷，用int的最大值表示
	//初始化时若从source_node到某个顶点之间有路径，则记录；否则记为int的最大值
	int* pred = new int[G.vexnum];//用来记录找到该顶点最短路径的直接前驱是哪个顶点
	//利用pred可以找到每一条所求的source_node到某顶点的最短路径，虽然本题没有要求，但此处一并实现
	int source_pos = source_node - 1;
	//source_node到自己记为-1，还未找到最短路径的也记为-1
	exploredS[source_pos] = true;
	shortestD[source_pos] = 0;
	for (int i = 0; i < G.vexnum; i++) {//exploredS的初始化
		if (i != source_pos)
		{
			exploredS[i] = false;
		}
	}
	for (int i = 0; i < G.vexnum; i++) {//shortestD和pred的初始化
		if (G.EdgeWithWeight[source_pos][i] != 0)
		{
			shortestD[i] = G.EdgeWithWeight[source_pos][i];
			pred[i] = source_pos;//直接前驱为source_node
		}
		else {//若图中不存在source_node到i+1（存在的位置是i，但数据是i+1)的边
			pred[i] = -1;
			if (i == source_pos)//若是i到source_node不存在，有可能是因为不存在自己到自己的路径
				continue;
			else
			{
				shortestD[i] = INT_MAX;//若此时通过S中的顶点无法到达某个顶点，则记为无穷，用int的最大值表示
			}
		}
	}
	while (1) {
		bool flag = true;
		int min_dis = INT_MAX;
		int min_dis_pos = -1;
		for (int i = 0; i < G.vexnum; i++) {//第一步：选出未被探索过，且shortestD最小的顶点
			if (exploredS[i] == false) {//若未被探索过
				if (shortestD[i] < min_dis) {
					min_dis = shortestD[i];
					min_dis_pos = i;
				}
				flag = false;
			}
		}
		if (flag) {//若此时没有顶点没被探索过了，则直接输出结果
			for (int i = 0; i < G.vexnum; i++) {
				if (i == G.vexnum - 1)
					cout << shortestD[i] << endl;
				else
					cout << shortestD[i] << " ";
			}
			return 0;
		}
		else {//若此时还有顶点未被探索过,即min_dis_pos位置的顶点min_dis_pos+1
			exploredS[min_dis_pos] = true;
			for (int i = 0; i < G.vexnum; i++) {
				if (exploredS[i] == false && G.EdgeWithWeight[min_dis_pos][i] != 0) {//检查所有未被探索过不在S中，并且和min_dis_pos+1相邻接的顶点，更新它们的shortestD和pred值
					if (shortestD[min_dis_pos] + G.EdgeWithWeight[min_dis_pos][i] < shortestD[i]) {//若存在更小的shortestD
						shortestD[i] = shortestD[min_dis_pos] + G.EdgeWithWeight[min_dis_pos][i];
						pred[i] = min_dis_pos;
					}
				}
			}
		}
	}
	//Dijkstra(G, source_node);
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
