#include <iostream>

using namespace std;

int main()
{
	int n;
	cin >> n;
	int a, b;
	cin >> a >> b;
	int N = 1;
	for(int i=0;i<n;i++)
		N*=2;
	a++;
	b++;
	int count = 0;
	while(1)
	{
		if(a==1&&b==1)
			break;

		if(a>N/2)
		{
			count += N*N/2;
			a -= N/2;
		}
		if(b>N/2)
		{
			count += N*N/4;
			b -= N/2;
		}
		N /= 2;
	}
	cout << count;
}
