//n^4인 값을 배열의 결합과 정렬을 통하여 (nlogn)^2으로 바꾸어주는 문제
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
	int A[n], B[n], C[n], D[n];
	for(int i=0;i<n;i++)
		cin >> A[i] >> B[i] >> C[i] >> D[i];

	int arr1[n*n], arr2[n*n];
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
		{
			arr1[n*i+j] = A[i]+B[j];
			arr2[n*i+j] = C[i]+D[j];
		}

	sort(arr2, arr2+n*n);
	long long count = 0;
	for(int i=0;i<n*n;i++)
	{
		int minus_find = -arr1[i];
		count += upper_bound(arr2, arr2+n*n, minus_find) - lower_bound(arr2, arr2+n*n, minus_find);
	}
	cout << count;
	return 0;
}
