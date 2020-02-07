//파스칼의 삼각형을 이용한 조합값 구하기

#include <iostream>

using namespace std;

int main()
{
	int n, k;
	cin >> n >> k;
	int PT[n+1][n+1] = {};

	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=i;j++)
		{
			if(j==0||j==i)
				PT[i][j] = 1;
			else
				PT[i][j] = (PT[i-1][j] + PT[i-1][j-1])%10007;
		}
	}

	cout << PT[n][k];

	return 0;

}

