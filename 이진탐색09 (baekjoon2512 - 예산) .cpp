//최대의 예산을 만들 수 있는 상한값을 구하는 문제
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int n;
	cin >> n;
	int money[n];
	for(int i=0;i<n;i++)
		cin >> money[i];
	sort(money, money+n);

	int m;
	cin >> m;

	int first = 0;
	int last = money[n-1];
	int ptr = 0;
	while(first<=last)
	{
		int mid = (first+last)/2;
		int count = 0;
		for(int i=0;i<n;i++)
		{
			if(money[i]<=mid)
				count += money[i];
			else
				count += mid;
		}

		if(count<=m)
		{
			ptr = max(ptr, mid);
			first = mid+1;
		}
		else
			last = mid-1;
	}
	cout << ptr;
	return 0;
}
