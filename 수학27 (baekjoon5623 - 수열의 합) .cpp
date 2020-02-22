#include <iostream>

using namespace std;

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;

	int s[3][n];
	for(int i=0;i<3;i++)
		for(int j=0;j<n;j++)
			cin >> s[i][j];

	if(n==2)
	{
		cout << 1 << " " << 1;
		return 0;
	}

	int a, b;
	b = (s[2][1] + s[1][0] - s[2][0])/2;
	a = s[1][0] - b;

	cout << a << " ";
	for(int i=1;i<n;i++)
		cout << s[0][i] - a << " ";
}
