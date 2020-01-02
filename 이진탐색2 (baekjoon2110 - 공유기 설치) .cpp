//이분탐색을 이용하여 문제 풀어보기 (반복문)
//https://www.acmicpc.net/problem/2110

#include <iostream>

using namespace std;

int compare(const void* a, const void *b)
{
	return *(int*)a-*(int*)b;
}
int main()
{
	int n, c;
	cin >> n >> c;
	int home[n];
	for(int i=0;i<n;i++)
		cin >> home[i];
	qsort(home, n, sizeof(int), compare);

	long long last = home[n-1]-home[0];
	long long start = 0;
	long long mm = 0;

	while(start<=last)
	{
		int t=0;
		int count = 1;
		long long mid = (start+last)/2;
		for(int i=1;i<n;i++)
		{
			if(home[i]-home[t]>=mid)
			{
				t = i;
				count++;
			}
		}
		if(count>=c)
		{
			start = mid+1;
			mm = max(mm, mid);
		}
		else
			last = mid-1;
	}
	cout << mm;
	return 0;
}
