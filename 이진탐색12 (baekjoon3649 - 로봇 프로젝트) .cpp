//STL algorithm의 sort를 이용한 후 이진탐색으로 푸는 문제
//입력이 끝날때까지 받아주는 것을 만들어주지 않아 많은 오답이 나왔다.
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int x, n;
	while(cin >> x >> n)
	{
		int block[n];
		for(int i=0;i<n;i++)
			cin >> block[i];
		x *= 10000000;

		sort(block, block+n);
		int left = 0;
		int right = n-1;
		bool bb = false;
		while(left<right)
		{
			int sum = block[left]+block[right];
			if(sum==x)
			{
				bb = true;
				cout << "yes " << block[left] << " " << block[right] << "\n";
				break;
			}
			else if(sum<x)
				left++;
			else
				right--;
		}
		if(!bb)
			cout << "danger" << "\n";
	}
	return 0;
}
