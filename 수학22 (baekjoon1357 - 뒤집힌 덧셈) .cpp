#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int main()
{
	string s1, s2;
	cin >> s1 >> s2;

	reverse(s1.begin(), s1.end());
	reverse(s2.begin(), s2.end());

	int i1 = stoi(s1);
	int i2 = stoi(s2);

	int i3 = i1+i2;
	string s3 = to_string(i3);

	reverse(s3.begin(), s3.end());
	i3 = stoi(s3);
	cout << i3;

	return 0;
}
