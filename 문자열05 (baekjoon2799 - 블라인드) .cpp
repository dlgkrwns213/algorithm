//아파트의 상태를 입력받고
//각 집마다 블라인드의 가짓수가 5개중 무엇인지 세어 개수를 출력해주기
#include <iostream>

using namespace std;


int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	int m, n;
	cin >> m >> n;
	int M = 5*m+1, N = 5*n+1;
	char apart[M][N];
	for(int i=0;i<M;i++)
		for(int j=0;j<N;j++)
			cin >> apart[i][j];

	int count[5] = {};
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(apart[5*i+4][5*j+1]=='*')
				count[4]++;
			else if(apart[5*i+3][5*j+1]=='*')
				count[3]++;
			else if(apart[5*i+2][5*j+1]=='*')
				count[2]++;
			else if(apart[5*i+1][5*j+1]=='*')
				count[1]++;
			else
				count[0]++;
		}
	}
	for(int i=0;i<5;i++)
		cout << count[i] << " ";
	return 0;
}
