//dp의 대표적인 문제인 LIS문제

#include <iostream>

using namespace std;

int maxTome(int* a, int n);
int fastmax(int* c, int start, int last);
int fastmin(int* c, int start, int last);

int main()
{
	int n;
	cin >> n;

	int a[n];
	for(int i=0;i<n;i++)
		cin >> a[i];

	cout << maxTome(a, n) << endl;

	return 0;
}

int maxTome(int* a, int n)
{
	int m[n];
	for(int i=0;i<n;i++)
	{
		if(i==0)
			m[i] = 1;
		else
		{
			int tmp[i] = {0};
			for(int j=0;j<i;j++)
				if(a[j]<a[i])
					tmp[j] = m[j];
			int tmp_max = fastmax(tmp, 0, i-1);
			if(tmp_max==0)
				m[i] = 1;
			else
				m[i] = tmp_max+1;
		}
	}

	return fastmax(m, 0, n-1);
}

int fastmax(int* c, int start, int last)
{
	if(start==last)
		return c[start];
	else
	{
		int mid = (start+last)/2;
		int max1 = fastmax(c, start, mid);
		int max2 = fastmax(c, mid+1, last);
		return max1>max2?max1:max2;
	}
}

int fastmin(int* c, int start, int last)
{
	if(start==last)
		return c[start];
	else
	{
		int mid = (start+last)/2;
		int min1 = fastmin(c, start, mid);
		int min2 = fastmin(c, mid+1, last);
		return min1<min2?min1:min2;
	}
}
