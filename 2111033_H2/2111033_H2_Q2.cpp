// 2111033H2Q2.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include<iostream>
using namespace std;

class Node
{
public:
	int data;
	Node* next;
};

Node* SortMerge(Node* a, Node* b)
{
	Node* result = NULL;
	if (a == NULL)
	{
		return(b);
	}
	else if (b == NULL)
	{
		return(a);
	}
	if (a->data <= b->data)
	{
		result = a;
		result->next = SortMerge(a->next, b);
	}
	else
	{
		result = b;
		result->next = SortMerge(a, b->next);
	}
	return(result);
}

void push(Node** head_ref, int new_data)
{
	Node* new_node = new Node();
	new_node->data = new_data;
	new_node->next = (*head_ref);
	(*head_ref) = new_node;
}

void printList(Node* node)
{
	while (node != NULL)
	{
		cout << node->data << " ";
		node = node->next;
	}
}

int main()
{
	Node* r = NULL;
	Node* a = NULL;
	Node* b = NULL;
	int n, m;
	int x, y;
	cout << "第一个链表个数：" << endl;
	cin >> n;
	cout << "第二个链表个数：" << endl;
	cin >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> x;
		push(&a, x);
	}
	for (int i = 0; i < m; i++)
	{
		cin >> y;
		push(&b, y);
	}
	r = SortMerge(a, b);
	printList(r);
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
