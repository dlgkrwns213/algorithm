//LIS변형 문제2

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
		int m = 0;
		for(int j=0;j<i;j++)
			if(a[i]<a[j])
				m = max(m, dp[j]);
		dp[i] = m+1;
	}

	int ptr = 0;
	for(int i=0;i<n;i++)
		ptr = max(ptr, dp[i]);

	cout << ptr;
}
