//이분탐색을 이용하여 문제 풀어보기 (반복문)
//https://www.acmicpc.net/problem/2805

#include <iostream>
#include <climits>

using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;

	int tree[n];
	for(int i=0;i<n;i++)
		cin >> tree[i];

	long long last = INT_MAX;
	long long start = 0;
	long long len = 0;
	while(start<=last)
	{
		long long mid = (start+last)/2;
		long long count = 0;
		for(int i=0;i<n;i++)
			if(tree[i]>mid)
				count += tree[i]-mid;

		if(count>=m)
		{
			start = mid+1;
			len = max(len, mid);
		}
		else
			last = mid-1;
	}
	cout << len;

	return 0;
}
