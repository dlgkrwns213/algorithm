//후보를 추천받고 추천을 일정 이상하면 가장 표가 적은 후보를 내려 마지막 추천사람들을 오른차순으로 출력하는 문제
//한번 후보에서 제외되면 추천 수가 0으로 초기화된다.

#include <iostream>
#include <algorithm>

using namespace std;

struct st
{
	int a, b, c;
};

int compare(const st &S1, const st &S2)
{
	if(S1.b==S2.b)
		return S1.c<S2.c;
	return S1.b<S2.b;
}
int compareA(const st &S1, const st &S2)
{
	return S1.a<S2.a;
}
int main()
{
	int n, m;
	cin >> n >> m;

	int p[m];
	for(int i=0;i<m;i++)
		cin >> p[i];

	st S[n];
	for(int i=0;i<n;i++)
		S[i].a = S[i].b = S[i].c = -1;

	for(int i=0;i<m;i++)
	{
		bool same = false;
		int index;
		for(int j=0;j<n;j++)
			if(S[j].a==p[i])
			{
				same = true;
				index = j;
			}
		if(same)
		{
			S[index].b++;
		}
		else
		{
			sort(S, S+n, compare);
			S[0] = {p[i], 1, i};
		}
	}
	sort(S, S+n, compareA);
	for(int i=0;i<n;i++)
		if(S[i].a!=-1)
			cout << S[i].a << " ";
}
