//경로가 주어질때 갈수 있는 모든 경로 출력하기

#include <iostream>
#include <vector>

using namespace std;
#define MAX 100

bool ptr[MAX][MAX] = {};
void dfs(vector<vector<int> > &graph, int start, int i, int j, int n, bool visited[][MAX]);
int main()
{
	int n;
	cin >> n;

	vector<vector<int> > graph(n);
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
		{
			bool b;
			cin >> b;
			if(b)
				graph[i].push_back(j);
		}

	for(int i=0;i<(int)graph.size();i++)
	{
		bool visited[n][MAX] = {};
		for(int j=0;j<(int)graph[i].size();j++)
			dfs(graph, i, i, graph[i][j], n, visited);
	}

	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
			cout << ptr[i][j] << " ";
		cout << "\n";
	}
	return 0;
}

void dfs(vector<vector<int> > &graph, int start, int i, int j, int n, bool visited[][MAX])
{
	if(visited[i][j])
		return;

	visited[i][j] = true;
	ptr[start][j] = true;

	for(int k=0;k<(int)graph[j].size();k++)
	{
		int h = graph[j][k];
		dfs(graph, start, j, h, n, visited);
	}
}
