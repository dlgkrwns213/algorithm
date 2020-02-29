#include <iostream>

using namespace std;

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	int n, m;
	cin >> n >> m;

	string B[n][m];
	int count = 0;
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
		{
			cin >> B[i][j];
			for(int k=0;k<(int)B[i][j].size();k++)
				if(B[i][j][k]=='9')
					count++;
		}

	int line_max = 0;
	for(int i=0;i<n;i++)
	{
		int tmp_count = 0;
		for(int j=0;j<m;j++)
		{
			for(int k=0;k<(int)B[i][j].size();k++)
				if(B[i][j][k]=='9')
					tmp_count++;
		}
		line_max = max(line_max, tmp_count);
	}

	for(int j=0;j<m;j++)
	{
		int tmp_count = 0;
		for(int i=0;i<n;i++)
		{
			for(int k=0;k<(int)B[i][j].size();k++)
				if(B[i][j][k]=='9')
					tmp_count++;
		}
		line_max = max(line_max, tmp_count);
	}
	cout << count-line_max;
}
