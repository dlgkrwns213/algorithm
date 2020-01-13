//*이 한개있는 string을 입력받고 *이 있는 곳은 아무 문자나 들어갈수 있다고 설정해준다.
//각 줄마다 들어오는 string이 *이 있는 string으로 표현될 수 있는 확인해보기
#include <iostream>

using namespace std;

int main()
{
	int n;
	string pt;
	cin >> n >> pt;
	while(n--)
	{
		string s;
		cin >> s;
		int ps = (int)pt.size();
		int ss = (int)s.size();
		bool yes = true;
		if(ps-1>ss)
			yes = false;
		for(int i=0;i<ps;i++)
		{
			if(pt[i]=='*')
				break;
			if(pt[i]!=s[i])
			{
				yes = false;
				break;
			}
		}
		for(int i=0;i<ps;i++)
		{
			if(pt[ps-i]=='*')
				break;
			if(pt[ps-i]!=s[ss-i])
			{
				yes = false;
				break;
			}
		}
		if(yes)
			cout << "DA" << endl;
		else
			cout << "NE" << endl;
	}
	return 0;
}
