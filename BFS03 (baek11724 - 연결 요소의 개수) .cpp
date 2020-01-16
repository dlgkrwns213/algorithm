//bfs를 이용하여 연결요소의 개수를 구하는 문제

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void bfs(vector<vector<int> > &graph, bool* visited, int n, int start);
int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	int n, m;
	cin >> n >> m;
	vector<vector<int> > graph(n+1);
	for(int i=0;i<m;i++)
	{
		int i1, i2;
		cin >> i1 >> i2;
		graph[i1].push_back(i2);
		graph[i2].push_back(i1);
	}

	int count = 0;
	bool visited[n+1] = {};
	for(int i=1;i<=n;i++)
	{
		if(!visited[i])
		{
			count++;
			bfs(graph, visited, n, i);
		}
	}
	cout << count;

	return 0;
}

void bfs(vector<vector<int> > &graph, bool* visited, int n, int start)
{
	queue<int> Q;
	Q.push(start);
	visited[start] = true;
	while(!Q.empty())
	{
		int m = Q.front();
		Q.pop();
		for(int i=0;i<(int)graph[m].size();i++)
		{
			int k = graph[m][i];
			if(visited[k])
				continue;
			visited[k] = true;
			Q.push(k);
		}
	}
}
