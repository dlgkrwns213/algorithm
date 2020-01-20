//성씨가 5명이상 같을 경우 경기에 내보낼때 경기에 나갈수 있는 성씨를 구하는 문제
//vector를 이용하여 성씨를 구하여 정렬한 뒤 5명 이상이면 출력해준다.
//pair<char, int>를 벡터의 템플릿값으로 설정했는데 sort할 경우 알아서 char순서로 정렬되었다.

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<pair<char, int> > p;
	while(n--)
	{
		string s;
		cin >> s;

		char c = s[0];
		bool yes = false;
		for(int i=0;i<(int)p.size();i++)
			if(p[i].first==c)
			{
				p[i].second++;
				yes = true;
			}
		if(!yes)
			p.push_back({c, 1});
	}
	sort(p.begin(), p.end());

	bool no = true;
	for(int i=0;i<(int)p.size();i++)
		if(p[i].second>=5)
		{
			no = false;
			cout << p[i].first;
		}
	if(no)
		cout << "PREDAJA";
	return 0;
}
