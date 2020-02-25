#include <iostream>
#include <vector>

using namespace std;

struct txt
{
	char c;
	int time;
};

int main()
{
	int n;
	cin >> n;

	string s;
	vector<txt> v;
	vector<pair<int, int> > undo;
	for(int i=0;i<n;i++)
	{
		cin >> s;
		int time;
		if(s=="type")
		{
			char c;
			cin >> c >> time;
			v.push_back({c, time});
		}
		else if(s=="undo")
		{
			int how;
			cin >> how >> time;
			undo.push_back({how, time});
		}
	}
	for(int i=(int)undo.size()-1;i>=0;i--)
	{
		if(undo[i].first!=-1)
		{
			int t = undo[i].second - undo[i].first;
			for(int j=i-1;j>=0;j--)
			{
				if(undo[j].second>=t)
					undo[j].first = undo[j].second = -1;
			}
		}
	}
	for(int i=(int)undo.size()-1;i>=0;i--)
	{
		if(undo[i].first!=-1)
		{
			int t = undo[i].second - undo[i].first;
			for(int j=0;j<(int)v.size();j++)
				if(v[j].time>=t&&v[j].time<undo[i].second)
					v[j].c = '0';
		}
	}

	for(int i=0;i<(int)v.size();i++)
		if(v[i].c!='0')
			cout << v[i].c;
}
