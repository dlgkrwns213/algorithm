//문자열을 입력받아서 자신을 뒤집은 문자열이 있는지 확인하는문제 (팰린드롬인 경우 자기 자신이다)
//그 문자열의 길이와 가운데 문자를 출력하기
#include <iostream>

using namespace std;

int main()
{
	int n;
	cin >> n;

	string file[n];
	for(int i=0;i<n;i++)
		cin >> file[i];

	for(int i=0;i<n;i++)
	{
		for(int j=0;j<=i;j++)
		{
			if(file[i].size()==file[j].size())
			{
				int fs = (int)file[i].size();
				bool fin=true;
				for(int k=0;k<fs;k++)
				{
					if(file[i][k]!=file[j][fs-k-1])
					{
						fin = false;
						break;
					}
				}
				if(fin)
				{
					cout << fs << " " << file[i][fs/2];
					return 0;
				}
			}
		}
	}
}
