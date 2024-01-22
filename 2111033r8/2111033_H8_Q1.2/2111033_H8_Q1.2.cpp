// 2111033_H8_Q1.2.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

vector<string> lcs;

void printLCS(string s1, string s2, int i, int j, string cur) {
    if (i == 0 || j == 0) {
        string temp = cur;
        reverse(temp.begin(), temp.end());
        lcs.push_back(temp);
        return;
    }
    if (s1[i - 1] == s2[j - 1]) {
        cur += s1[i - 1];
        printLCS(s1, s2, i - 1, j - 1, cur);
    }
    else {
        printLCS(s1, s2, i - 1, j, cur);
        printLCS(s1, s2, i, j - 1, cur);
    }
}

int main() {
    string s1, s2;
    cin >> s1 >> s2;
    int n = s1.length(), m = s2.length();
    string cur = "";
    for (int i = 0; i < (1 << n); i++) {
        string temp = "";
        for (int j = 0; j < n; j++) {
            if (i & (1 << j)) {
                temp += s1[j];
            }
        }
        int k = temp.length();
        string cur = "";
        printLCS(temp, s2, k, m, cur);
    }
    for (string s : lcs) {
        cout << s << endl;
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
