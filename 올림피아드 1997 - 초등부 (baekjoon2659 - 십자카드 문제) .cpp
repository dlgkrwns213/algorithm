#include <iostream>

using namespace std;

int watch(int a, int b, int c, int d);
int main()
{
	int a, b, c, d;
	cin >> a >> b >> c >> d;

	int n = watch(a, b, c, d);

	int count = 1;
	for(int i=1111;;i++)
	{
		int tmp = i;
		int A = tmp/1000;
		int B = tmp/100%10;
		int C = tmp/10%10;
		int D = tmp%10;
		if(watch(A, B, C, D)==n)
		{
			cout << count;
			return 0;
		}

		if(watch(A, B, C, D)==i)
			count++;
	}
}

int watch(int a, int b, int c, int d)
{
	if(a==0||b==0||c==0||d==0)
		return -1;

	int tmp1 = min(a*1000+b*100+c*10+d, b*1000+c*100+d*10+a);
	int tmp2 = min(c*1000+d*100+a*10+b, d*1000+a*100+b*10+c);
	int m = min(tmp1, tmp2);

	return m;
}
