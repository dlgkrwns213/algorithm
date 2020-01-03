//정렬과 역정렬을 이용하여 최소의 곱을 
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int n;
	cin >> n;
	int A[n], B[n];
	for(int i=0;i<n;i++)
		cin >> A[i];
	for(int i=0;i<n;i++)
		cin >> B[i];

	sort(A, A+n);
	sort(B, B+n);
	reverse(B, B+n);

	int sum = 0;
	for(int i=0;i<n;i++)
		sum += A[i]*B[i];

	cout << sum;
}
