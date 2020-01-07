//vector와 pair를 이용하여 알파벳과 그 알파벳의 값을 저장하고 
//sort를 이용하여 정렬 한 후 
//차례대로 9부터 순차적으로 값을 입력받아 최댓값을 구해준다.

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(const pair<int, char> &p1, const pair<int, char> &p2)
{
	if(p1.first==p2.first)
		return p1.second>p2.second;
	return p1.first>p2.first;
}

int main()
{
	int n;
	cin >> n;

	string s[n];
	vector<pair<int, char> > alpha;
	for(int i=0;i<n;i++)
	{
		cin >> s[i];
		int r = 1;
		for(int j=(int)s[i].size()-1;j>=0;j--)
		{
			bool yes = false;
			int k;
			for(k=0;k<(int)alpha.size();k++)
			{
				if(alpha[k].second==s[i][j])
				{
					yes = true;
					break;
				}
			}
			if(yes)
			{
				alpha[k].first += r;
			}
			else
			{
				alpha.push_back({r, s[i][j]});
			}
			r*=10;
		}
	}

	sort(alpha.begin(), alpha.end(), compare);

	int count = 0;
	int nine = 9;
	for(int i=0;i<(int)alpha.size();i++)
	{
		count += alpha[i].first*nine;
		nine--;
	}
	cout << count;

}
