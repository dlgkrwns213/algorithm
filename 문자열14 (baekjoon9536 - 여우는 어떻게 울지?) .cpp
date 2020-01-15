//case의 수를 입력받고 각 case마다 첫줄로 여러동물의 울음소리가 나온다.
//그 뒤로 "동물" "goes" "울음소리"형태로 입력값을 주고 이 울음소리들을 없애서 위에 나오는 울음소리중 여우의 울음소리를 찾는 문제
//getline의 경우 cin으로 입력받고 다음으로 입력을 받아도 줄로 인식을 받기 때문에 입력이 또 들어오게 되서 trash를 통해 이를 막아주었다.
//vector를 통해 값을 저장해주고 여우의 울음소리가 아닌 것들은 nofox로 저장해준다.

#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int T;
	cin >> T;
	while(T--)
	{
		string trash;
		getline(cin, trash);
		string s;
		getline(cin, s);
		vector<string> speak;
		string tmp;
		for(int i=0;i<(int)s.size();i++)
		{
			if(s[i]==' ')
			{
				speak.push_back(tmp);
				tmp.clear();
			}
			else
				tmp.push_back(s[i]);
			if(i==(int)s.size()-1)
				speak.push_back(tmp);
		}
		while(1)
		{
			string animal, goes, spoke;
			cin >> animal >> goes;
			if(goes!="goes")
			{
				string a, b, c;
				cin >> a >> b >> c;
				break; //쓰레기값 무시
			}
			cin >> spoke;
			for(int i=0;i<(int)speak.size();i++)
			{
				if(speak[i]==spoke)
					speak[i] = "nofox";
			}
		}
		for(int i=0;i<(int)speak.size();i++)
		{
			if(speak[i]!="nofox")
				cout << speak[i] << " ";
		}
		cout << endl;
	}
	return 0;
}
