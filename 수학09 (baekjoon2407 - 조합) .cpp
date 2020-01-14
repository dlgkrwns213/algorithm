//c에서는 long long보다 큰 수를 표현할 수 없어서 struct를 이용해서 좀더 큰수를 표현하였다.
#include <iostream>
#include <string>

using namespace std;
#define big 100000000000000

int main()
{
	int n, m;
	cin >> n >> m;

	pair<long long, long long> c[n+1][n+1];
	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=i;j++)
		{
			c[i][j].first = 0;
			if(i==0||j==0||i==j)
			{
				c[i][j].second = 1;
			}
			else
			{
				c[i][j].second = c[i-1][j-1].second+c[i-1][j].second;
				c[i][j].first = c[i-1][j-1].first+c[i-1][j].first;
				if(c[i][j].second>big)
				{
					c[i][j].second-=big;
					c[i][j].first++;
				}
			}
		}
	}

	string s = to_string(c[n][m].second);
	if(c[n][m].first!=0)
	{
		cout << c[n][m].first;
		int zero_s = 14-s.size();
		for(int i=0;i<zero_s;i++)
			cout << 0;
		cout << s;
	}
	else
		cout << s;

	return 0;
}
