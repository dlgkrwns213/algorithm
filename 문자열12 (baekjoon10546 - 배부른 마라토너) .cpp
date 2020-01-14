//마라토너중에서 단 한명의 낙오자를 출력해주기
//마라토너를 입력받고 정렬시켜준 후 vector를 통해 이름과 동명이인의 수를 기록해준다.
//이진탐색을 통해 통과한 마라토너의 수를 줄여주고 0이 되지 못한 마라토너의 이름을 출력해준다.

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;

	string maratoner[n];
	for(int i=0;i<n;i++)
		cin >> maratoner[i];
	sort(maratoner, maratoner+n);
	vector<pair<string, int> > graph;
	graph.push_back({maratoner[0], 1});
	for(int i=1;i<n;i++)
	{
		if(maratoner[i]==maratoner[i-1])
			graph.back().second++;
		else
			graph.push_back({maratoner[i], 1});
	}

	for(int i=0;i<n-1;i++)
	{
		string perfect;
		cin >> perfect;
		int start = 0;
		int last = n-1;
		while(start<=last)
		{
			int mid = (start+last)/2;
			if(perfect>graph[mid].first)
				start = mid+1;
			else if(perfect<graph[mid].first)
				last = mid-1;
			else
			{
				graph[mid].second--;
				break;
			}
		}
	}
	for(int i=0;i<(int)graph.size();i++)
		if(graph[i].second!=0)
		{
			cout << graph[i].first;
			break;
		}
	return 0;
}
