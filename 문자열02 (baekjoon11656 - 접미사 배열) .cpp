//string이 vector처럼 push_back() 함수가 있어서 뒤에 덧붙이는것이 가능하다를 이용하여 접미사들을 만들어주고 
//이 접미사들을 string형 vector에 추가해준 후 sort를 이용하여 사전순으로 정렬시켜준다.

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	string s;
	cin >> s;
	int n = (int)s.size();

	vector<string> vs;
	for(int i=0;i<n;i++)
	{
		string tmps;
		for(int j=i;j<n;j++)
			tmps.push_back(s[j]);
		vs.push_back(tmps);
	}

	sort(vs.begin(), vs.end());
	for(int i=0;i<n;i++)
		cout << vs[i] << "\n";
	return 0;
}
