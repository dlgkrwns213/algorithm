#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	double a, b, c;
	double i, j, k;

	cin >> a >> b >> c;
	cin >> i >> j >> k;

	double d[3];
	d[0] = a/i;
	d[1] = b/j;
	d[2] = c/k;

	double m = *min_element(d, d+3);

	double ta = i*m, tb = j*m, tc = k*m;

	cout << fixed;
	cout.precision(4);
	cout << a-ta << " " << b-tb << " " << c-tc;

}
