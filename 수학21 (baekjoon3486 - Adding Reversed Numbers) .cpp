#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	int T;
	cin >> T;

	while(T--)
	{
		string a, b;
		cin >> a >> b;

		reverse(a.begin(), a.end());
		reverse(b.begin(), b.end());

		int i = stoi(a)+stoi(b);
		string s = to_string(i);

		reverse(s.begin(), s.end());
		cout << stoi(s) << "\n";
	}
}
