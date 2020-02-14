//서로 다른 3진법의 합으로 표현한다.
//=>n번째 수는 n을 2진법으로 바꾼 값으로 표현 
//10진법을 2진법으로 바꾼 뒤 3진법으로 바꿔서 계산해주었다.

#include <iostream>

using namespace std;

string make2string(long long n);
long long three(string s);
int main()
{
	long long n;
	cin >> n;

	string s = make2string(n);
	cout << three(s);
}

string make2string(long long n)
{
	string tmps;
	while(n>0)
	{
		tmps.push_back(n%2+'0');
		n/=2;
	}
	return tmps;
}

long long three(string s)
{
	long long sum=0, t=1;
	for(int i=0;i<(int)s.size();i++)
	{
		sum+=(s[i]-'0')*t;
		t*=3;
	}
	return sum;
}
