//승률이 99나 100일 경우 아무리 많이 이겨도 승률이 변하지 않음
//1000000000000이란 수가 1초만에 하기엔 너무 큰 수 이므로 이진탐색을 통하여 범위를 줄여나가며 시간을 최소화시킴
#include <iostream>
#include <vector>

using namespace std;

long long fac(int n)
{
	long long sum = 1;
	for(int i=1;i<=n;i++)
		sum *= i;
	return sum;
}

int main()
{
	int n;
	cin >> n;

	int q;
	cin >> q;
	if(q==1)
	{
		long long k;
		cin >> k;
		k--;
		bool v[n] = {};
		for(int i=0;i<n;i++)
		{
			int m = k/fac(n-i-1);
			k %= fac(n-i-1);
			int j = 0;
			int h = 0;
			while(1)
			{
				if(h==m&&!v[j])
				{
					v[j] = true;
					break;
				}
				else if(!v[j])
				{
					j++;
					h++;
				}
				else
					j++;
			}
			cout << j+1 << " ";
		}
	}
	else if(q==2)
	{
		int a[n];
		for(int i=0;i<n;i++)
			cin >> a[i];

		long long count = 1;
		vector<int> s;
		for(int i=0;i<n-1;i++)
		{
			int minus=0;
			for(int j=0;j<(int)s.size();j++)
				if(s[j]<a[i])
					minus++;
			count += (a[i]-minus-1)*fac(n-i-1);
			s.push_back(a[i]);
		}
		cout << count;
	}
}
