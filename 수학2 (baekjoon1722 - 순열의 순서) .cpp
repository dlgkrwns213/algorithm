//입력받은 숫자에 알맞게 입력과 그에 대한 출력을 하는 문제
//20!값이 int의 범위를 벗어나므로 long long을 이용하여 값을 입력 혹은 출력해준다.
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
