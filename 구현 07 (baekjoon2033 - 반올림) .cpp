//첫자리수를 제외하고 모든 자리수가 0일 될때까지 반올림해주기
//145 => 200, 144 => 100이 된다
//while을 이용하여 반올림 계산

#include <iostream>

using namespace std;

int main()
{
	int n;
	cin >> n;

	int r = 1;
	while(n>10)
	{
		if(n%10<5)
			n/=10;
		else
		{
			n/=10;
			n++;
		}
		r*=10;
	}
	cout << n*r;
}
