//재귀를 이용하여 이진 분열 알고리즘에 대해 만들어보았다.
#include <iostream>

using namespace std;

void make(int* length, int k, long long start, long long last, int n);

long long made_max;
int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int k, n;
	cin >> k >> n;

	int len[k];
	long long count = 0;
	for(int i=0;i<k;i++)
	{
		cin >> len[i];
		count += len[i];
	}

	long long mm = count/n;
	long long m = len[0]/n;

	make(len, k, m, mm+1, n);
	cout << made_max;

	return 0;
}

void make(int* length, int k, long long start, long long last, int n)
{
	if(start>last)
		return;
	long long mid = (start+last)/2;
	long long made = 0;
	for(int i=0;i<k;i++)
		made += length[i]/mid;
	if(made>=n)
	{
		made_max = max(made_max, mid);
		make(length, k, mid+1, last, n);
	}
	else
		make(length, k, start, mid-1, n);
}
