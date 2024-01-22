// 2111033_H5_Q1.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include<iostream>
using namespace std;
const int Maxn = 1010;
int Farthest_in_Future(int i, int s, int* requests_sequence, int k, int* cache) {
	//函数返回的是Farthest_in_Future的那个需要evict的最大数字对应位置
	//i对应的是此时已经遍历到了requests_sequence的哪个位置
	//数组直接在传进来的时候就进行这一步操作
	bool* appeared = new bool[k];
	for (int j = 0; j < k; j++)
		appeared[j] = false;
	int appear_num = 0;
	int start_pos = i;//保存此时遍历到的位置（i后面会变化），即开始位置
	//，由于，最后我们如果都不存在时需要用longest not used,后面选择时使用
	while (++i < s) {
		for (int j = 0; j < k; j++) {//遍历cache，看此时的requests_sequence[i]是否在cache里面
			if (requests_sequence[i] == cache[j])
			{//若在cache里面
				appeared[j] = true;//标志其出现过
				appear_num++;
				break;
			}
		}
		if (appear_num == k - 1) 
		{//若此时只有一个数字没有出现过了，直接跳出对序列的遍历
			break;
		}
	}
	//此时跳出了上述循环有两种可能，要么是遍历到了序列末尾
	//此时while条件不满足退出（即有大于1个cache中的数字未出现）
	//要么是因为此时只有一个数字未出现过了，才break跳出的循环
	if (appear_num == k - 1) {
		//若是因为此时只有一个数字没有出现过了而退出循环，直接返回该数字来evict
		for (int j = 0; j < k; j++) {
			if (appeared[j] == false)
				return j;
		}
	}
	else {//若是遍历到了序列末尾，此时while条件不满足退出
		//（即有大于1个cache中的数字未出现），选出其中longest not used的
		//即从那些到序列末尾都没出现的数字中，选出一个距离上次出现到start_pos最久的
		for (int m = start_pos - 1; m >= 0; m--) {//从start_pos开始往回倒着遍历
			if (appear_num == k - 1) {
				//若此时只剩最后一个数字未出现，那它一定是最久未出现的，直接输出它的位置
				for (int j = 0; j < k; j++) {
					if (appeared[j] == false)
						return j;
				}
			}
			for (int j = 0; j < k; j++) {//对之前序列的每个数字进行判断
				if (requests_sequence[m] == cache[j]) {//若其在cache中，则设置其appeared为true
					//用这种方法，最后剩下的那个一定是距离现在start_pos最远的，即最久未使用的
					appeared[j] = true;
					appear_num++;
					break;
				}
			}
		}
	}
}
void OptimalCaching(int k, int n, int* cache, int s, int* requests_sequence)
{
	int current_block = n;//用来记录此时cache之中的block数
	for (int i = 0; i < s; i++) {
		if (current_block < k) {//若此时cache未满，直接把序列数字加入进去到下一位
			cache[current_block] = requests_sequence[i];
			current_block++;
			continue;
		}
		bool flag = false;//用来标志此时cache之中是否已经有了本来想要保存的序列数字
		for (int j = 0; j < k; j++) {
			if (cache[j] == requests_sequence[i]) {
				flag = true;
				break;
			}
		}
		if (flag) //若已经有了，直接遍历下一个序列数字
			continue;
		else {//若此时cache中没有，则需要找到Farthest_in_Future的最大数字，将其evict
			int evict_pos = Farthest_in_Future(i, s, requests_sequence, k, cache);
			//获取要evict的数字下标
			cout << cache[evict_pos] << " ";
			cache[evict_pos] = requests_sequence[i];
		}
	}
	return;
}
int main() {
	int k, n, s;
	cin >> k >> n >> s;
	int* cache = new int[k];//Cache动态分配生成
	int* requests_sequence = new int[s];//request of sequence
	for (int i = 0; i < n; i++)
		cin >> cache[i];
	for (int i = 0; i < s; i++)
		cin >> requests_sequence[i];
	int current_block = n;//用来记录此时cache之中的block数
	for (int i = 0; i < s; i++) {
		if (current_block < k) {//若此时cache未满，直接把序列数字加入进去到下一位
			cache[current_block] = requests_sequence[i];
			current_block++;
			continue;
		}
		bool flag = false;//用来标志此时cache之中是否已经有了本来想要保存的序列数字
		for (int j = 0; j < k; j++) {
			if (cache[j] == requests_sequence[i]) {
				flag = true;
				break;
			}
		}
		if (flag) //若已经有了，直接遍历下一个序列数字
			continue;
		else {//若此时cache中没有，则需要找到Farthest_in_Future的最大数字，将其evict
			int evict_pos = Farthest_in_Future(i, s, requests_sequence, k, cache);
			//获取要evict的数字下标
			cout << cache[evict_pos] << " ";
			cache[evict_pos] = requests_sequence[i];
		}
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
