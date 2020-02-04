#include <iostream>

using namespace std;

int main()
{
	string str;
	int count = 0;
	int flag = 1;
	getline(cin, str);

	for(int i=0;i<(int)str.length();i++)
	{
		if(str[i]==' ')
			flag = 1;
		else if(flag==1)
		{
			count++;
			flag = 0;
		}
	}
	cout << count;
}
