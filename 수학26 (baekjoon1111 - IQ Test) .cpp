#include <iostream>

using namespace std;

int main()
{
	int n;
	cin >> n;

	int x[n];
	for(int i=0;i<n;i++)
		cin >> x[i];

	if(n<=2)
	{
		if(x[0]==x[1])
			cout << x[1];
		else
			cout << 'A';
		return 0;
	}

	int a;
	if(x[1]==x[0])
		a = 0;
	else
		a = (x[2]-x[1])/(x[1]-x[0]);
	int b = x[1]-x[0]*a;

	bool suc = true;
	for(int i=1;i<n;i++)
		if(x[i]!=x[i-1]*a+b)
		{
			suc = false;
			break;
		}

	if(!suc)
		cout << 'B';
	else
		cout << x[n-1]*a+b;
}
