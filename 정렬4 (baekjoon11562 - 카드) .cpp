//sort, vector, pair를 이용하여 가장 많이 갖고 있는 카드의 수를 구하는 문제
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	int n;
	cin >> n;

	long long card[n];
	for(int i=0;i<n;i++)
		cin >> card[i];
	if(n==1)
	{
		cout <<card[0];
		return 0;
	}

	sort(card, card+n);

	vector<pair<long long, int> > cv;
	int count = 1;
	for(int i=1;i<n;i++)
	{
		if(card[i]==card[i-1])
			count++;
		else
		{
			cv.push_back({card[i-1], count});
			count = 1;
		}

		if(i==n-1)
			cv.push_back({card[n-1], count});
	}

	int max_index = 0;
	for(int i=0;i<(int)cv.size();i++)
	{
		if(cv[max_index].second<cv[i].second)
			max_index = i;
	}
	cout << cv[max_index].first;

	return 0;
}
