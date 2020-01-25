//이차원 배열에서 최대값을 가지는 경로로 이동하기
//같은 크기의 이차원 배열을 dp값으로 설정하여 최대값 구하기

#include <iostream>

using namespace std;

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	int n, m;
	cin >> n >> m;

	int miro[n][m];
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			cin >> miro[i][j];

	int dp[n][m];
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
		{
			if(i==0&&j==0)
				dp[i][j] = 0;
			else if(i==0)
				dp[i][j] = dp[i][j-1];
			else if(j==0)
				dp[i][j] = dp[i-1][j];
			else
				dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
			dp[i][j] += miro[i][j];
		}
	
	cout << dp[n-1][m-1];
}
