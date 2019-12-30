//최대 힙과 같은 방법으로 풀어보았다.
#include <iostream>
#include <queue>

using namespace std;

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	priority_queue<int, vector<int>, greater<int> > pq;
	int n;
	cin >> n;

	for(int i=0;i<n;i++)
	{
		int m;
		cin >> m;
		if(m==0)
			if(pq.empty())
				cout << 0 << "\n";
			else
			{
				cout << pq.top() << "\n";
				pq.pop();
			}
		else
			pq.push(m);
	}

	return 0;
}
