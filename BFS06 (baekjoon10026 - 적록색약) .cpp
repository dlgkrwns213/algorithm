//bfs함수를 두번 이용하여 적록색약일 경우 'G'를 'R'로 바꿔서 함수를 돌려 count값을 구해준다

#include <iostream>
#include <vector>
#include <queue>

using namespace std;
#define MAX 100
char picture[MAX][MAX];
void bfs(bool visited[][MAX], int n, int i, int j);
int main()
{
	int n;
	cin >> n;

	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			cin >> picture[i][j];
	bool visited[n][MAX] = {};
	int count = 0;
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			if(!visited[i][j])
			{
				count++;
				bfs(visited, n, i, j);
			}

	for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				if(picture[i][j]=='G')
					picture[i][j] = 'R';
	bool gr_visited[n][MAX] = {};
	int gr_count = 0;
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			if(!gr_visited[i][j])
			{
				gr_count++;
				bfs(gr_visited, n, i, j);
			}

	cout << count << " " << gr_count;
	return 0;
}
void bfs(bool visited[][MAX], int n, int i, int j)
{
	int go_i[4] = {0, 1, 0, -1};
	int go_j[4] = {1, 0, -1, 0};
	queue<pair<int, int> > Q;
	Q.push({i, j});

	while(!Q.empty())
	{
		int I = Q.front().first;
		int J = Q.front().second;
		Q.pop();

		for(int k=0;k<4;k++)
		{
			int new_i = I+go_i[k];
			int new_j = J+go_j[k];

			if(new_i<0||new_j<0||new_i>=n||new_j>=n)
				continue;
			if(visited[new_i][new_j])
				continue;
			if(picture[I][J]!=picture[new_i][new_j])
				continue;
			visited[new_i][new_j] = true;
			Q.push({new_i, new_j});
		}
	}
}
