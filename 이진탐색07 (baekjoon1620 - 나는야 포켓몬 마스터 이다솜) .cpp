//pair로 index를 같이 저장하여 index가 입력되면 string값을, string값을 입력받으면 index값을 가져오는 문제
#include <iostream>
#include <algorithm>

using namespace std;

bool compares(const pair<string, int> &p1, const pair<string, int> &p2)
{
	return p1.first<p2.first;
}
int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;

	string pocketi[n];
	pair<string, int> pockets[n];
	for(int i=0;i<n;i++)
	{
		string s;
		cin >> s;
		pocketi[i] = s;
		pockets[i] = {s, i+1};
	}

	sort(pockets, pockets+n, compares);

	for(int i=0;i<m;i++)
	{
		string tmp;
		cin >> tmp;
		if('0'<=tmp[0]&&tmp[0]<='9')
		{
			int index = stoi(tmp);
			cout << pocketi[index-1] << "\n";
		}
		else
		{
			int first = 0;
			int last = n-1;
			while(first<=last)
			{
				int mid = (first+last)/2;
				if(pockets[mid].first>tmp)
					last = mid-1;
				else if(pockets[mid].first<tmp)
					first = mid+1;
				else
				{
					cout << pockets[mid].second << "\n";
					break;
				}
			}
		}
	}
	return 0;
}
