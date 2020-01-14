//문자열에서 모든 문자로 부터 같은 거리만큼 떨어진 문자하나와 문자열을 이루었을때
//모든 문자열이 다른 경우 전체문자열은 놀라운 문자열이라고 한다.
//이때 문자열을 입력받아 놀라운 문자열인지 확인하여 출력하기

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	while(1)
	{
		string s;
		cin >> s;
		if(s=="*")
			return 0;
		bool no = false;
		for(int i=1;i<(int)s.size();i++)
		{
			vector<string> vs;
			string tmp;
			tmp.push_back(s[0]);
			tmp.push_back(s[i]);
			vs.push_back(tmp);
			tmp.clear();
			for(int j=1;j<(int)s.size()-i;j++)
			{
				tmp.push_back(s[j]);
				tmp.push_back(s[j+i]);
				vs.push_back(tmp);
				tmp.clear();
			}
			sort(vs.begin(), vs.end());

			for(int i=1;i<(int)vs.size();i++)
				if(vs[i-1]==vs[i])
				{
					no = true;
					break;
				}

			if(no)
				break;
		}

		cout << s << " is ";
		if(no)
			cout <<"NOT ";
		cout << "surprising." << endl;
	}
}
