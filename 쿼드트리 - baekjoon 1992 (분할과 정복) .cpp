//분할과 정복을 이용하여 종이를 자른 후 총 종이의 개수 구하기
#include <iostream>

using namespace std;

int data[65][65];
bool same(int x, int y, int n);
void quad_tree(int x, int y, int n);

int main()
{
	int n;
	cin >> n;
	for(int i=0;i<n;i++)
	{
		string s;
		cin >> s;
		for(int j=0;j<n;j++)
			data[i][j] = s[j]-'0';
	}

	quad_tree(0, 0, n);
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
		cout << data[x][y];
	else
	{
		cout << "(";
		int dn = n/2;
		quad_tree(x, y, dn);
		quad_tree(x, y+dn, dn);
		quad_tree(x+dn, y, dn);
		quad_tree(x+dn, y+dn, dn);
		cout << ")";
	}
}
