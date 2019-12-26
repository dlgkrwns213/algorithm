//STL의 deque와 algorithm을 이용하여 문제 풀어보기
#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	int T;
	cin >> T;
	for(int t=0;t<T;t++)
	{
		string s;
		int n;
		cin >> s >> n;

		deque<int> dq;
		if(n==0)
		{
			char c1, c2;
			cin >> c1 >> c2;
		}
		else
		{
			char c;
			for(int i=0;i<n;i++)
			{
				int card;
				cin >> c >> card;
				dq.push_back(card);
			}
			cin >> c;
		}

		bool error = false;
		int Rcount = 0;
		for(int i=0;i<(int)s.size();i++)
		{
			if(s[i]=='R')
				Rcount++;
			else if(s[i]=='D')
			{
				if(dq.size()==0)
				{
					error=true;
					break;
				}
				else
				{
					if(Rcount%2==0)
						dq.pop_front();
					else
						dq.pop_back();
				}
			}
		}
		if(error)
			cout << "error" << endl;
		else
		{
			if(Rcount%2==1)
				reverse(dq.begin(), dq.end());
			int ds = (int)dq.size();
			if(ds==0)
				cout << "[]" << endl;
			else
			{
				cout << "[";
				for(int i=0;i<ds-1;i++)
				{
					cout << dq.front() << ",";
					dq.pop_front();
				}
				cout << dq.back() << "]" << endl;
			}
		}
	}


	return 0;
}
