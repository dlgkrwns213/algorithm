#include <iostream>
#include <vector>

using namespace std;

void dfs(vector<vector<int> > graph, int now, int n, bool* tmp, bool &circle);
int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	int n;
	cin >> n;
	vector<vector<int> > graph(n+1);
	for(int i=1;i<=n;i++)
	{
		int k;
		cin >> k;
		graph[k].push_back(i);
	}

	bool no[n+1] = {};
	for(int i=1;i<=n;i++)
	{
		bool tmp[n+1] = {};
		bool circle = false;
		dfs(graph, i, n, tmp, circle);
		if(!circle)
			no[i] = true;
	}


	int sum = 0;
	for(int i=1;i<=n;i++)
		sum+=!no[i];
	cout << sum << "\n";
	for(int i=1;i<=n;i++)
		if(!no[i])
			cout << i << "\n";
}


void dfs(vector<vector<int> > graph, int now, int n, bool* tmp, bool &circle)
{
	if(tmp[now])
		return;
	tmp[now] = true;

	for(int i=0;i<(int)graph[now].size();i++)
	{
		int next = graph[now][i];
		if(tmp[next]==true)
		{
			circle = true;
			return;
		}
		dfs(graph, next, n, tmp, circle);
	}
}
