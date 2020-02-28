#include <iostream>
#include <stack>

using namespace std;

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	int T;
	cin >> T;

	int count = 0;
	while(T--)
	{
		string s;
		cin >> s;
		int ss = (int)s.size();

		stack<char> st;
		for(int i=0;i<ss;i++)
		{
			if(st.empty()||st.top()!=s[i])
				st.push(s[i]);
			else
				st.pop();
		}
		if(st.size()==3)
			continue;
		if(st.empty())
			count++;
	}
	cout << count;
}
