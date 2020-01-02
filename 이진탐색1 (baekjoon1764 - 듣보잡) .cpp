//string의 크기 비교
//string 크기 비교를 이용한 string배열 정렬
//정렬된 배열과 string 크기 비교를 이용한 이진탐색
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void find(string* NoSee, int first, int last, string s, bool& f)
{
	if(first>last)
		return;
	else
	{
		int mid = (first+last)/2;
		if(NoSee[mid]>s)
			find(NoSee, first, mid-1, s, f);
		else if(NoSee[mid]==s)
			f = true;
		else
			find(NoSee, mid+1, last, s, f);
	}
}

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;

	string NoSee[n];

	for(int i=0;i<n;i++)
		cin >> NoSee[i];

	sort(NoSee, NoSee+n);

	vector<string> No;
	for(int j=0;j<m;j++)
	{
		string s;
		cin >> s;
		bool f = false;
		find(NoSee, 0, n-1, s, f);
		if(f)
			No.push_back(s);
	}

	sort(No.begin(), No.end());
	int ns = (int)No.size();
	cout << ns << "\n";
	for(int i=0;i<ns;i++)
		cout << No[i] << "\n";

	return 0;
}
