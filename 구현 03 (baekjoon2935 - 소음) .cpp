//10의 거듭제곱 두개와 +, *중 하나를 입력받고 연산해주는 문제
//string을 통해 입력받아야 하므로 0의 개수를 잘 세어서 출력해준다.

#include <iostream>

using namespace std;

int main()
{
	string A, B;
	char c;
	cin >> A >> c >> B;
	int a = (int)A.size(), b=(int)B.size();

	if(c=='+')
	{
		if(A>B)
		{
			cout << 1;
			for(int i=1;i<a-b;i++)
				cout << 0;
			cout << B;
		}
		else if(A<B)
		{
			cout << 1;
			for(int i=1;i<b-a;i++)
				cout << 0;
			cout << A;
		}
		else
		{
			cout << 2;
			for(int i=1;i<a;i++)
				cout << 0;
		}
	}
	else if(c=='*')
	{
		cout << 1;
		for(int i=2;i<a+b;i++)
			cout << 0;
	}
}
