//암호문1->암호문2의 방식의 역순으로 저장된다
//=>암호문2->암호문1과 같은 방식으로 저장된다
//복호문을 위와 같은 방법으로 바꾸면 평문이 된다.
#include <iostream>

using namespace std;

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int T;
	cin >> T;
	while(T--)
	{
		int n;
		cin >> n;
		string s1[n];
		for(int i=0;i<n;i++)
			cin >> s1[i];
		string s2[n];
		for(int i=0;i<n;i++)
			cin >> s2[i];

		string code[n];
		for(int i=0;i<n;i++)
			cin >> code[i];
		string made[n];

		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				if(s1[i]==s2[j])
				{
					made[i] = code[j];
				}

		for(int i=0;i<n;i++)
			cout << made[i] << " ";
		cout << "\n";
	}
}
