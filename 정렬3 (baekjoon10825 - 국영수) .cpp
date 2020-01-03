//국어 점수, 수학 점수, 영어 점수, 이름을 입력받아 각 조건에 따라 역정렬 또는 정렬하기
#include <iostream>
#include <algorithm>

using namespace std;

struct student
{
	string name;
	int kor, math, eng;
};

bool bigger(const student &s1, const student &s2)
{
	if(s1.kor==s2.kor&&s1.eng==s2.eng&&s1.math==s2.math)
		return s1.name<s2.name;
	else if(s1.kor==s2.kor&&s1.eng==s2.eng)
		return s1.math>s2.math;
	else if(s1.kor==s2.kor)
		return s1.eng<s2.eng;
	return s1.kor>s2.kor;
}

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	student s[n];
	for(int i=0;i<n;i++)
		cin >> s[i].name >> s[i].kor >> s[i].eng >> s[i].math;

	sort(s, s+n, bigger);

	for(int i=0;i<n;i++)
		cout << s[i].name << "\n";
	return 0;
}
