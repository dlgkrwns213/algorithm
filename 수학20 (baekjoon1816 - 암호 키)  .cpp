#include <iostream>

using namespace std;

int main()
{
	int T;
	cin >> T;

	while(T--)
	{
		long long l;
		cin >> l;

		bool no = false;
		if(l%2==0)
			cout << "NO\n";
		else
		{
			for(long long i=3;i<1000000;i+=2)
				if(l%i==0)
				{
					no = true;
					break;
				}
			if(!no)
				cout << "YES\n";
			else
				cout << "NO\n";
		}
	}
}
