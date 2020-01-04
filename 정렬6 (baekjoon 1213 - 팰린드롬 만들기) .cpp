//문자열을 정렬 후에 각 문자들이 짝수개씩 있나 확인한 후 홀수 개가 한개를 초과하여 나타날 경우 팰린드롬을 만들지 못함을 표시해준다.
//한개 이하일 경우 한개는 중간에 써주고, 나머지 문자들은 벡터에 저장후에 순서대로 출력하고, 다시 역순으로 한번 더 출력해준다.
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool compare(const char &c1, const char &c2)
{
	return c1<c2;
}
int main()
{
	string s;
	cin >> s;

	sort(s.begin(), s.end());

	vector<char> vc;
	int ss = (int)s.size();
	bool can = true;
	bool one = false;
	char co = '\0';
	int n = ss;
	int i = 0;
	while(n>i)
	{
		if(s[i]==s[i+1])
		{
			vc.push_back(s[i]);
			i+=2;
		}
		else if(!one)
		{
			co = s[i];
			one = true;
			i++;
		}
		else
		{
			can = false;
			break;
		}
	}


	if(!can)
		cout << "I'm Sorry Hansoo";
	else
	{
		int vcs = (int)vc.size();
		for(int i=0;i<vcs;i++)
			cout << vc[i];
		if(co!='\0')
			cout << co;
		for(int i=vcs-1;i>=0;i--)
			cout << vc[i];
	}
	return 0;
}
