//STL의 queue와 vector를 이용하여 문제 풀어보기
#include <iostream>
#include <queue>

using namespace std;

int main()
{
	int T;
	cin >> T;
	for(int t=0;t<T;t++)
	{
		int n, m;
		cin >> n >> m;
		int ipt[n];
		for(int i=0;i<n;i++)
			cin >> ipt[i];

		int import[10] = {0};
		queue<pair<int, int> > q;
		int count=0;
		for(int i=0;i<n;i++)
		{
			if(ipt[m]<ipt[i])
				count++;
			import[ipt[i]]++;
			q.push({ipt[i], i});
		}

		for(int j=9;j>ipt[m];j--)
		{
			while(import[j]!=0)
			{
				if(q.front().first==j)
				{
					import[j]--;
					q.pop();
				}
				else
				{
					int f = q.front().first;
					int s = q.front().second;
					q.push({f, s});
					q.pop();
				}
			}
		}

		while(1)
		{
			if(q.front().first<ipt[m])
			{
				q.pop();
				continue;
			}
			count++;
			if(q.front().second==m)
				break;
			q.pop();
		}
		cout << count << endl;
	}
	return 0;
}
