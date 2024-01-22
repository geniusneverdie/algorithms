//第一次作第一题-Stable Matching
#include<iostream>
using namespace std;
int n;
bool* men_engaged = new bool[n];
bool* women_engaged = new bool[n];
void StableMatching_Gale_Shapley(int** a, int** b) {
	int* Lady_Offer = new int[n];//最终匹配结果，下标0-n-1为女士，其数字为男士
	int* men_pointer = new int[n];
	for (int i = 0; i < n; i++) {
		Lady_Offer[i] = -1;//设置为特殊值
		men_pointer[i] = 0;
	}
	while (1) {//每一天都进行婚配
		bool flag = true;
		for (int i = 0; i < n; i++) {//检查是否所有人都已经订婚了
			if (men_engaged[i] == false)
				flag = false;
		}
		if (flag == true) {//若所有人都已经订婚了那么就结束匹配，输出结果
			int* result = new int[n];//为了最后统一输出和题目一致，改为男士作为下标，与之匹配的女士作为数值
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					if (Lady_Offer[j] == i) {
						result[i] = j;
						break;
					}
				}
			}
			for (int i = 0; i < n; i++) {
				cout << "(" << char(i + 65) << "," << char(result[i] + 88) << ")" << endl;
			}
			return;
		}
		else {
			for (int i = 0; i < n; i++) {
				if (men_engaged[i] == false) {
					if (women_engaged[a[i][men_pointer[i]]] == false) {//若此时被求婚的女士单身,被求婚的女士下标：a[i][men_pointer[i]]
						Lady_Offer[a[i][men_pointer[i]]] = i;
						men_engaged[i] = women_engaged[a[i][men_pointer[i]]] = true;
						continue;
					}
					else {//若不单身，比较谁好
						for (int j = 0; j < n; j++) {
							if (b[a[i][men_pointer[i]]][j] == i) {//若i在前，则更喜欢i，拒绝原来的婚约，和i订婚
								men_engaged[Lady_Offer[a[i][men_pointer[i]]]] = false;
								men_pointer[Lady_Offer[a[i][men_pointer[i]]]]++;
								Lady_Offer[a[i][men_pointer[i]]] = i;
								men_engaged[i]= true;
								break;
							}
							else if (b[a[i][men_pointer[i]]][j] == Lady_Offer[a[i][men_pointer[i]]]) {//若i在后，求婚失败
								men_pointer[i]++;
								break;
							}
						}
					}
				}
			}
		}
	}
	return;
}
int main() {
	cin >> n;
	int** men_preference = new int* [n];//男性默认：ABC表示
	int** women_preference = new int* [n];//女性默认：XYZ表示

	for (int i = 0; i < n; i++) {
		men_preference[i] = new int[n];
		women_preference[i] = new int[n];
		men_engaged[i] = women_engaged[i] = false;
	}
	for (int i = 0; i < 2 * n; i++) {
		if (i < n) {//男性
			string preference;
			cin >> preference;
			int j = 2;//从第三个位置开始遍历，冒号后
			int count = 0;//填好几个喜好了
			while (j<=2*n) {
					men_preference[i][count] = preference[j] - 88;//字母转换为数字（X-88，Y-89，Z-90）
					count++;
					j += 2;
			}
		}
		else {//女性
			string preference;
				cin >> preference;
				int j = 2;//从第三个位置开始遍历，冒号后
				int count = 0;//填好几个喜好了
				while (j<=2*n) {
						women_preference[i-n][count] = preference[j] - 65;//字母转换为数字（A-65，B-66，C-67)
						count++;
						j += 2;
				}
			}
	}
	StableMatching_Gale_Shapley(men_preference, women_preference);
	return 0;
	}