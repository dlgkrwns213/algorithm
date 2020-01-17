//나이트가 시작지점부터 최종지점까지 갈수 있는 최단 횟수를 구하여 출력하는 문제
//bfs를 이용하고 나이트가 이동할수 있는 곳을 다음 위치로 선정해준다.

#include <iostream>
#include <vector>
#include <queue>

using namespace std;
#define MAX 300

struct IJ
{
	int i, j;
};
void bfs(int n, bool visited[][MAX], int i, int j, IJ finish);

int main()
{
	int T;
	cin >> T;
	while(T--)
	{
		int n;
		cin >> n;

		IJ start, finish;
		cin >> start.i >> start.j >> finish.i >> finish.j;
		bool visited[n][MAX] = {};
		bfs(n, visited, start.i, start.j, finish);
	}
	return 0;
}

void bfs(int n, bool visited[][MAX], int i, int j, IJ finish)
{
	int go_i[8] = {1, 2, 2, 1, -1, -2, -2, -1};
	int go_j[8] = {2, 1, -1, -2, -2, -1, 1, 2};
	queue<pair<IJ , int> > Q;
	Q.push({{i, j}, 0});

	while(!Q.empty())
	{
		int I = Q.front().first.i;
		int J = Q.front().first.j;
		int c = Q.front().second;
		Q.pop();
		if(I==finish.i&&J==finish.j)
		{
			cout << c << endl;
			return;
		}
		visited[I][J] = true;

		for(int k=0;k<8;k++)
		{
			int new_i = I+go_i[k];
			int new_j = J+go_j[k];
			if(new_i<0||new_j<0||new_i>=n||new_j>=n)
				continue;
			if(visited[new_i][new_j])
				continue;
			visited[new_i][new_j] = true;
			Q.push({{new_i, new_j}, c+1});
		}
	}
}
