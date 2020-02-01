//시간초과에 유의해주는 기본적인 dfs문제

#include <iostream>
#include <vector>

using namespace std;

void dfs(vector<vector<int> > &graph, bool* visited, int now, int n, int* count, int start);
int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;

	vector<vector<int> > graph(n+1);
	while(m--)
	{
		int c1, c2;
		cin >> c1 >> c2;
		graph[c2].push_back(c1);
	}

	int count[n+1] = {};
	for(int start=1;start<=n;start++)
	{
		bool visited[n+1] = {};
		dfs(graph, visited, start, n, count, start);
	}

	int M = 0;
	for(int i=1;i<=n;i++)
		M = max(M, count[i]);
	for(int i=1;i<=n;i++)
		if(count[i]==M)
			cout << i << " ";

	return 0;
}
void dfs(vector<vector<int> > &graph, bool* visited, int now, int n, int* count, int start)
{
	if(visited[now])
		return;
	visited[now] = true;
	count[start]++;
	for(int i=0;i<(int)graph[now].size();i++)
	{
		int next = graph[now][i];
		dfs(graph, visited, next, n, count, start);
	}
}
