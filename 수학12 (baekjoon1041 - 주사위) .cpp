#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	long long n;
	cin >> n;
	long long dice[6];
	for(int i=0;i<6;i++)
		cin >> dice[i];
	if(n==1)
	{
		long long count = 0;
		for(int i=0;i<6;i++)
			count += dice[i];
		cout << count - *max_element(dice, dice+6);
		return 0;
	}
	long long one_min = *min_element(dice, dice+6);
	long long three[8];
	three[0] = dice[0]+dice[1]+dice[2];//ABC
	three[1] = dice[0]+dice[1]+dice[3];//ABD
	three[2] = dice[0]+dice[2]+dice[4];//ACE
	three[3] = dice[0]+dice[3]+dice[4];//ADE
	three[4] = dice[1]+dice[2]+dice[5];//BCF
	three[5] = dice[1]+dice[3]+dice[5];//BDF
	three[6] = dice[2]+dice[4]+dice[5];//CEF
	three[7] = dice[3]+dice[4]+dice[5];//DEF
	long long three_min = *min_element(three, three+8);

	long long two[12];
	two[0] = dice[0]+dice[1]; //AB
	two[1] = dice[0]+dice[2]; //AC
	two[2] = dice[0]+dice[3]; //AD
	two[3] = dice[0]+dice[4]; //AE
	two[4] = dice[1]+dice[2]; //BC
	two[5] = dice[1]+dice[3]; //BD
	two[6] = dice[2]+dice[4]; //CE
	two[7] = dice[3]+dice[4]; //DE
	two[8] = dice[1]+dice[5]; //BF
	two[9] = dice[2]+dice[5]; //CF
	two[10] = dice[3]+dice[5]; //DF
	two[11] = dice[4]+dice[5]; //EF
	long long two_min = *min_element(two, two+12);

	long long count =  4*three_min + (8*n-12)*two_min + (4*(n-1)*(n-2)+(n-2)*(n-2))*one_min ;
	cout << count;

	return 0;
}
