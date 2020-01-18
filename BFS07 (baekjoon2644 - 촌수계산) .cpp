//가계도를 입력받아 두사람의 촌수를 구하는 문제 (구할 수 없으면 -1을 출력한다)
//기본적인 bfs문제

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int bfs(vector<vector<int> > &graph, bool* visited, int n, int start, int finish);
int main()
{
	int n, a, b, m;
	cin >> n >> a >> b >> m;

	vector<vector<int> > graph(n+1);
	while(m--)
	{
		int p1, p2;
		cin >> p1 >> p2;
		graph[p1].push_back(p2);
		graph[p2].push_back(p1);
	}

	bool visited[n+1] = {};
	cout << bfs(graph, visited, n, a, b);

	return 0;
}

int bfs(vector<vector<int> > &graph, bool* visited, int n, int start, int finish)
{
	queue<pair<int , int> > Q;
	Q.push({start, 0});

	while(!Q.empty())
	{
		int m = Q.front().first;
		int c = Q.front().second;
		Q.pop();
		visited[m] = true;
		if(m==finish)
			return c;

		for(int i=0;i<(int)graph[m].size();i++)
		{
			int w = graph[m][i];
			if(visited[w])
				continue;
			visited[w] = true;
			Q.push({w, c+1});
		}
	}
	return -1;
}

