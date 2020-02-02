#include <iostream>
#include <string>
#include <cmath>

using namespace std;

bool palin(int n);
bool prime(int n);
int main()
{
	int k;
	cin >> k;

	for(int i=k;;i++)
	{
		bool pa = palin(i);
		bool pr = prime(i);
		if(pa&&pr)
		{
			cout << i;
			return 0;
		}
	}
}

bool palin(int n)
{
	string s = to_string(n);
	int left = 0;
	int right = (int)s.size();
	while(left<right)
	{
		if(s[left]!=s[right-1])
			return false;
		left++;
		right--;
	}
	return true;
}

bool prime(int n)
{
	if(n==1)
		return false;
	for(int i=2;i<=sqrt(n);i++)
		if(n%i==0)
			return false;
	return true;
}
