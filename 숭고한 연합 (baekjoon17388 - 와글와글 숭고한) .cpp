#include <iostream>

using namespace std;

int main()
{
	int a, b, c;
	cin >> a >> b >> c;
	if(a+b+c>=100)
		cout << "OK";
	else
	{
		int m;
		m = min(a, min(b, c));
		if(a==m)
			cout << "Soongsil";
		else if(b==m)
			cout << "Korea";
		else
			cout << "Hanyang";
	}
}
