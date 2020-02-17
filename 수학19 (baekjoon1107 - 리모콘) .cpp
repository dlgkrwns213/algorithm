#include <iostream>

using namespace std;

int main()
{
	int n;
	cin >> n;

	int m;
	cin >> m;
	bool ten[10] = {};
	while(m--)
	{
		int num;
		cin >> num;
		ten[num] = true;
	}

	int mini = 500000;
	for(int i=0;i<=2*n+10;i++)
	{
		string s = to_string(i);
		int ss = (int)s.size();

		bool use = true;
		for(int j=0;j<ss;j++)
			if(ten[s[j]-'0'])
			{
				use = false;
				break;
			}

		if(use)
			mini = min(abs(n-i)+ss, mini);

	}
	cout << min(mini, abs(100-n));
}
