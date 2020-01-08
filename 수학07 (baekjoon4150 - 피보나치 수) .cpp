//자릿수가 1000자리 이하까지 가능하다고 함 
//=>long long으로해도 훨씬 부족함
//=>string으로 만들어 string끼리 덧셈하도록 만들어준다.
//첫자리부터 역순으로 저장해준다.
#include <iostream>

using namespace std;

void reset(char* c)
{
	for(int i=0;i<1001;i++)
		c[i] = '0';
}

void change(char* c1, char* c2)
{
	for(int i=0;i<1001;i++)
		c2[i] = c1[i];
}

int main()
{
	int n;
	cin >> n;

	char c1[1001];
	char c2[1001];
	reset(c1);
	reset(c2);

	c1[0] = '1';
	c2[0] = '1';

	for(int i=2;i<n;i++)
	{
		char tmp[1001];
		reset(tmp);
		for(int j=0;j<1000;j++)
		{
			tmp[j] += c2[j] + c1[j] - '0'-'0';
			if(tmp[j]>'9')
			{
				tmp[j]-= 10;
				tmp[j+1] += 1;
			}
		}

		change(c2, c1);
		change(tmp, c2);
	}

	bool only_zero = true;
	for(int i=1000;i>=0;i--)
	{
		if(c2[i]=='0'&&only_zero)
			continue;
		if(c2[i]!='0')
			only_zero = false;
		cout << c2[i];
	}
	return 0;
}
