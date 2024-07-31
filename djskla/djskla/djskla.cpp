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
	vector<uint> dis(N);//��¼�õ㵽���е�����·��
	vector<bool> use(N,false);//S����
	use[start] = true;
	//��ʼ��start���㵽���������·��
	for (int i = 0; i < N; i++)
	{
		dis[i] = graph[start][i];
	}
	//��ʣgraph.size()-1������û����ӵ�S������
	for (int i = 1; i < N; i++)
	{
		//1.�ҵ�U������·����С��ֵ�Ͷ���
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
		//2.���ö�����ӵ�S������
		use[k] = true;
		//3.����dis
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
	vector<uint> dis(N);//��¼�õ㵽���е�����·��
	vector<bool> use(N, false);//S����
	vector<int> prev(N,start);//��¼·��,�տ�ʼ���нڵ㶼�Ǵ���㿪ʼ
	use[start] = true;
	priority_queue<pair<uint, int>, vector< pair<uint, int>>, greater< pair<uint, int>>> que;
	//��ʼ��start���㵽���������·��
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
		if (use[min.second]) continue; // ��ֹ�ظ�����

		int u = min.second;
		use[u] = true; // ���ö�����ӵ�S������

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