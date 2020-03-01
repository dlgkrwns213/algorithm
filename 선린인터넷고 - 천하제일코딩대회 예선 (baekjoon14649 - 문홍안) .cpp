#include <iostream>

using namespace std;

int main()
{
	double p;
	int n;
	cin >> p >> n;

	int count[101] = {};
	while(n--)
	{
		int num;
		char LR;
		cin >> num >> LR;

		if(LR=='R')
			for(int i=100;i>num;i--)
				count[i]++;
		else
			for(int i=1;i<num;i++)
				count[i]++;
	}
	int B=0, R=0, G=0;
	for(int i=1;i<101;i++)
	{
		if(count[i]%3==0)
			B++;
		else if(count[i]%3==1)
			R++;
		else
			G++;
	}
	double b, r, g;
	b = p*B/100;
	r = p*R/100;
	g = p*G/100;

	cout << fixed;
	cout.precision(2);
	cout << b << "\n" << r << "\n" << g;
}
