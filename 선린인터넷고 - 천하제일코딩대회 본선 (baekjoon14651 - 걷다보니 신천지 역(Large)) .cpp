#include <iostream>

using namespace std;
#define mod 1000000009

int main()
{
	int n;
	cin >> n;

	if(n==1)
		cout << 0;
	else
	{
		long long r = 2;
		for(int i=2;i<n;i++)
		{
			r*=3;
			r%=mod;
		}
		cout << r;
	}
}
