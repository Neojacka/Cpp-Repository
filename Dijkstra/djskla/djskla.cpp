#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<queue>
#include<stack>
using namespace std;
using uint = unsigned int;
uint INF = INT_MAX;

int Dijksla(vector<vector<uint>>& graph, int start, int end)
{
	const size_t N = graph.size();
	vector<uint> dis(N);//记录该点到所有点的最短路径
	vector<bool> use(N,false);//S集合
	use[start] = true;
	//初始化start顶点到其他顶点的路径
	for (int i = 0; i < N; i++)
	{
		dis[i] = graph[start][i];
	}
	//还剩graph.size()-1个顶点没有添加到S集合中
	for (int i = 1; i < N; i++)
	{
		//1.找到U集合中路径最小的值和顶点
		int k = -1;
		uint min = INF;
		for (int j = 0; j < N; j++)
		{
			if (!use[j] && min > dis[j])
			{
				k = j;
				min = dis[j];
			}
		}
		if (k == -1)
		{
			break;
		}
		//2.将该顶点添加到S集合中
		use[k] = true;
		//3.更新dis
		for (int j = 0; j < N; j++)
		{
			if (!use[j] && min + graph[k][j] < dis[j])
			{
				dis[j] = min + graph[k][j];
			}
		}
		
	}
	for (int d : dis)
	{
		cout << d << " ";
	}
	return dis[end];
}
int Dijksla2(vector<vector<uint>>& graph, int start, int end)
{
	const size_t N = graph.size();
	vector<uint> dis(N);//记录该点到所有点的最短路径
	vector<bool> use(N, false);//S集合
	vector<int> prev(N,start);//记录路径,刚开始所有节点都是从起点开始
	use[start] = true;
	priority_queue<pair<uint, int>, vector< pair<uint, int>>, greater< pair<uint, int>>> que;
	//初始化start顶点到其他顶点的路径
	for (int i = 0; i < N; i++)
	{
		dis[i] = graph[start][i];
		if (!use[i])
			que.emplace(dis[i], i);
	}
	while (!que.empty())
	{
		pair<uint, int> min = que.top();
		que.pop();

		if (min.first == INF) break;
		if (use[min.second]) continue; // 防止重复处理

		int u = min.second;
		use[u] = true; // 将该顶点添加到S集合中

		for (int v = 0; v < N; v++) 
		{
			if (!use[v] && min.first + graph[u][v] < dis[v])
			{
				dis[v] = min.first + graph[u][v];
				que.emplace(dis[v], v);
				prev[v] = u;
			}
		}
	}
	for (int d : dis)
	{
		cout << d << " ";
	}
	int index = end;
	stack<char> path;
	char P[] = { 'A','B','C','D','E','F' };
	for(;;)
	{
		path.push(P[index]);
		if (index == 0)
			break;
		index = prev[index];
	}
	while (!path.empty())
	{
		char p = path.top();
		path.pop();
		if (path.size() >= 1)
			cout << p << "->";
		else
			cout << p << endl;
	}
	return dis[end];
}
int main()
{
	vector<vector<uint>> graph = {
		{0,6,3,INF,INF,INF},
		{6,0,2,5,INF,INF},
		{3,2,0,3,4,INF},
		{INF,5,3,0,2,3},
		{INF,INF,4,2,0,5},
		{INF,INF,INF,3,5,0}
	};
	int distant = Dijksla2(graph, 0, 5);
	if (distant != INF)
		cout << "distant:" << distant << endl;
}