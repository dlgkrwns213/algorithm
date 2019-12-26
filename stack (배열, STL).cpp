//배열을 이용한 스택만들기 (baekjoon 10828)
#include <iostream>

using namespace std;
#define MAX 10000

class Stack
{
private:
	int a[MAX];
	int StackSize;

public:
	Stack();
	void push(int n);
	int pop();
	int size();
	bool empty();
	int top();
};

int main()
{
	Stack s;
	int n;
	cin >> n;
	for(int i=0;i<n;i++)
	{
		string command;
		cin >> command;
		if(command=="push")
		{
			int x;
			cin >> x;
			s.push(x);
		}
		else if(command=="pop")
			cout << s.pop() << endl;
		else if(command=="size")
			cout << s.size() << endl;
		else if(command=="empty")
			cout << s.empty() << endl;
		else if(command=="top")
			cout << s.top() << endl;
	}

	return 0;
}

Stack::Stack()
{
	StackSize = 0;
}

void Stack::push(int n)
{
	a[StackSize] = n;
	StackSize++;
}

int Stack::pop()
{
	if(StackSize==0)
		return -1;
	else
	{
		StackSize--;
		return a[StackSize];
	}
}

int Stack::size()
{
	return StackSize;
}

bool Stack::empty()
{
	return StackSize==0;
}

int Stack::top()
{
	if(StackSize==0)
		return -1;
	else
		return a[StackSize-1];
}


//STL의 stack을 이용하여 문제 풀기
//1. 균형잡힌세상(괄호계산) - baekjoon 4949
#include <iostream>
#include <stack>

using namespace std;

int main()
{
	while(1)
	{
		string s;
		getline(cin, s);
		if(s[0]=='.')
			break;
		int n = (int)s.size();
		stack<char> st;
		bool balance = true;
		for(int i=0;i<n&&balance;i++)
		{
			if(s[i]=='('||s[i]=='[')
				st.push(s[i]);
			else if(s[i]==')')
			{
				if(st.empty())
					balance = false;
				else
				{
					char tmpc = st.top();
					balance = tmpc=='(';
					st.pop();
				}
			}
			else if(s[i]==']')
			{
				if(st.empty())
					balance = false;
				else
				{
					char tmpc = st.top();
					balance = tmpc=='[';
					st.pop();
				}
			}
		}
		if(!balance)
			cout << "no" << endl;
		else if(st.empty())
			cout << "yes" << endl;
		else
			cout << "no" << endl;
	}
	return 0;
}


//2. 오큰수 - baekjoon 17298
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main()
{
	cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	vector<int> a(n), re(n, -1);
	stack<int> st;

	for(int i=0;i<n;i++)
		cin >> a[i];

	for(int i=n-1;i>=0;i--)
	{
		while(!st.empty()&&st.top()<=a[i])
			st.pop();
		if(!st.empty())
			re[i] = st.top();

		st.push(a[i]);
	}
	for(int i=0;i<n;i++)
		cout << re[i] << " ";

	return 0;
}
