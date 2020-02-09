#include <iostream>
#include <queue>

using namespace std;
#define MAX 301

struct IJ
{
	int i, j;
};
int map[MAX][MAX], ptr=0;
bool visited[MAX][MAX] = {};
void bfs(int n, int m);
int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;

	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			cin >> map[i][j];

	bfs(n, m);
	cout << ptr;
}

void bfs(int n, int m)
{
	int go_i[4] = {0, 1};
	int go_j[4] = {1, 0};

	queue<pair<IJ, int> > Q;
	Q.push({{0, 0}, 0});
	visited[0][0] = true;
	while(!Q.empty())
	{
		int I = Q.front().first.i;
		int J = Q.front().first.j;
		int w = Q.front().second;
		Q.pop();

		if(I==n-1&&J==m-1)
		{
			ptr = w;
			return;
		}
		visited[I][J] = true;

		for(int k=1;k<=map[I][J];k++)
			for(int f=0;f<2;f++)
			{
				int new_i = I+go_i[f]*k;
				int new_j = J+go_j[f]*k;

				if(new_i<0||new_j<0||new_i>=n||new_j>=m)
					continue;
				if(visited[new_i][new_j])
					continue;

				visited[new_i][new_j] = true;
				Q.push({{new_i, new_j}, w+1});
			}
	}
}
