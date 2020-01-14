//그림을 char형으로 입력받아 각 배들의 등수를 구해주는 문제
//뒤에서부터 1등을 설정해주고 등수를 score로 설정하여 한 팀이라도 등수가 정해지면 score값을 올려주기

#include <iostream>

using namespace std;

int main()
{
	int r, c;
	cin >> r >> c;
	char contest[r][c];
	for(int i=0;i<r;i++)
		for(int j=0;j<c;j++)
			cin >> contest[i][j];

	int score = 1;
	int kayak[9];
	bool visited[r] = {};
	for(int i=c-2;i>0;i--)
	{
		bool yes = false;
		for(int j=0;j<r;j++)
		{
			if(visited[j])
				continue;
			if(contest[j][i]!='.')
			{
				kayak[contest[j][i]-'1'] = score;
				visited[j] = true;
				yes = true;
			}
		}
		if(yes)
			score++;
	}
	for(int i=0;i<9;i++)
		cout << kayak[i] << endl;
	return 0;
}
