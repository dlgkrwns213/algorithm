//수면의 값을 설정하여 가장 섬이 많을때의 섬의 개수를 구하는 문제

#include <iostream>

using namespace std;
#define MAX 100

int map[MAX][MAX];
void dfs(int i, int j, int n, int water, bool visited[][MAX]);
int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	int n;
	cin >> n;

	int m=100, M=0;
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
		{
			cin >> map[i][j];
			m = min(m, map[i][j]);
			M = max(M, map[i][j]);
		}

	int count = 1;
	for(int k=m;k<=M;k++)
	{
		bool visited[n][MAX] = {};
		int c = 0;
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				if(!visited[i][j]&&map[i][j]>k)
				{
					c++;
					dfs(i, j, n, k, visited);
				}
		count = max(count, c);
	}
	cout << count;
}

void dfs(int i, int j, int n, int water, bool visited[][MAX])
{
	if(i<0||j<0||i>=n||j>=n)
		return;
	if(visited[i][j])
		return;
	if(map[i][j]<=water)
		return;

	int go_i[4] = {0, 1, 0, -1};
	int go_j[4] = {1, 0, -1, 0};
	visited[i][j] = true;
	for(int k=0;k<4;k++)
	{
		int I = i+go_i[k];
		int J = j+go_j[k];
		dfs(I, J, n, water, visited);
	}
}
