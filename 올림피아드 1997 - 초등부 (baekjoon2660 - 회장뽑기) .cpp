#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void bfs(vector<vector<int> > &graph, int start, int n, bool* visited, int* count);
int main()
{
	int n;
	cin >> n;

	vector<vector<int> > graph(n+1);
	while(1)
	{
		int a, b;
		cin >> a >> b;
		if(a==-1)
			break;
		graph[a].push_back(b);
		graph[b].push_back(a);

	}

	int count[n+1] = {};
	for(int i=1;i<=n;i++)
	{
		bool visited[n+1] = {};
		bfs(graph, i, n, visited, count);
	}

	int m = count[1];
	for(int i=2;i<=n;i++)
		m = min(m, count[i]);

	int sum = 0;
	for(int i=1;i<=n;i++)
		if(count[i]==m)
			sum++;
	cout << m << " " << sum << endl;
	for(int i=1;i<=n;i++)
		if(count[i]==m)
			cout << i << " ";
}

void bfs(vector<vector<int> > &graph, int start, int n, bool* visited, int* count)
{
	queue<pair<int, int> > Q;
	Q.push({start, 1});
	visited[start] = true;

	while(!Q.empty())
	{
		int now = Q.front().first;
		int w = Q.front().second;
		Q.pop();

		for(int i=0;i<(int)graph[now].size();i++)
		{
			int next = graph[now][i];
			if(visited[next])
				continue;

			visited[next] = true;
			Q.push({next, w+1});
		}

		int sum = 0;
		for(int i=1;i<=n;i++)
			sum += visited[i];
		if(sum==n)
		{
			count[start] = w;
			return;
		}
	}
}
