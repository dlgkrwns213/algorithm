#include <iostream>

using namespace std;

int main()
{
	int n;
	cin >> n;
	pair<int, int> p;

	p = {0, 0};
	for(int i=1;i<=n;i++)
	{
		char c;
		cin >> c;

		if(c=='X')
			p.second = 0;
		else
		{
			p.first+=i+p.second;
			p.second++;
		}
	}
	cout << p.first;
}
