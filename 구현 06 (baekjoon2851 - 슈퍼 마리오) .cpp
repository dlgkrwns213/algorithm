//각 버섯들을 입력받아 버섯의 값이 100과 가장 가까운 값을 얻을떄까지 버섯을 먹기로 함
//가까운 값이 두개인 경우 큰 값으로 설정한다

#include <iostream>

using namespace std;

int main()
{
	int a[10];
	for(int i=0;i<10;i++)
		cin >> a[i];

	int sum = 0;
	int index;
	bool up = false;
	for(int i=0;i<10;i++)
	{
		sum+=a[i];
		if(sum==100)
		{
			cout << 100;
			return 0;
		}
		if(sum>100)
		{
			up = true;
			index = i;
			break;
		}
	}
	if(!up)
		cout << sum;
	else
	{
		int A = 100-sum+a[index];
		int B = sum-100;
		if(A<B)
			cout << sum-a[index];
		else
			cout << sum;
	}
	return 0;
}
