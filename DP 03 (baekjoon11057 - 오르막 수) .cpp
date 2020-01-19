//끝자리 수가 0부터 9인 점을 이용하여 n*10의 배열을 만들어 끝자리 수별로 값을 계산하여 마지막에 값을 더해주어 출력해준다.

#include <iostream>

using namespace std;

int main()
{
	int n;
	cin >> n;

	int dp[n][10] = {};
	for(int i=0;i<n;i++)
		for(int j=0;j<10;j++)
		{
			if(i==0||j==0)
				dp[i][j] = 1;
			else
			{
				for(int k=0;k<=j;k++)
					dp[i][j]+=dp[i-1][k];
				dp[i][j]%=10007;
			}
		}
	int sum = 0;
	for(int i=0;i<10;i++)
		sum+=dp[n-1][i];
	cout << sum%10007;
}
