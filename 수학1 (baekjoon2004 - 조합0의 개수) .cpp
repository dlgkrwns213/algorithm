//함수를 이용하여 코드를 간단하고 짧게 사용
//nCr = n!/(n-r)!*r!이란 것과 10 = 2*5라는 것을 이용하여 2의 개수와 5의 개수중 작은 값을 결과값으로 출력해준다.
#include <iostream>

using namespace std;

long long getNum(long long n, int k)
{
	long long count = 0;
	for(long long i=k;i<=n;i*=k)
		count += n/i;
	return count;
}

int main()
{
	long long n, m;
	cin >> n >> m;

	long long two_count = getNum(n, 2)-getNum(m, 2)-getNum(n-m ,2);
	long long five_count = getNum(n, 5)-getNum(m, 5)-getNum(n-m, 5);
	cout << min(two_count, five_count);
	return 0;
}
