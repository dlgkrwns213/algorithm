//주어진 나라와 각 나라의 금, 은, 동메달의 수를 입력받고 특정 나라의 순위를 구하는 문제
//등수는 자신 나라보다 메달이 금, 은, 동메달이 많은 나라+1로 한다.

#include <iostream>

using namespace std;

struct medal
{
	int x, y, z;
};
int main()
{
	int n, k;
	cin >> n >> k;

	medal m[n+1];
	for(int i=0;i<n;i++)
	{
		int p;
		cin >> p;
		cin >> m[p].x >> m[p].y >> m[p].z;
	}

	int count = 1;
	for(int i=1;i<=n;i++)
		if(m[i].x>m[k].x)
			count++;
	for(int i=1;i<=n;i++)
		if(m[i].x==m[k].x&&m[i].y>m[k].y)
			count++;
	for(int i=1;i<=n;i++)
		if(m[i].x==m[k].x&&m[i].y==m[k].y&&m[i].z>m[k].z)
			count++;
	cout << count;
}
