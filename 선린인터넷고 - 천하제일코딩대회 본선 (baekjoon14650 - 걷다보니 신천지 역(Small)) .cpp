#include <iostream>

using namespace std;

int main()
{
	int n;
	cin >> n;

	if(n==1)
		cout << 0;
	else
	{
		int r = 2;
		for(int i=2;i<n;i++)
			r*=3;
		cout << r;
	}
}
