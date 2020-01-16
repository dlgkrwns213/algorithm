//각 수를 2진법으로 바꿔 1이면 더하고 0이면 더하지 않아서 더한 값이 k와 동일한 경우 count값을 늘려주었다.

#include <iostream>

using namespace std;

void maketwo(char* c, int n, int r, int i)
{
	for(int k=0;k<n;k++)
	{
		c[k] = i/r+'0';
		if(i>=r)
			i-=r;
		r/=2;
	}
}
int main()
{
	int n, s;
	cin >> n >> s;
	int a[n];
	for(int i=0;i<n;i++)
		cin >> a[i];

	int r=1;
	for(int i=1;i<n;i++)
		r*=2;
	int count = 0;

	char c[n];
	for(int i=1;i<2*r;i++)
	{
		maketwo(c, n, r, i);

		int sum = 0;
		for(int j=0;j<n;j++)
			if(c[j]=='1')
				sum+= a[j];

		if(sum==s)
			count++;
	}
	cout << count;
}
