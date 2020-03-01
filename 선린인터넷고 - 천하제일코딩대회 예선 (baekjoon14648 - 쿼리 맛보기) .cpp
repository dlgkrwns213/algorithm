#include <iostream>

using namespace std;

long long one(int* a, int start, int last);
long long two(int* a, int s1, int l1, int s2, int l2);
int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, q;
	cin >> n >> q;

	int a[n+1];
	for(int i=1;i<=n;i++)
		cin >> a[i];

	while(q--)
	{
		int num;
		cin >> num;
		if(num==1)
		{
			int start, last;
			cin >> start >> last;
			cout << one(a, start, last) << "\n";
		}
		else if(num==2)
		{
			int s1, l1, s2, l2;
			cin >> s1 >> l1 >> s2 >> l2;
			cout << two(a, s1, l1, s2, l2) << "\n";
		}
	}
}

long long one(int* a, int start, int last)
{
	long long sum = 0;
	for(int i=start;i<=last;i++)
		sum+=a[i];
	int tmp = a[start];
	a[start] = a[last];
	a[last] = tmp;

	return sum;
}

long long two(int* a, int s1, int l1, int s2, int l2)
{
	long long sum1 = 0;
	for(int i=s1;i<=l1;i++)
		sum1+=a[i];

	long long sum2 = 0;
	for(int i=s2;i<=l2;i++)
		sum2+=a[i];

	return sum1-sum2;
}
