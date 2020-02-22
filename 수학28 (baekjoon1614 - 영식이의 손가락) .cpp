#include <iostream>

using namespace std;

int main()
{
	int n;
	cin >> n;

	long long M;
	cin >> M;

	long long C = 0;
	if(n==1)
		C = M*8;
	else if(n==2)
		C = M/2*8 + 1 + M%2*6;
	else if(n==3)
		C = M/2*8 + 2 + M%2*4;
	else if(n==4)
		C = M/2*8 + 3 + M%2*2;
	else if(n==5)
		C = M*8+4;

	cout << C;
}
