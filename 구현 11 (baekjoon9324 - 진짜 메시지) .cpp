//메시지에서 같은 문자가 3번 나올때마다 그 같은 문자를 한번 더 써주는 것을 암호로 한다.
//이때 메시지가 암호문인지 확인해준다.
//알파벳의 수를 세주는 배열을 만들어서 계산해준다.

#include <iostream>
#include <vector>

using namespace std;

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	int n;
	cin >> n;
	while(n--)
	{
		string s;
		cin >> s;
		int alpha[26] = {};

		bool real = true;
		for(int i=0;i<(int)s.size();i++)
		{
			int now = s[i]-'A';
			alpha[now]++;

			if(alpha[now]==3)
			{
				if(i==(int)s.size()-1||s[i+1]!=s[i])
				{
					real = false;
					break;
				}
				i++;
				alpha[now] = 0;
			}
		}
		if(real)
			cout << "OK\n";
		else
			cout << "FAKE\n";
	}
}
