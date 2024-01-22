// 2111033_H8_Q2.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include<iostream>
#include<cstdio>//读取hpc.in和写hpc.out需要用到的头文件
using namespace std;
int nA, nB;//A和B子问题的数量
int p;
int* tA = new int[p + 1];//动态内存分配
int* tB = new int[p + 1];
int* kA = new int[p + 1];
int* kB = new int[p + 1];
int f[30][70][70];//三维数组f[i][a][b]表示第i个计算节点，完成a个A任务
//，b个B任务所需要的最短时间——用于内层的第一步动态规划
int C[30][70][70];//三维数组C[i][a][b]表示第i个计算节点，
//完成a个A任务，b个B任务所需要的最短时间——用于外层的第二步动态规划
void HighPerformanceComputerTaskAllocationProblem_DynamicProgramming_1() {//进行内层动态规划，计算出第i个节点完成a个A和b个B的最短时间
	for (int i = 1; i <= p; i++) {//遍历所有节点
		int P[2][70][70];//对于第i个计算节点，使用三维动态数组P,P[a][b][0/1]表示该结点完成a个A和b个B
		//且第一维的0时表示最后一个任务为A任务的情况；第一维的1时表示最后一个任务为B任务的情况
		memset(P, 31, sizeof(P));//使用memset函数对P中所有元素初始化
		P[1][0][0] = P[0][0][0] = 0;//没有任务时没有意义，直接就是0
		for (int a = 0; a <= nA; a++) {
			for (int b = 0; b <= nB; b++) {//a个A和b个B任务遍历其所有组合
				for (int w = 1; w <= a; w++)//若最后一个任务为A任务，遍历其分配给结点的A任务数量的所有可能
					P[0][a][b] = min(P[0][a][b], P[1][a - w][b] + kA[i] * w * w + tA[i]);
				for (int w = 1; w <= b; w++)//若最后一个任务为B任务，遍历其分配给结点的B任务数量的所有可能
					P[1][a][b] = min(P[1][a][b], P[0][a][b - w] + kB[i] * w * w + tB[i]);
				f[i][a][b] = min(P[0][a][b], P[1][a][b]);//两种情况取最小
			}
		}
	}
	return;
}
void HighPerformanceComputerTaskAllocationProblem_DynamicProgramming_2() {
	//进行外层动态规划，计算出前i个结点完成a个A和b个B的最短时间
	memset(C, 31, sizeof(C));//使用memset函数将C中所有元素初始化
	for (int i = 0; i <= nA; i++) {
		for (int j = 0; j <= nB; j++) {
			C[1][i][j] = f[1][i][j];//当只有一个计算结点时候，与前1个结果相同，故直接赋值
		}
	}
	for (int i = 2; i <= p; i++) {//从前两个节点开始遍历
		for (int a = 0; a <= nA; a++) {//遍历前i-1个结点已经完成的a个A与b个B的所有任务组合
			for (int b = 0; b <= nB; b++) {
				for (int w1 = 0; w1 <= a; w1++) {//第i个结点分配w1个A，分配w2个B的所有任务组合
					for (int w2 = 0; w2 <= b; w2++) {
						C[i][a][b] = min(C[i][a][b], max(C[i - 1][a - w1][b - w2], f[i][w1][w2]));//最后结束计算的节点的完成时间尽可能早
					}
				}
			}
		}
	}
	return;
}
int main() {
#pragma warning(disable : 4996)
	freopen("hpc.in", "r", stdin);//重定向输入流
	freopen("hpc.out", "w", stdout);//重定向输出流	
	scanf("%d%d%d", &nA, &nB, &p);//连续读入三个%d，中间默认的hpc.in中已经用空格隔开（包括换行）
	if (nA < 1 || nA>60 || nB < 1 || nB>60 || p < 1 || p>20) {//违反输入规定
		cout << "Input Wrong!Please input again." << endl;
		return 0;
	}
	for (int i = 1; i <= p; i++) {//读取每个结点的tA,tB,kA,kB
		scanf("%d%d%d%d", &tA[i], &tB[i], &kA[i], &kB[i]);//连续读入四个%d，中间默认的hpc.in中已经用空格隔开
		if (tA[i] < 1 || tA[i]>1000 || tB[i] < 1 || tB[i]>1000 || kA[i] < 1 || kA[i]>50 || kB[i] < 1 || kB[i]>50) {//违反输入规定
			cout << "Input Wrong!Please input again." << endl;
			return 0;
		}
	}
	HighPerformanceComputerTaskAllocationProblem_DynamicProgramming_1();
	HighPerformanceComputerTaskAllocationProblem_DynamicProgramming_2();
	printf("%d", C[p][nA][nB]);//此时C[p][nA][nB]对应的就是题目要求的结果。使用printf的%d向文件写入十进制结果
	fclose(stdin);//关闭重定向输入流
	fclose(stdout);//关闭重定向输出流
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
