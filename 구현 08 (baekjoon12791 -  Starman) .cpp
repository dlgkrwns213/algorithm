//입력값을 코드를 통해 넣어서 입력하고 
//시작년도와 끝년도를 입력받아 그 사이에 낸 앨범을 출력하기

#include <iostream>

using namespace std;

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	pair<int, string> p[25];
	p[0] = {1967, "DavidBowie"};
	p[1] = {1969, "SpaceOddity"};
	p[2] = {1970, "TheManWhoSoldTheWorld"};
	p[3] = {1971, "HunkyDory"};
	p[4] = {1972, "TheRiseAndFallOfZiggyStardustAndTheSpidersFromMars"};
	p[5] = {1973, "AladdinSane"};
	p[6] = {1973, "PinUps"};
	p[7] = {1974, "DiamondDogs"};
	p[8] = {1975, "YoungAmericans"};
	p[9] = {1976, "StationToStation"};
	p[10] = {1977, "Low"};
	p[11] = {1977, "Heroes"};
	p[12] = {1979, "Lodger"};
	p[13] = {1980, "ScaryMonstersAndSuperCreeps"};
	p[14] = {1983, "LetsDance"};
	p[15] = {1984, "Tonight"};
	p[16] = {1987, "NeverLetMeDown"};
	p[17] = {1993, "BlackTieWhiteNoise"};
	p[18] = {1995, "1.Outside"};
	p[19] = {1997, "Earthling"};
	p[20] = {1999, "Hours"};
	p[21] = {2002, "Heathen"};
	p[22] = {2003, "Reality"};
	p[23] = {2013, "TheNextDay"};
	p[24] = {2016, "BlackStar"};

	int T;
	cin >> T;
	while(T--)
	{
		int start, finish;
		cin >> start >> finish;
		int si = 25, fi = -1;
		for(int i=0;i<25;i++)
			if(p[i].first>=start)
			{
				si = i;
				break;
			}
		for(int i=24;i>=0;i--)
			if(p[i].first<=finish)
			{
				fi = i;
				break;
			}
		int tmp = fi-si+1;
		if(tmp<0)
			cout << 0 << "\n";
		else
			cout << fi-si+1 << "\n";
		for(int i=si;i<=fi;i++)
			cout << p[i].first << " " << p[i].second << "\n";
	}
}
