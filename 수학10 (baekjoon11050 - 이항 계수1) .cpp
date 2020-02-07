//기본적인 조합값 구하는 문제

#include <iostream>

using namespace std;

int fac(int big, int small);

int main()
{
	int n, k;
	cin >> n >> k;
	cout << fac(n, n-k+1)/fac(k, 1);

	return 0;
}

int fac(int big, int small)
{
	int sum = 1;
	for(int i=small;i<=big;i++)
		sum *= i;
	return sum;
}
