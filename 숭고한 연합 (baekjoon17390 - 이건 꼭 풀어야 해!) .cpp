//시간 상 매우 효율적인 코드는 아니다.

#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;

	int a[n];
	for(int i=0;i<n;i++)
		cin >> a[i];
	sort(a, a+n);

	int num[1001] = {};
	int count[1001] = {};
	for(int i=n-1;i>=0;i--)
	{
		num[a[i]] = i;
		count[a[i]]++;
	}

	while(m--)
	{
		int L, R;
		cin >> L >> R;
		L--, R--;

		if(a[L]==a[R])
			cout << a[L]*(R-L+1) << "\n";
		else
		{
			int sum = 0;
			int La = a[L], Ra = a[R];
			for(int i=La+1;i<Ra;i++)
				sum += i*count[i];

			sum+=Ra*(R-num[Ra]+1);

			for(int i=0;;i++)
				if(L<num[i])
				{
					sum+=La*(num[i]-L);
					break;
				}
			cout << sum << "\n";
		}
	}
}
