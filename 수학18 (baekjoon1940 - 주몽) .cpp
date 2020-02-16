#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;

	int shld[n];
	for(int i=0;i<n;i++)
		cin >> shld[i];

	sort(shld, shld+n);

	int count = 0;
	int left=0, right=n-1;
	while(left<right)
	{
		int tmp = shld[left]+shld[right];
		if(tmp<m)
			left++;
		else if(tmp>m)
			right--;
		else
		{
			count++;
			left++;
			right--;
		}
	}
	cout << count;
}
