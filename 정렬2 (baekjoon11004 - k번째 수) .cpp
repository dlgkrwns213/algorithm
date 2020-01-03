//O(nlogn)의 정렬을 이용하여 수열을 정렬한 후 k번째 값을 출력하기
#include <iostream>

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
	
	int n, k;
	cin >> n >> k;

	int A[n];
	for(int i=0;i<n;i++)
		cin >> A[i];

	qsort(A, n, sizeof(int), compare);

	cout << A[k-1];
	return 0;
}
