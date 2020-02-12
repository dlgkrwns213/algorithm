#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	int n;
	cin >> n;

	char room[n][n];
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			cin >> room[i][j];

	int fcount = 0;
	for(int i=0;i<n;i++)
	{
		bool x = true;
		for(int j=1;j<n;j++)
		{
			if(room[i][j-1]=='.'&&room[i][j]=='.'&&x)
			{
				fcount++;
				x = false;
			}
			if(room[i][j]=='X')
				x = true;
		}
	}
	int scount = 0;
	for(int j=0;j<n;j++)
	{
		bool x = true;
		for(int i=1;i<n;i++)
		{
			if(room[i-1][j]=='.'&&room[i][j]=='.'&&x)
			{
				scount++;
				x = false;
			}
			if(room[i][j]=='X')
				x = true;
		}
	}
	cout << fcount << " " << scount;
	return 0;
}
