//재귀를 이용하여 하노이탑의 이동순서를 모두 출력하였다.
#include <iostream>

using namespace std;

void make(int from, int to, int n);

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;

	int count = 1;
	for(int i=0;i<n;i++)
		count *= 2;
	cout << count-1 << "\n";
	make(1, 3, n);

	return 0;
}

void make(int from, int to, int n)
{
	if(n==1)
		cout << from << " " << to << "\n";
	else
	{
		make(from, 6-from-to, n-1);
		cout << from << " " << to << "\n";
		make(6-from-to, to, n-1);
	}
}
