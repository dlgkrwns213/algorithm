//LIS변형 문제1
//n^2의 시간으로 LIS와 비슷한 방법을 사용한다.

#include <iostream>

using namespace std;

int main()
{
	int n;
	cin >> n;

	int a[n];
	for(int i=0;i<n;i++)
		cin >> a[i];

	int dp[n];
	for(int i=0;i<n;i++)
	{
		int M = 0;
		for(int j=0;j<i;j++)
		{
			if(a[i]>a[j])
				M = max(M, dp[j]);
		}
		dp[i] = M+a[i];
	}

	int ptr = 0;
	for(int i=0;i<n;i++)
		ptr = max(ptr, dp[i]);

	cout << ptr;
}

