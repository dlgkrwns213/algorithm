#include <iostream>

using namespace std;

int main()
{
	int sum, i;
	char c;
	cin >> i;
	sum = i;
	while(1)
	{
		cin >> c;
		if(c=='=')
		{
			cout << sum;
			return 0;
		}
		cin >> i;
		if(c=='+')
			sum+=i;
		else if(c=='-')
			sum-=i;
		else if(c=='*')
			sum*=i;
		else if(c=='/')
			sum/=i;
	}
}
