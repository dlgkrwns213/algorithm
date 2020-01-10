#include <iostream>
#include <climits>

using namespace std;

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	int n, m;
	cin >> n >> m;
	int jew[m];
	for(int i=0;i<m;i++)
		cin >> jew[i];


	int left = 0;
	int right = INT_MAX;
	while(left<right)
	{
		int mid = (left+right)/2;
		int count = 0;
		for(int i=0;i<m;i++)
			count += (jew[i]+mid-1)/mid;
		if(count<=n)
			right = mid;
		else
			left = mid+1;
	}
	cout << left;
	return 0;
}
