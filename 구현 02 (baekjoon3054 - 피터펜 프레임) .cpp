//글자를 잘 꾸며주는 문제

#include <iostream>
#include <vector>

using namespace std;

int main()
{
	string s;
	cin >> s;

	int ss = 4*(int)s.size()+1;
	char pic[5][ss];
	for(int i=0;i<5;i++)
		for(int j=0;j<ss;j++)
			pic[i][j] = '.';

	for(int i=0;i<5;i++)
	{
		for(int j=0;j<ss;j++)
		{
			if(j%4==0)
				pic[2][j] = '#';
			else if(j%4==1||j%4==3)
			{
				pic[1][j] = '#';
				pic[3][j] = '#';
			}
			else if(j%4==2)
			{
				pic[0][j] = '#';
				pic[4][j] = '#';
				pic[2][j] = s[(j-2)/4];
			}
		}
		for(int j=12;j<ss;j+=12)
		{
			pic[2][j] = '*';
			pic[1][j-1] = '*';
			pic[3][j-1] = '*';
			pic[0][j-2] = '*';
			pic[4][j-2] = '*';
			pic[1][j-3] = '*';
			pic[3][j-3] = '*';
			pic[2][j-4] = '*';
		}
	}

	for(int i=0;i<5;i++)
	{
		for(int j=0;j<ss;j++)
			cout << pic[i][j];
		cout << endl;
	}
}
