//vecotor와 sort를 이용하여 푸는 이진탐색 문제
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m, road;
	cin >> n >> m >> road;

	vector<int> rest;
	for(int i=0;i<n;i++)
	{
		int r;
		cin >> r;
		rest.push_back(r);
	}
	rest.push_back(0);
	rest.push_back(road);
	sort(rest.begin(), rest.end());

	n = (int)rest.size();
	int left = 0;
	int right = 10000;
	while(left<=right)
	{
		int mid = (left+right)/2;
		int count = 0;
		for(int i=1;i<n;i++)
			count += (rest[i]-rest[i-1]-1)/mid;
		if(count<=m)
			right = mid-1;
		else
			left = mid+1;
	}
	cout << left;
	return 0;
}
