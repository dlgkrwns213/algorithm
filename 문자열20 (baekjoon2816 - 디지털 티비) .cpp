#include <iostream>

using namespace std;

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;

	string s[n];
	int one, two;
	for(int i=0;i<n;i++)
	{
		cin >> s[i];
		if(s[i]=="KBS1")
			one = i;
		else if(s[i]=="KBS2")
			two = i;
	}

	int index;
	for(int i=0;;i++)
	{
		if(s[i]=="KBS1")
		{
			index = i;
			break;
		}
		cout << 1;
	}
	while(index--)
		cout << 4;

	if(one>two)
	{
		s[two+1] = "KBS2";
		s[two] = "NO";
	}
	if(s[1]=="KBS2")
		return 0;

	for(int i=0;;i++)
	{
		if(s[i]=="KBS2")
		{
			index = i-1;
			break;
		}
		cout << 1;
	}
	while(index--)
		cout << 4;
}
