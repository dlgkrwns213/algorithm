#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

struct XY
{
	int x, y;
};
int main()
{
	XY xy[3];
	for(int i=0;i<3;i++)
		cin >> xy[i].x >> xy[i].y;

	bool can = true;
	for(int i=0;i<3;i++)
		for(int j=0;j<i;j++)
			if(xy[i].x==xy[j].x&&xy[i].y==xy[j].y)
				can = false;

	if(!can)
	{
		cout << -1;
		return 0;
	}

	int ONE = (xy[1].x-xy[0].x)*(xy[2].y-xy[0].y);
	int TWO = (xy[2].x-xy[0].x)*(xy[1].y-xy[0].y);
	if(ONE==TWO)
	{
		cout << -1;
		return 0;
	}

	double d[3];
	d[0] = sqrt((xy[1].x-xy[2].x)*(xy[1].x-xy[2].x)+(xy[1].y-xy[2].y)*(xy[1].y-xy[2].y));
	d[1] = sqrt((xy[0].x-xy[2].x)*(xy[0].x-xy[2].x)+(xy[0].y-xy[2].y)*(xy[0].y-xy[2].y));
	d[2] = sqrt((xy[1].x-xy[0].x)*(xy[1].x-xy[0].x)+(xy[1].y-xy[0].y)*(xy[1].y-xy[0].y));

	double M = *max_element(d, d+3);
	double m = *min_element(d, d+3);

	cout << fixed;
	cout.precision(10);
	cout << 2*(M-m);
}
