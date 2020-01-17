//개인과 개인 사이에 아는 거리에 대한 최소인 사람을 구하기
//bfs를 이용하여 count값을 저장해주고, sum으로 모두 더하여 최소 사람을 구해준다.

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void bfs(vector<vector<int> > &graph, bool* visited, int n, int start, int* count);
int main()
{
	int n, m;
	cin >> n >> m;

	vector<vector<int> > graph(n+1);
	for(int i=0;i<m;i++)
	{
		int f1, f2;
		cin >> f1 >> f2;
		graph[f1].push_back(f2);
		graph[f2].push_back(f1);
	}

	int sum[n+1] = {};
	for(int i=1;i<=n;i++)
	{
		int count[n+1] = {};
		bool visited[n+1] = {};
		bfs(graph, visited, n, i, count);
		for(int j=1;j<=n;j++)
			sum[i] += count[j];
	}

	int min_index = 1;
	for(int i=1;i<=n;i++)
		if(sum[min_index]>sum[i])
			min_index = i;

	cout << min_index;
	return 0;
}

void bfs(vector<vector<int> > &graph, bool* visited, int n, int start, int* count)
{
	queue<pair<int, int>> Q;
	Q.push({start, 0});
	count[start] = 0;

	while(!Q.empty())
	{
		int m = Q.front().first;
		int c = Q.front().second;
		Q.pop();
		count[m] = c;
		visited[m] = true;

		for(int i=0;i<(int)graph[m].size();i++)
		{
			int w = graph[m][i];
			if(visited[w])
				continue;
			visited[w] = true;
			Q.push({w, c+1});
		}
	}
}
