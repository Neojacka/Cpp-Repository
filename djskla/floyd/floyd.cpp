#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
using namespace std;
using uint = unsigned int;
uint INF = INT_MAX;
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
	//依次将每个节点加进去
	int N = graph.size();
	for (int k = 0; k < N; k++)
	{
		for(int i=0;i<N;i++)
			for (int j = 0; j < N; j++)
			{
				graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
			}
	}
	for (auto& line : graph)
	{
		for (auto dis : line)
		{
			cout << dis << " ";
		}
		cout << endl;
	}
}