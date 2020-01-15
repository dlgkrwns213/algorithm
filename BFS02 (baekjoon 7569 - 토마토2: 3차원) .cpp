//토마토 와 같은 유형의 문제이지만 3차원의 공간을 입력받아 만들어준다. - 3차형배열을 전역변수로 사용함
#include <iostream>
#include <vector>
#include <queue>

using namespace std;
#define MAX 100
struct XYZ
{
	int x, y, z;
};
XYZ go_xyz[6] = {{0, 0, -1},{0, 0, 1},{0, -1, 0},{0, 1, 0},{-1, 0, 0},{1, 0, 0}};


int tomato[MAX][MAX][MAX];
bool visited[MAX][MAX][MAX];
void bfs(vector<XYZ> &xyz, int x, int y, int z, vector<int> &days);

int main()
{
	int x, y, z;
	cin >> x >> y >> z;
	vector<XYZ> xyz;
	for(int i=0;i<z;i++)
		for(int j=0;j<y;j++)
			for(int k=0;k<x;k++)
			{
				visited[k][j][i] = false;
				int ts;
				cin >> ts;
				tomato[k][j][i] = ts;
				if(ts==1)
					xyz.push_back({k, j, i});
				if(ts==-1)
					visited[k][j][i] = true;
			}

	vector<int> days;
	bfs(xyz, x, y, z, days);

	for(int i=0;i<z;i++)
		for(int j=0;j<y;j++)
			for(int k=0;k<x;k++)
				if(!visited[k][j][i])
				{
					cout << -1;
					return 0;
				}
	cout << days.back();
	return 0;
}

void bfs(vector<XYZ> &xyz, int X, int Y, int Z, vector<int> &days)
{
	queue<pair<XYZ, int> > Q;
	for(int i=0;i<(int)xyz.size();i++)
	{
		int x = xyz[i].x;
		int y = xyz[i].y;
		int z = xyz[i].z;
		Q.push({{x, y, z}, 0});
		visited[x][y][z] = true;
	}

	while(!Q.empty())
	{
		int x = Q.front().first.x;
		int y = Q.front().first.y;
		int z = Q.front().first.z;
		int day = Q.front().second;
		Q.pop();
		days.push_back(day);
		for(int i=0;i<6;i++)
		{
			int new_x = x+go_xyz[i].x;
			int new_y = y+go_xyz[i].y;
			int new_z = z+go_xyz[i].z;
			if(new_x>=X||new_x<0||new_y>=Y||new_y<0||new_z>=Z||new_z<0)
				continue;
			if(visited[new_x][new_y][new_z])
				continue;
			if(tomato[new_x][new_y][new_z]==1)
				continue;
			visited[new_x][new_y][new_z] = true;
			Q.push({{new_x, new_y, new_z}, day+1});
		}
	}
}
