//2*n의 동물원에 동물을 채우는 가짓수 구하기, 단 가로 세로로 연달아 놓을 수 없다.
//이전 값들을 이미 더하는 변수를 만들어서 연산이 겹치지 않게 하여 수행시간을 최소화한다.

#include <iostream>

using namespace std;

int main()
{
	int n;
	cin >> n;

	int zoo[n][2];
	int tmp = 1;
	int sum = 3;
	zoo[0][0] = 1;
	zoo[0][1] = 1;
	for(int i=1;i<n;i++)
	{
		zoo[i][0] = tmp+zoo[i-1][1];
		zoo[i][1] = tmp+zoo[i-1][0];
		tmp += zoo[i-1][0]+zoo[i-1][1];
		sum += zoo[i][0]+zoo[i][1];
		tmp%=9901;
		sum%=9901;
	}
	cout << sum;
}
