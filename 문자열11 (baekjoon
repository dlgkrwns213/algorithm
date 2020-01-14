//고장난 폰을 이용하여 원하는 string 값을 출력하기 위해 버튼을 어떻게 눌러야하는지 구하는 문제
//n번키를 누를경우 k번키가 작동되는것을 역으로 k번이 눌리기 위해 i를 누르는 형식으로 num값을 저장해준다.
//string을 만들기 위해 원래 누르는 방법을 계산하고 다시 고장난 방법으로 원래 방법을 구하는 문자값을 계산해주어 출력해준다.


#include <iostream>
#include <vector>

using namespace std;

string finals;
void make(string s);
void numbering(int* num);

int main()
{
	int num[9];
	for(int i=1;i<10;i++)
	{
		int tmp;
		cin >> tmp;
		num[tmp] = i;
	}
	string s;
	cin >> s;
	make(s);
	numbering(num);
	cout << finals;
	return 0;
}

void make(string s)
{
	for(int i=0;i<(int)s.size();i++)
	{
		char tmps;
		int num;
		if(s[i]=='a')
			tmps = '2', num = 1;
		else if(s[i]=='b')
			tmps = '2', num = 2;
		else if(s[i]=='c')
			tmps = '2', num = 3;
		else if(s[i]=='d')
			tmps = '3', num = 1;
		else if(s[i]=='e')
			tmps = '3', num = 2;
		else if(s[i]=='f')
			tmps = '3', num = 3;
		else if(s[i]=='g')
			tmps = '4', num = 1;
		else if(s[i]=='h')
			tmps = '4', num = 2;
		else if(s[i]=='i')
			tmps = '4', num = 3;
		else if(s[i]=='j')
			tmps = '5', num = 1;
		else if(s[i]=='k')
			tmps = '5', num = 2;
		else if(s[i]=='l')
			tmps = '5', num = 3;
		else if(s[i]=='m')
			tmps = '6', num = 1;
		else if(s[i]=='n')
			tmps = '6', num = 2;
		else if(s[i]=='o')
			tmps = '6', num = 3;
		else if(s[i]=='p')
			tmps = '7', num = 1;
		else if(s[i]=='q')
			tmps = '7', num = 2;
		else if(s[i]=='r')
			tmps = '7', num = 3;
		else if(s[i]=='s')
			tmps = '7', num = 4;
		else if(s[i]=='t')
			tmps = '8', num = 1;
		else if(s[i]=='u')
			tmps = '8', num = 2;
		else if(s[i]=='v')
			tmps = '8', num = 3;
		else if(s[i]=='w')
			tmps = '9', num = 1;
		else if(s[i]=='x')
			tmps = '9', num = 2;
		else if(s[i]=='y')
			tmps = '9', num = 3;
		else if(s[i]=='z')
			tmps = '9', num = 4;

		if(!finals.empty()&&tmps==finals.back())
			finals.push_back('#');
		for(int i=0;i<num;i++)
			finals.push_back(tmps);
	}
}

void numbering(int* num)
{
	for(int i=0;i<(int)finals.size();i++)
	{
		if(finals[i]=='#')
			continue;
		finals[i] = num[finals[i]-'0']+'0';
	}
}
