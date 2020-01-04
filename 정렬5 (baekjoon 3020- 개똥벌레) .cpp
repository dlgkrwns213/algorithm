//번갈아 입력받아 석순과 종유석을 각각 정렬해준 후 각 층마다 추가되는 개수와 감소하는 개수를 더하고 뺴주어 값을 계산해줌
//min_element를 이용하여 최솟값을 얻음
#include <iostream>
#include <algorithm>

using namespace std;

bool re(const int &a, const int& b)
{
	return a<b;
}
int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, h;
	cin >> n >> h;
	int m = n/2;
	int floor[h+1]={}, roof[h+1]={};
	for(int i=0;i<m;i++)
	{
		int f, r;
		cin >> f >> r;
		floor[f]++;
		roof[r]++;
	}


	int count[h] = {};
	for(int i=1;i<h;i++)
		count[i] = count[i-1]-floor[i]+roof[h-i];

	int c = 0;
	int min = *min_element(count, count+h);
	for(int i=0;i<h;i++)
		if(count[i]==min)
			c++;
	cout << min+m << " " << c;

	return 0;
}
