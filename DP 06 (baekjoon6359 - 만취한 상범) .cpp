//1부터 n까지 배수일때 문이 열렸을 경우 닫고, 닫혔을 경우 열어주는 행위를 반복하여 탈출 가능한 방의 수 구하기
//bool배열을 사용하여 메모리 사용의 최소화시켜준다.
//내부 for문의 횟수를 최소화하여 사용시간을 최소화시켜준다.

#include <iostream>

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
		int n;
		cin >> n;
		bool room[n+1] = {};
		for(int i=1;i<=n;i++)
			for(int j=i;j<=n;j+=i)
			{
				if(room[j])
					room[j] = false;
				else
					room[j] = true;
			}

		int count = 0;
		for(int i=1;i<=n;i++)
			count+=room[i];
		cout << count << "\n";
	}
}
