//중심음을 찾아 가단조와 다장조를 찾기

#include <iostream>

using namespace std;

int main()
{
	string s;
	cin >> s;
	int ga_long=0, da_short=0;
	for(int i=0;i<(int)s.size();i++)
	{
		if(s[i-1]=='|'||i==0)
		{
			if(s[i]=='A'||s[i]=='D'||s[i]=='E')
				ga_long++;
			else if(s[i]=='C'||s[i]=='F'||s[i]=='G')
				da_short++;
		}
	}
	if(ga_long>da_short)
		cout << "A-minor";
	else if(ga_long<da_short)
		cout << "C-major";
	else
	{
		int i = s.size()-1;
		while(s[i]=='B')
			i--;
		if(s[i]=='A'||s[i]=='D'||s[i]=='E')
			cout << "A-minor";
		else if(s[i]=='C'||s[i]=='F'||s[i]=='G')
			cout << "C-major";
	}

	return 0;
}
