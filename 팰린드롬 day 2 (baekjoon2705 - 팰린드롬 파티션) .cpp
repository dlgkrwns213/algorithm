#include <iostream>

using namespace std;

int main()
{
	int T;
	cin >> T;
	while(T--)
	{
		int n;
		cin >> n;

		int dp[n+1] = {};
		dp[0] = 1;
		dp[1] = 1;
		for(int i=2;i<=n;i++)
		{
			if(i%2==1)
				dp[i] = dp[i-1];
			else
			{
				for(int k=0;k<=i/2;k++)
					dp[i]+=dp[k];
			}
		}
		cout << dp[n] << "\n";
	}
}
