//구름이 몇분뒤에 오는지 확인해보기
//줄마다 계산을 하면 되므로 이중배열을 사용하지 않아도 

#include <iostream>

using namespace std;

int main()
{
	int w, h;
	cin >> h >> w;

	while(h--)
	{
		char cl[w];
		for(int i=0;i<w;i++)
			cin >> cl[i];

		int how[w];
		for(int i=0;i<w;i++)
		{
			if(cl[i]=='c')
			{
				how[i] = 0;
			}
			else
			{
				bool f = false;
				for(int j=i;j>=0;j--)
				{
					if(cl[j]=='c')
					{
						how[i] = i-j;
						f = true;
						break;
					}
				}
				if(!f)
					how[i] = -1;
			}
		}
		for(int i=0;i<w;i++)
			cout << how[i] << " ";
		cout << endl;
	}
}
