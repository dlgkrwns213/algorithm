//한줄의 string값과 정수값 을 입력받고 입력받은 값이 정수값만큼의 IOI값이 몇개있는지 확인해보기
//시간주의
//하나하나 찾는 방법 : 매우 느림 //O(mn)의 시간
#include <iostream>

using namespace std;

string p;
void makePn(int n);
int main()
{
	int n, m;
	cin >> n >> m;
	string s;
	cin >> s;
	makePn(n);
	int count = 0;
	for(int i=0;i<m-p.size();i++)
	{
		bool same = true;
		for(int j=0;j<p.size();j++)
		{
			if(s[i+j]!=p[j])
			{
				same = false;
				break;
			}
		}
		if(same)
			count++;
	}
	cout << count;

	return 0;
}

void makePn(int n)
{
	p.push_back('I');
	for(int i=0;i<n;i++)
	{
		p.push_back('O');
		p.push_back('I');
	}
}

//IOIOI를 찾아서 수를 세어준다 //O(m)의 시간
#include <iostream>

using namespace std;

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	int n, m;
	string s;
	cin >> n >> m >> s;

	int count = 0;
	for(int i=0;i<m;i++)
	{
		if(s[i]=='I')
		{
			string ioi;
			ioi.push_back('I');
			int j=0;
			while(1)
			{
				if(s[i+j+1]=='O'&&s[i+j+2]=='I')
				{
					ioi.push_back('O');
					ioi.push_back('I');
					j+=2;
				}
				else
				{
					i+=j;
					break;
				}
			}
			int ss = (int)ioi.size()/2+1;
			if(ss>n)
				count += ss-n;
		}
	}
	cout << count;
	return 0;
}
