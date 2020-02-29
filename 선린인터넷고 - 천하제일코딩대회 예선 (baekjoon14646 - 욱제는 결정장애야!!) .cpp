#include <iostream>

using namespace std;

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	int n;
	cin >> n;

	bool stick[n+1] = {};
	int T = 2*n;
	int M=0, now=0;
	while(T--)
	{
		int num;
		cin >> num;

		if(!stick[num])
		{
			stick[num] = true;
			now++;
		}
		else
			now--;
		M = max(M, now);
	}
	cout << M;
}
