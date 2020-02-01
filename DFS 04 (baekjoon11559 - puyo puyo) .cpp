//dfs를 이용하여 연결된 개수를 찾고 4개이상이 되면 없애준 후 몇번 연속 가능한지 구해주는 문제

#include <iostream>

using namespace std;

char map[12][6];
void dfs(int i, int j, int& c, bool find[][6], char alpha);
int main()
{
	for(int i=0;i<12;i++)
		for(int j=0;j<6;j++)
			cin >> map[i][j];

	int count = 0;
	while(1)
	{
		bool boom = false;
		for(int i=0;i<12;i++)
			for(int j=0;j<6;j++)
				if(map[i][j]!='.')
				{
					bool find[12][6] = {};
					int c = 0;
					dfs(i, j, c, find, map[i][j]);

					if(c>=4)
					{
						for(int i=0;i<12;i++)
							for(int j=0;j<6;j++)
								if(find[i][j])
									map[i][j] = '.';
						boom = true;
					}
				}
		if(!boom)
			break;
		count++;

		for(int j=0;j<6;j++)
			for(int i=11;i>=0;i--)
				if(map[i][j]!='.')
					for(int k=11;k>i;k--)
						if(map[k][j]=='.')
						{
							swap(map[i][j], map[k][j]);
							break;
						}

	}

	cout << count;
}

void dfs(int i, int j, int& c, bool find[][6], char alpha)
{
	if(find[i][j])
		return;
	int go_i[4] = {0, 1, 0, -1};
	int go_j[4] = {1, 0, -1, 0};
	c++;
	find[i][j] = true;

	for(int k=0;k<4;k++)
	{
		int I = i+go_i[k];
		int J = j+go_j[k];
		if(I<0||J<0||I>=12||J>=6)
			continue;
		if(map[I][J]==alpha)
			dfs(I, J, c, find, alpha);
	}
}
