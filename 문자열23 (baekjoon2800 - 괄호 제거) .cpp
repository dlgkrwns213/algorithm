#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

struct Parentheses
{
	int open, close;
};

string make2(int vs, int n);
int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	string s;
	cin >> s;

	vector<Parentheses> vp;
	stack<int> tmp;
	for(int i=0;i<(int)s.size();i++)
	{
		if(s[i]=='(')
			tmp.push(i);
		else if(s[i]==')')
		{
			vp.push_back({tmp.top(), i});
			tmp.pop();
		}
	}

	int vs = (int)vp.size();
	int count = 1;
	for(int i=0;i<vs;i++)
		count*=2;
	count--;

	vector<string> ans;
	for(int i=1;i<=count;i++)
	{
		string two = make2(vs, i);
		bool no[200] = {};
		for(int i=0;i<vs;i++)
			if(two[i]=='1')
			{
				no[vp[i].open] = true;
				no[vp[i].close] = true;
			}

		string add;
		for(int j=0;j<(int)s.size();j++)
		{
			if(!no[j])
				add.push_back(s[j]);
		}
		ans.push_back(add);
	}

	sort(ans.begin(), ans.end());
	cout << ans[0] << "\n";
	for(int i=1;i<count;i++)
		if(ans[i]!=ans[i-1])
		cout << ans[i] << "\n";
}

string make2(int vs, int n)
{
	string tmps, s;
	while(n>0)
	{
		tmps.push_back(n%2+'0');
		n/=2;
	}
	for(int i=0;i<vs;i++)
		tmps.push_back('0');
	for(int i=0;i<vs;i++)
		s.push_back(tmps[i]);
	return s;
}
