#include <iostream>
#include <stack>

using namespace std;

struct ci
{
	char c;
	int i;
};
int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	string s, bomb;
	cin >> s >> bomb;
	int ss=(int)s.size(), bs=(int)bomb.size();

	stack<ci> st;

	for(int i=0;i<ss;i++)
	{
		st.push({s[i], i});

		int sts = st.size();
		if(sts>=bs&&s[i]==bomb.back())
		{
			stack<ci> tmp;
			bool yes = true;
			for(int j=0;j<bs;j++)
			{
				tmp.push(st.top());
				if(bomb[bs-j-1]!=st.top().c)
					yes = false;
				st.pop();
			}

			if(yes)
				for(int j=0;j<bs;j++)
				{
					s[tmp.top().i] = '-';
					tmp.pop();
				}
			else
			{
				for(int j=0;j<bs;j++)
				{
					st.push(tmp.top());
					tmp.pop();
				}
			}
		}
	}

	bool no_word = true;
	for(int i=0;i<ss;i++)
		if(s[i]!='-')
		{
			no_word = false;
			cout << s[i];
		}
	if(no_word)
		cout << "FRULA";
}
