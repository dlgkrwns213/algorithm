//java : 처음 글자는 소문자, 나머지는 소문자 or 대문자
//c++ : 처음 글자는 소문자, 나머지는 소문자 or _
//java와 c++둘다 아닐 경우 에러 출력, 둘 중 하나일 경우 나머지 변수명으로 바꾸어주기

#include <iostream>

using namespace std;

int main()
{
	bool c_plus = true;
	bool java = true;
	string s;
	cin >> s;
	for(int i=0;i<(int)s.size();i++)
	{
		if(!(('a'<=s[i]&&s[i]<='z')||s[i]=='_'))
			c_plus = false;
		if((i>0&&s[i]=='_'&&s[i-1]=='_')||s[s.size()-1]=='_'||s[0]=='_')
			c_plus = false;
		if(!(('a'<=s[i]&&s[i]<='z')||('A'<=s[i]&&s[i]<='Z'))||!('a'<=s[0]&&s[0]<='z'))
			java = false;
	}
	if(!c_plus&&!java)
		cout << "Error!";
	else if(java)
	{
		string cs;
		for(int i=0;i<(int)s.size();i++)
		{
			if('A'<=s[i]&&s[i]<='Z')
			{
				cs.push_back('_');
				cs.push_back(s[i]+32); //대문자->소문자
			}
			else
				cs.push_back(s[i]);
		}
		cout << cs;
	}
	else if(c_plus)
	{
		string js;
		for(int i=0;i<(int)s.size();i++)
		{
			if(s[i]=='_')
			{
				js.push_back(s[i+1]-32);
				i++;
			}
			else
				js.push_back(s[i]);
		}
		cout << js;
	}
	return 0;
}
