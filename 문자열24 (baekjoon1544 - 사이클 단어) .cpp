#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

string cycle(string s, int k)
{
	string ns;
	for(int i=k;i<(int)s.size();i++)
		ns.push_back(s[i]);
	for(int i=0;i<k;i++)
		ns.push_back(s[i]);
	return  ns;
}
int main()
{
	int n;
	cin >> n;
	vector<string> vs;
	for(int i=0;i<n;i++)
	{
		string s;
		cin >> s;

		bool same = false;
		for(int j=0;j<(int)vs.size();j++)
			for(int i=0;i<(int)s.size();i++)
				if(cycle(s, i)==vs[j])
				{
					same = true;
					break;
				}
		if(!same)
			vs.push_back(s);
	}
	cout << vs.size();
	return 0;
}
