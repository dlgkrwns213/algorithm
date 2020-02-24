#include <iostream>

using namespace std;

int main()
{
	string s;
	cin >> s;
	string ss = s;

	int first=0;
	for(int i=1;i<(int)s.size();i++)
	{
		int tmp = 0;
		if(s[i]=='*')
		{
			tmp = (s[i-1]-'0')*(s[i+1]-'0');
			s[i-1] = '0';
			s[i+1] = '0';
			while(s[i+2]=='*')
			{
				i+=2;
				tmp *= s[i+1]-'0';
				s[i+1] = '0';
			}
		}
		first+=tmp;
	}
	for(int i=0;i<(int)s.size();i++)
	{
		if(s[i]>='0'&&s[i]<='9')
			first += s[i]-'0';
	}

	ss.push_back('.');
	int second = ss[0]-'0';
	for(int i=1;ss[i]!='.';i++)
	{
		if(ss[i]=='+')
			second+=ss[i+1]-'0';
		else if(ss[i]=='*')
			second*=ss[i+1]-'0';
		i++;
	}

	int ans;
	cin >> ans;
	if(first==ans&&second==ans)
		cout << "U";
	else if(first==ans)
		cout << "M";
	else if(second==ans)
		cout << "L";
	else
		cout << "I";
}
