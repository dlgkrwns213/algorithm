#include <iostream>

using namespace std;

int mod(string s, int n)
{
	int r = 0;
	for(int i=0;i<(int)s.size();i++)
		r = (r*10+s[i]-'0')%n;
	return r;
}
int main()
{
	string s;
	cin >> s;
	int k;
	cin >> k;

	bool good = true;
	int i;
	for(i=2;i<k;i++)
	{
		if(mod(s, i)==0)
		{
			good = false;
			break;
		}
	}
	if(good)
		cout << "GOOD";
	else
		cout << "BAD " << i;
}
