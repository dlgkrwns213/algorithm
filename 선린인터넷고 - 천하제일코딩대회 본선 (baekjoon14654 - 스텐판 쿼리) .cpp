#include <iostream>

using namespace std;

int win(int a, int b);
int main()
{
	int n;
	cin >> n;

	int a[n], b[n];
	for(int i=0;i<n;i++)
		cin >> a[i];
	for(int i=0;i<n;i++)
		cin >> b[i];

	bool A[n];
	for(int i=0;i<n;i++)
	{
		int now = win(a[i], b[i]);
		if(i==0)
		{
			if(now==-1)
				A[0] = true;
			else
				A[0] = false;
		}
		else
		{
			if(now==0)
				A[i] = !A[i-1];
			else if(now==-1)
				A[i] = true;
			else
				A[i] = false;
		}
	}
	int M=1, tmp=1;
	for(int i=1;i<n;i++)
	{
		if(A[i]==A[i-1])
			tmp++;
		else
			tmp = 1;
		M = max(M, tmp);
	}

	cout << M;
	return 0;
}

int win(int a, int b)
{
	if(a==b)
		return 0;
	if(a==1&&b==3)
		return -1;
	if((a==3&&b==1)||a<b)
		return 1;
	return -1;
}
