//정렬 후 짧은 시간내에 값을 찾는 기초적인 이진탐색 문제
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	int card[n];
	for(int i=0;i<n;i++)
		cin >> card[i];

	sort(card, card+n);

	int m;
	cin >> m;
	while(m--)
	{
		int give;
		cin >> give;
		int first = 0;
		int last = n-1;
		bool find = false;
		while(first<=last)
		{
			int mid = (first+last)/2;
			if(card[mid]<give)
				first = mid+1;
			else if(card[mid]>give)
				last = mid-1;
			else
			{
				cout << 1 << " ";
				find = true;
				break;
			}
		}
		if(!find)
			cout << 0 << " ";
	}
	return 0;
}
