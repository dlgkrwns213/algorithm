//제곱수를 뺀 값에 1더한 값과의 차이를 통해 계산해준다.
//값 자체가 제곱수인 경우를 처리해주기 위해 0까지 계산해준다.

#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	int n;
	cin >> n;

	int dp[n+1];
	for(int i=0;i<=n;i++)
	{
		dp[i] = i;
		for(int j=1;j<=sqrt(i);j++)
			dp[i] = min(dp[i-j*j]+1, dp[i]);
	}
	cout << dp[n];
	return 0;
}
