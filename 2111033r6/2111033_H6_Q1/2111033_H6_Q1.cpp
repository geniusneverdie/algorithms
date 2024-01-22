//第六次作业第一题：Implement algorithms of minimum spanning tree
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define MaxNum 100
class Edge {//为了实现Kruskal算法定义的Edge类，Prim算法用不上
public:
	int vex, adj;
	int length;
	Edge(int vex, int adj, int length) {
		this->vex = vex;
		this->adj = adj;
		this->length = length;
	}
};
class UndirectedGraphWithWeight_AdjacencyMatrix {
	//无向图,邻接矩阵存储
public:
	int vexnum, arcnum;
	int EdgeWithWeight[MaxNum][MaxNum];
	vector<Edge> EdgeList;
	//为了进行Kruskal算法生成最小生成树，提前在初始化时候存储了每条边对应的长度和相邻接的两个顶点
	UndirectedGraphWithWeight_AdjacencyMatrix(int vexnum, int arcnum) {
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
			Edge edge(vex, adj, length);
			EdgeList.push_back(edge);
			EdgeWithWeight[vex - 1][adj - 1] = EdgeWithWeight[vex - 1][adj - 1] = length;
		}
	}
};
void Prim_MinimumSpanningTree(UndirectedGraphWithWeight_AdjacencyMatrix G, int source_node) {
	//source_node为从哪个结点开始纳入最小生成树
	bool* exploredS_v = new bool[G.vexnum];
	//判断该顶点是否已经加入了生成树的bool类型数组,顶点i被保存在i-1的位置
	int* lowestCost = new int[G.vexnum];
	//将每个结点加入树的最小代价，与上同理：顶点i被保存在i-1的位置
	int source_pos = source_node - 1;
	for (int i = 0; i < G.vexnum; i++) {
		//exploredS_v的初始化，除了source_node以外的顶点都设为false,source_node设为true
		if (i == source_pos)
			exploredS_v[i] = true;
		else
			exploredS_v[i] = false;
	}
	for (int i = 0; i < G.vexnum; i++) {//lowestCost的初始化
		if (G.EdgeWithWeight[source_pos][i] != 0)
			//若其和source_node之间有边相连接，初始化为边的长度
			lowestCost[i] = G.EdgeWithWeight[source_pos][i];
		else
			//若没有边相连接，或者是source_node与自己，都将代价设为无穷，用int的最大值INT_MAX表示
			lowestCost[i] = INT_MAX;
	}
	int current_node = 1;
	//记录现在最小生成树中有多少个结点了
	int SumOfAllEdges = 0;//the sum of all edges in minimum spanning tree
	while (current_node < G.vexnum) {
		int min_cost = INT_MAX;
		for (int i = 0; i < G.vexnum; i++) {
			//每次循环，寻找还没加入到生成树中且加入代价所需最小的结点
			if (!exploredS_v[i] && lowestCost[i] < min_cost) {
				//若该顶点还未加入到生成树中,且代价比min_cost小
				min_cost = lowestCost[i];
				exploredS_v[i] = true;
				current_node++;
				SumOfAllEdges += lowestCost[i];
				for (int j = 0; j < G.vexnum; j++) {
					//再次循环遍历，更新还未加入的各个顶点的lowestCost
					//（只需要去检查与新增加的结点之间有边连接的未加入的顶点）
					if (!exploredS_v[j] && G.EdgeWithWeight[i][j] > 0 && G.EdgeWithWeight[i][j] < lowestCost[j])
					{
						//若某个顶点还未加入
						//且和新增加的顶点i+1(保存的位置是i，顶点为i+1)之间有边连接
						//并且边还小于之前记录的最小代价lowestCost
						lowestCost[j] = G.EdgeWithWeight[i][j];
					}
				}
			}
		}
	}
	cout << SumOfAllEdges << endl;
	return;
}


//以下均为Kruskal算法所用到的函数，与Prim算法无关！


int FindFather(int a, vector<int> father) {//用来判断父亲结点是否相同
	while (a != father[a - 1]) {
		a = father[a - 1];
	}
	return a;
}
bool isConnectedInMinimumSpanningTree(int m, int n, vector<int> father) {//判断二者是否在最小生成树中已经连通
	return FindFather(m, father) == FindFather(n, father);//实质上就是判断二者在最小生成树中的父亲结点是否相同
}
bool compare(Edge a, Edge b) {//用于stable_sort的比较函数规则
	return a.length < b.length;
}
//void Kruskal_MinimumSpanningTree(UndirectedGraphWithWeight_AdjacencyMatrix G) {
//	stable_sort(G.EdgeList.begin(), G.EdgeList.end(), compare);
//	先调用algorithm函数库的stable_sort函数让EdgeList中的所有边按照长度升序排序
//	int SumOfAllEdges = 0;//the sum of all edges in minimum spanning tree
//	vector <int> father;//记录每个结点的“父亲结点”
//	int current_edge = 0;//记录此时MST中的边数
//	for (int i = 0; i < G.vexnum; i++) {
//		father.push_back(i + 1);//初始化父亲结点为自己
//	}
//	for (int i = 0; i < G.arcnum; i++) {
//		if (current_edge == G.vexnum - 1) 
//		{
//			当边的数目为n-1时候，提前停止算法（用于边较多的时候可以提高效率）
//			cout << SumOfAllEdges << endl;
//			return;
//		}
//		if (!isConnectedInMinimumSpanningTree(G.EdgeList[i].vex, G.EdgeList[i].adj, father))
//		{
//			每次循环，按照顺序检查EdgeList的每个边
//			若两边未连通，则把两头的结点和之间的边纳入最小生成树
//			SumOfAllEdges += G.EdgeList[i].length;//加入该边的长度
//			current_edge++;
//			father[FindFather(G.EdgeList[i].vex, father) - 1] = father[FindFather(G.EdgeList[i].adj, father) - 1];
//			将两顶点并入一个集合中
//		}
//	}
//}
int main() {
	int n, e;
	cin >> n >> e;
	UndirectedGraphWithWeight_AdjacencyMatrix G(n, e);//以邻接矩阵的形式存储
	//Prim_MinimumSpanningTree(G, 1);//Prim算法默认从1号结点开始构造最小生成树
	stable_sort(G.EdgeList.begin(), G.EdgeList.end(), compare);
	//先调用algorithm函数库的stable_sort函数让EdgeList中的所有边按照长度升序排序
	int SumOfAllEdges = 0;//the sum of all edges in minimum spanning tree
	vector <int> father;//记录每个结点的“父亲结点”
	int current_edge = 0;//记录此时MST中的边数
	for (int i = 0; i < G.vexnum; i++) {
		father.push_back(i + 1);//初始化父亲结点为自己
	}
	for (int i = 0; i < G.arcnum; i++) {
		if (current_edge == G.vexnum - 1)
		{
			//当边的数目为n-1时候，提前停止算法（用于边较多的时候可以提高效率）
			cout << SumOfAllEdges << endl;
			return 0;
		}
		if (!isConnectedInMinimumSpanningTree(G.EdgeList[i].vex, G.EdgeList[i].adj, father))
		{
			//每次循环，按照顺序检查EdgeList的每个边
			//若两边未连通，则把两头的结点和之间的边纳入最小生成树
			SumOfAllEdges += G.EdgeList[i].length;//加入该边的长度
			current_edge++;
			father[FindFather(G.EdgeList[i].vex, father) - 1] = father[FindFather(G.EdgeList[i].adj, father) - 1];
			//将两顶点并入一个集合中
		}
	}
	//Kruskal_MinimumSpanningTree(G);//Kruskal算法产生最小生成树
	return 0;
}
