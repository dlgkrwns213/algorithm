//주관식 점수를 총점을 n*(n-1)/2로 하고 두개씩 골라서 두개의 순서관계가 맞을 경우 1점으로 하여 점수를 냈을때 점수를 출력하는 문제
//index(index는 일의 순서와 동일하다)을 pair로 하여 같이 입력받은 후 string값에 따라 정렬해준 후 이진탐색을 통하여 쓴 답(string)값을 int로 바꿔준다.
//앞에 있는 수보다 뒤에 있는 수가 클 경우 순서관계가 맞는 것이므로 점수를 올려줘서 을 계산해준다.

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(const pair<string, int> &p1, const pair<string, int> &p2)
{
	return p1.first<p2.first;
}

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;

	vector<pair<string, int> > correct;
	for(int i=0;i<n;i++)
	{
		string tmps;
		cin >> tmps;
		correct.push_back({tmps, i});
	}
	sort(correct.begin(), correct.end(), compare);

	int ai[n];
	for(int i=0;i<n;i++)
	{
		string answer;
		cin >> answer;
		int start = 0;
		int last = n-1;
		while(start<=last)
		{
			int mid = (start+last)/2;
			if(answer<correct[mid].first)
				last = mid-1;
			else if(answer>correct[mid].first)
				start = mid+1;
			else
			{
				ai[i] = correct[mid].second;
				break;
			}
		}
	}

	int count = 0;
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
			if(ai[j]-ai[i]>0)
				count++;
	}
	cout << count << "/" << n*(n-1)/2;
}
