//쿼드트리와 비슷하지만 9개로 자르는 알고리즘
#include <iostream>

using namespace std;

int data[2188][2188];
int one = 0;
int zero = 0;
int minus_one = 0;
bool same(int x, int y, int n);
void quad_tree(int x, int y, int n);

int main()
{
	int n;
	cin >> n;
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			cin >> data[i][j];

	quad_tree(0, 0, n);
	cout << minus_one << endl;
	cout << zero << endl;
	cout << one;
	return 0;
}

bool same(int x, int y, int n)
{
	for(int i=x;i<x+n;i++)
		for(int j=y;j<y+n;j++)
			if(data[x][y]!=data[i][j])
				return false;
	return true;
}

void quad_tree(int x, int y, int n)
{
	if(same(x, y, n))
	{
		if(data[x][y]==1)
			one++;
		else if(data[x][y]==0)
			zero++;
		else
			minus_one++;
	}
	else
	{
		int dn = n/3;
		for(int i=0;i<3;i++)
			for(int j=0;j<3;j++)
				quad_tree(x+i*dn, y+j*dn, dn);
	}
}
