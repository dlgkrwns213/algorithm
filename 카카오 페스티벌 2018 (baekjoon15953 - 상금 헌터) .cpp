#include <iostream>

using namespace std;

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	int T;
	cin >> T;
	while(T--)
	{
		int a, b;
		cin >> a >> b;
		int A, B;
		if(a==0)
			A = 0;
		else if(a==1)
			A = 5000000;
		else if(a<=3)
			A = 3000000;
		else if(a<=6)
			A = 2000000;
		else if(a<=10)
			A = 500000;
		else if(a<=15)
			A = 300000;
		else if(a<=21)
			A = 100000;
		else
			A = 0;


		if(b==0)
			B = 0;
		else if(b==1)
			B = 5120000;
		else if(b<=3)
			B = 2560000;
		else if(b<=7)
			B = 1280000;
		else if(b<=15)
			B = 640000;
		else if(b<=31)
			B = 320000;
		else
			B = 0;

		cout << A+B << "\n";
	}
}
