//algorithm의 lower_bound와 upper_bound를 이용하여 푼 문제 - 이 두 함수는 이분 탐색을 이용한다.
#include <iostream>
#include <algorithm>

using namespace std;

int compare(const void* a, const void* b)
{
	return *(int*)a-*(int*)b;
}

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
	qsort(card, n, sizeof(int), compare);

	int m;
	cin >> m;
	for(int i=0;i<m;i++)
	{
		int c;
		cin >> c;
		int* low = lower_bound(card, card+n, c);
		int* up = upper_bound(card, card+n, c);

		cout << up-low << " ";
	}
	return 0;
}
