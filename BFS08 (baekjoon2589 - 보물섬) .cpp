//지도가 주어졌을 때 육지로만으로 이동이 가장 먼 두곳에 보물이 묻혀있다. 이때 두 보물의 떨어진 거리를 구하기
//모든 육지마다 거리를 구해서 계산해준다.

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
#define MAX 50

int dfs(char map[][MAX], bool visited[][MAX], int n, int m, int i, int j);
int main()
{
	int n, m;
	cin >> n >> m;

	char map[n][MAX];
	int l_count = 0;
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
		{
			cin >> map[i][j];
			if(map[i][j]=='L')
				l_count++;
		}

	vector<int> how;
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			if(map[i][j]=='L')
			{
				bool visited[n][MAX] = {};
				how.push_back(dfs(map, visited, n, m, i, j));
			}
	cout << *max_element(how.begin(), how.end());

	return 0;
}

int dfs(char map[][MAX], bool visited[][MAX], int n, int m, int i, int j)
{
	int go_i[4] = {0, 1, 0, -1};
	int go_j[4] = {1, 0, -1, 0};
	queue<pair<pair<int, int>, int> > Q;
	Q.push({{i, j}, 0});

	int c;
	while(!Q.empty())
	{
		int I = Q.front().first.first;
		int J = Q.front().first.second;
		c = Q.front().second;
		visited[I][J] = true;
		Q.pop();

		for(int k=0;k<4;k++)
		{
			int new_i = I+go_i[k];
			int new_j = J+go_j[k];
			if(new_i<0||new_j<0||new_i>=n||new_j>=m)
				continue;
			if(visited[new_i][new_j])
				continue;
			if(map[new_i][new_j]=='W')
				continue;

			visited[new_i][new_j] = true;
			Q.push({{new_i, new_j}, c+1});
		}
	}
	return c;
}
