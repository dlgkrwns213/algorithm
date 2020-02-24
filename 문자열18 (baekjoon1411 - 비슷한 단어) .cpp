#include <iostream>
#include <vector>

using namespace std;

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	vector<pair<string, int> > v;
	for(int i=0;i<n;i++)
	{
		string ss;
		cin >> ss;

		int alpha[26];
		for(int i=0;i<26;i++)
			alpha[i] = -1;
		int start = 0;
		for(int j=0;j<(int)ss.size();j++)
		{
			int index = ss[j]-'a';
			if(alpha[index]==-1)
			{
				alpha[index] = start;
				start++;
			}
		}
		string s=ss;
		for(int j=0;j<(int)s.size();j++)
			s[j] = alpha[ss[j]-'a']+'A';
		//cout << s << endl;

		bool same = false;
		for(int j=0;j<(int)v.size();j++)
			if(s==v[j].first)
			{
				same = true;
				v[j].second++;
				break;
			}

		if(!same)
			v.push_back({s, 1});
	}

	/*cout << endl;
	for(int i=0;i<(int)v.size();i++)
		cout << v[i].first << " " << v[i].second << endl;
	cout << endl;*/

	int sum = 0;
	for(int i=0;i<(int)v.size();i++)
	{
		int vi = v[i].second;
		sum += ((vi-1)*vi)/2;
	}
	cout << sum;
}
