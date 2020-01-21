//vector를 이용하여 사람수의 관계를 입력받아 그래프를 만들어주고
//이중 for문을 통해 친구와 그 친구의 친구까지 초대를 할수 있도록 해준다 (bool배열을 사용)

#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;

	vector<vector<int> > graph(n+1);
	while(m--)
	{
		int f1, f2;
		cin >> f1 >> f2;
		graph[f1].push_back(f2);
		graph[f2].push_back(f1);
	}
	bool visited[n+1] = {};
	for(int i=0;i<(int)graph[1].size();i++)
	{
		int k = graph[1][i];
		visited[k] = true;
		for(int j=0;j<(int)graph[k].size();j++)
		{
			int w = graph[k][j];
			visited[w] = true;
		}
	}

	int count = 0;
	for(int i=2;i<=n;i++)
		if(visited[i])
			count++;

	cout << count;
}
