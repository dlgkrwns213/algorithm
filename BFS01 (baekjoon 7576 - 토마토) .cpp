//bfs를 이용하여 토마토가 모두 익을때까지의 시간 구하기
#include <iostream>
#include <vector>
#include <queue>

using namespace std;
#define MAX 1000

struct XY
{
	int x, y;
};

void bfs(int tomato[][MAX], bool visited[][MAX], vector<XY> &xy, int m, int n, vector<int> &day);

int main()
{
	int n, m;
	cin >> n >> m;

	vector<XY> xy;
	int tomato[m][MAX];
	bool visited[m][MAX] = {};
	for(int j=0;j<m;j++)
		for(int i=0;i<n;i++)
		{
			cin >> tomato[j][i];
			if(tomato[j][i]==1)
			{
				xy.push_back({i, j});
			}
			if(tomato[j][i]==-1)
				visited[j][i] = true;
		}

	vector<int> day;
	bfs(tomato, visited, xy, m, n, day);

	bool all_visited = true;
	for(int j=0;j<m;j++)
		for(int i=0;i<n;i++)
			if(!visited[j][i])
				all_visited = false;

	if(all_visited)
		cout << day.back();
	else
		cout << -1;

	return 0;
}

void bfs(int tomato[][MAX], bool visited[][MAX], vector<XY> &xy, int m, int n, vector<int> &days)
{
	int go_x[4] = {-1, 0, 1, 0};
	int go_y[4] = {0, -1, 0, 1};
	queue<pair<pair<int, int>, int> > Q;
	for(int i=0;i<(int)xy.size();i++)
	{
		int x = xy[i].x;
		int y = xy[i].y;
		Q.push({{x, y}, 0});
		visited[y][x] = true;
	}

	while(!Q.empty())
	{
		int x = Q.front().first.first;
		int y = Q.front().first.second;
		int day = Q.front().second;
		Q.pop();
		days.push_back(day);
		for(int i=0;i<4;i++)
		{
			int new_x = x+go_x[i];
			int new_y = y+go_y[i];
			if(new_x>=n||new_x<0||new_y>=m||new_y<0)
				continue;
			if(visited[new_y][new_x])
				continue;
			if(tomato[new_y][new_x]==1)
				continue;
			visited[new_y][new_x] = true;
			Q.push({{new_x, new_y}, day+1});
		}
	}

}
