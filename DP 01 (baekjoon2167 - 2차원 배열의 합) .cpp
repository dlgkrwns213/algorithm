//dp를 통하여 배열의 1, 1부터 i, k까지의 합을 모두 구한 후 문제에서 원하는 작은 사각형의 합은 따로 계산하였다.
//많은 메모리를 사용했지만 구하는 방식이 쉽고 명확하다.

#include <iostream>

using namespace std;

struct IJ
{
	int i, j;
};
int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;

	int a[n+1][m+1];
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			cin >> a[i][j];

	int dp[n+1][m+1] = {};
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		{
			if(i==1&&j==1)
				dp[i][j] = a[i][j];
			else if(i==1)
				dp[i][j] = dp[i][j-1]+a[i][j];
			else if(j==1)
				dp[i][j] = dp[i-1][j]+a[i][j];
			else
				dp[i][j] = dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1]+a[i][j];
		}

	int T;
	cin >> T;
	while(T--)
	{
		IJ start, last;
		cin >> start.i >> start.j >> last.i >> last.j;
		cout << dp[last.i][last.j] - dp[start.i-1][last.j] - dp[last.i][start.j-1] + dp[start.i-1][start.j-1] << "\n";
	}
	return 0;
}
