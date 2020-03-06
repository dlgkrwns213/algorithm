#include <iostream>

using namespace std;

int main()
{
	int n, a, i=1, count=0;
	cin >> n;
	while(n--)
	{
		cin >> a;
		if(i!=a)
			count++;
		i++;
	}
	cout << count;
}
