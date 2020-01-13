//평문을 암호키에 따라 암호문으로 바꿔주는 문제
//단 빈칸은 빈칸으로 바꿔준다
//getline으로 입력받은 경우 공백은 ' '값이 된다
#include <iostream>

using namespace std;

int main()
{
	string s, key;
	getline(cin, s);
	getline(cin, key);

	for(int i=0, j=0;i<(int)s.size();i++)
	{
		if(s[i]!=' ')
		{
			s[i] -= key[j]-'a'+1;
			if(s[i]<'a')
				s[i]+=26;
		}
		cout << s[i];
		j++;
		if(j==(int)key.size())
			j=0;
	}
	return 0;
}
