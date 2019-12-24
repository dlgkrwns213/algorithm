// baekjoon1181 - 단어 정렬
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool Sbigger(const string &s1, const string &s2)
{
	if(s1.size()==s2.size())
	{
		int i=0;
		while(1)
		{
			if(s1[i]!=s2[i])
				return s1[i]<s2[i];
			i++;
		}
	}
	return s1.size()<s2.size();
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;

	vector<string> s;
	for(int i=0;i<n;i++)
	{
		string tmps;
		cin >> tmps;
		bool same = false;
		for(int j=0;j<(int)s.size();j++)
			if(s[j]==tmps)
			{
				same = true;
				break;
			}
		if(!same)
			s.push_back(tmps);
	}

	sort(s.begin(), s.end(), Sbigger);

	for(int i=0;i<(int)s.size();i++)
		cout << s[i] << "\n";

	return 0;
}

// baekjoon11651 - 좌표정렬하기2
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct XY
{
	int x;
	int y;
};

bool XYbigger(const XY &xy1, const XY &xy2)
{
	if(xy1.y==xy2.y)
		return xy1.x<xy2.x;
	return xy1.y<xy2.y;
}

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;

	vector<XY> xy;
	for(int i=0;i<n;i++)
	{
		int x, y;
		cin >> x >> y;
		xy.push_back({x, y});
	}
	sort(xy.begin(), xy.end(), XYbigger);

	for(int i=0;i<n;i++)
		cout << xy[i].x << " " << xy[i].y << "\n";

	return 0;
}
