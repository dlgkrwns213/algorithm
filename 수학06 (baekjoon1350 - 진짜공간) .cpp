//vector를 이용하여 실제 메모리를 최소화하고 
//나누어떨어질때와 아닐때를 구분하여 사용메모리의 최솟값 구하기

#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int n;
	cin >> n;

	vector<long long> file;
	for(int i=0;i<n;i++)
	{
		int f;
		cin >> f;
		if(f!=0)
			file.push_back(f);
	}
	int fs = (int)file.size();

	long long disk;
	cin >> disk;

	long long all = 0;
	for(int i=0;i<fs;i++)
	{
		if(file[i]%disk==0)
			all += file[i];
		else
			all += (file[i]/disk+1)*disk;
	}
	cout << all;
}
