//정렬을 이용하여 index값을 하나씩 늘려가며 풀기와 문자열의 개수를 하나하나 값을 저장하여 풀어보았다.
//정렬을 이용
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	string s1, s2;
	cin >> s1 >> s2;
	sort(s1.begin(), s1.end());
	sort(s2.begin(), s2.end());
	int count = 0;
	int i=0, j=0;
	while(1)
	{
		if(s1[i]==s2[j])
		{
			i++;
			j++;
		}
		else if(s1[i]>s2[j])
		{
			count++;
			j++;
		}
		else
		{
			count++;
			i++;
		}
		if(i>=(int)s1.size()||j>=(int)s2.size())
		{
			count += (s1.size()-i+s2.size()-j);
			break;
		}
	}
	cout << count;


	return 0;
}


//문자개수를 모두 저장하기 - 정렬보다 짧은 시간이지만 보다 큰 메모리 사용
#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	string s1, s2;
	cin >> s1 >> s2;
	int a1[26] = {}, a2[26] = {};

	for(int i=0;i<(int)s1.size();i++)
		a1[s1[i]-'a']++;
	for(int i=0;i<(int)s2.size();i++)
		a2[s2[i]-'a']++;

	int count = 0;
	for(int i=0;i<26;i++)
		count += abs(a1[i]-a2[i]);

	cout << count;

	return 0;
}

