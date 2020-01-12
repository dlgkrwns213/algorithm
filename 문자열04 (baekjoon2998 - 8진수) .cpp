//2진수로 주어진 수를 8진수로 바꿔주는 문제
//짝이 맞지 않는 앞자리 수들에 대해 먼저 계산 후 출력해주고
//나머지 값들에 대해 출력해준다

#include <iostream>

using namespace std;

int main()
{
	string s;
	cin >> s;

	int ss = (int)s.size();
	int n = ss%3;
	if(n==1)
		cout << 1;
	else if(n==2)
		cout << 2+s[1]-'0';

	for(int i=n;i<ss;i+=3)
		cout << s[i]*4+s[i+1]*2+s[i+2]-'0'*7;

	return 0;
}
