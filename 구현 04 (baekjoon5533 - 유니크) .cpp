//n*3개의 카드값을 입력받고 각 k번째카드마다 겹치는 사람이 없을 경우 점수를 얻고 겹칠경우 점수를 얻지 못하는 게임
//이중배열을 사용하여 모든 경우를 계산할수 있게 해준다.

#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	int n;
	cin >> n;

	int sum[n] = {};
	int a[n][3];
	for(int i=0;i<n;i++)
		for(int j=0;j<3;j++)
			cin >> a[i][j];

	for(int j=0;j<3;j++)
	{

		for(int i=0;i<n;i++)
		{
			bool same = false;
			for(int k=0;k<n;k++)
				if(i!=k&&a[i][j]==a[k][j])
					same = true;

			if(!same)
				sum[i]+=a[i][j];
		}
	}

	for(int i=0;i<n;i++)
		cout << sum[i] << "\n";
}
