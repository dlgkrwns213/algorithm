//3*n개의 틀을 1*2의 사각형 모양으로 채우는 가짓수를 구하는 문제
//n이 홀수일 경우 0을 출력하고 
//짝수일 경우 2를 나누어서 규칙을 찾고 dp로 계산한다.
//3*2칸을 채우는 가짓수는 3, 나머지 짝수칸을 채우는 가짓수는 2라는 규칙을 적용시킨다.

#include <iostream>

using namespace std;

int main()
{
	int n;
	cin >> n;
	if(n%2==1)
	{
		cout << 0;
		return 0;
	}
	n/=2;
	int dp[n+1] = {};
	dp[1] = 3;
	for(int i=2;i<=n;i++)
	{
		for(int j=1;j<i;j++)
			dp[i] += dp[j]*2;
		dp[i]+=dp[i-1]+2;
	}

	cout << dp[n];
}
