//1부터 n까지 자릿수의 개수를 구하는 문제

//하나하나 전부 세어주는 방식
#include <iostream>
#include <string>

using namespace std;

int main()
{
	int n;
	cin >> n;

	int count[10] = {};
	for(int i=1;i<=n;i++)
	{
		string s = to_string(i);
		for(int i=0;i<s.size();i++)
			count[s[i]-'0']++;
	}

	for(int i=0;i<10;i++)
		cout << count[i] << " ";
	return 0;
}

//최댓값 1000000000을 하기에는 시간제한이 걸리게 된다.
//=>자릿수별로 나누어 계산해준다.
#include <iostream>
#include <string>

using namespace std;

int ten(int n)
{
	int k = 1;
	for(int i=0;i<n;i++)
		k *= 10;
	return k;
}

int main()
{
	string s;
	cin >> s;

	int count[10] = {};
	int ss = (int)s.size();
	int how = ss-1;

	for(int i=0;i<ss;i++)
	{
		int m = s[i]-'0';
		if(i==0)
		{
			for(int j=2;j<=how;j++)
				count[0] += 9*ten(j-2)*(j-1);
			for(int j=1;j<10;j++)
				count[j] += ten(how-1)*how;

			for(int j=2;j<=m;j++)
			{
				for(int k=0;k<10;k++)
					count[k] += ten(how-1)*how;
				count[j-1] += ten(how);
			}
		}
		else
		{
			for(int j=0;j<i;j++)
				count[s[j]-'0'] += m*ten(how-i);
			for(int j=1;j<=m;j++)
			{
				for(int k=0;k<10;k++)
					count[k] += ten(how-1-i)*(how-i);
				count[j-1] += ten(how-i);
			}

		}
		count[m]++;
	}

	for(int i=0;i<10;i++)
		cout << count[i] << " ";

	return 0;
}
