//n+1개의 그릇에 k개의 공을 최대한 균일하게 놓

#include <iostream>

using namespace std;

int main()
{
	int n, day;
	cin >> n >> day;

	for(int i=0;i<n;i++)
	{
		int tmp;
		cin >> tmp;
		day -= tmp+1;
	}

	if(day<=0)
		cout << 0;
	else
	{
		int x = day/(n+1);
		int r = day%(n+1);
		int sum = r*(x+1)*(x+1)+(n+1)*x*(x+1)*(2*x+1)/6;
		cout << sum;
	}
}
