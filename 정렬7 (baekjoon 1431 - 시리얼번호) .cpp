//sort함수를 이용하여 각 조건에 맞게 정렬해주는 문제
//아스키코드에서 숫자값들이 영대문자 값들보다 작으므로 사전 순은 string비교를 통하여 return값을 설정해준다.
#include <iostream>
#include <algorithm>

using namespace std;

bool compare(const string &s1, const string &s2)
{
	if(s1.size()==s2.size())
	{
		int ss = s1.size();
		int count1 = 0;
		for(int i=0;i<ss;i++)
			if(s1[i]>='0'&&s1[i]<='9')
				count1 += s1[i]-'0';
		int count2 = 0;
		for(int i=0;i<ss;i++)
			if(s2[i]>='0'&&s2[i]<='9')
				count2 += s2[i]-'0';
		if(count1==count2)
		{
			return s1<s2;
		}
		return count1<count2;
	}
	return s1.size()<s2.size();
}

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	string s[n];
	for(int i=0;i<n;i++)
		cin >> s[i];

	sort(s, s+n, compare);
	for(int i=0;i<n;i++)
		cout << s[i] << "\n";

	return 0;
}
