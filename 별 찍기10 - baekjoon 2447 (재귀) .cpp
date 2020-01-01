//보다 복잡한 모양이 반복되는 별 문양을 재귀를 이용하여 만들어보았다.
#include <iostream>

using namespace std;

bool map[6562][6562];
void split(int n, int a, int b);
void draw(int a, int b);
void no(int n, int a, int b);
int main()
{
	int n;
	cin >> n;

	split(n, 0, 0);

	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(map[i][j])
				cout << "*";
			else
				cout << " ";
		}
		cout << endl;
	}

	return 0;
}

void split(int n, int a, int b)
{
	if(n==3)
		draw(a, b);
	else
	{
		int dn = n/3;
		for(int i=0;i<3;i++)
			for(int j=0;j<3;j++)
			{
				if(i==1&&j==1)
					no(dn, a+dn, b+dn);
				else
					split(dn, a+i*dn, b+j*dn);
			}
	}
}

void draw(int a, int b)
{
	for(int i=0;i<3;i++)
		for(int j=0;j<3;j++)
		{
			if(i==1&&j==1)
				no(1, a+1, b+1);
			else
				map[a+i][b+j] = 1;
		}
}

void no(int n, int a, int b)
{
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			map[a+i][a+j] = 0;
}
