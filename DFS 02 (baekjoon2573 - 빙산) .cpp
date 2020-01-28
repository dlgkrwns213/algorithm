//dfs를 이용하여 빙산의 크기가 두개 이상이 되는 해를 구하는 문제

#include <iostream>

using namespace std;
#define MAX 300

int go_i[4] = {0, 1, 0, -1};
int go_j[4] = {1, 0, -1, 0};
int map[MAX][MAX];
void dfs(int i, int j, int n, int m, bool visited[][MAX]);
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

	int year = 0;
	while(1)
	{
		int count = 0;
		bool b = true;
		bool visited[n][MAX] = {};
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++)
			{
				if(map[i][j]!=0)
					b = false;
				if(!visited[i][j]&&map[i][j]!=0)
				{
					count++;
					dfs(i, j, n, m, visited);
				}
			}

		if(b)
		{
			year = 0;
			break;
		}
		if(count>1)
			break;
		year++;

		int minus[n][m] = {};
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++)
			{
				if(map[i][j]!=0)
				{
					int zc = 0;
					for(int k=0;k<4;k++)
					{
						int I = i+go_i[k];
						int J = j+go_j[k];
						if(I<0||J<0||I>=n||j>=m)
							continue;
						if(map[I][J]==0)
							zc++;
					}
					minus[i][j] = zc;
				}
			}

		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++)
			{
				map[i][j]-=minus[i][j];
				if(map[i][j]<0)
					map[i][j] = 0;
			}
	}
	cout << year;
	return 0;
}

void dfs(int i, int j, int n, int m, bool visited[][MAX])
{
	if(i<0||j<0||i>=n||j>=m)
		return;
	if(visited[i][j])
		return;
	if(map[i][j]==0)
		return;

	visited[i][j] = true;
	for(int k=0;k<4;k++)
	{
		int I = i+go_i[k];
		int J = j+go_j[k];
		dfs(I, J, n, m, visited);
	}
}
