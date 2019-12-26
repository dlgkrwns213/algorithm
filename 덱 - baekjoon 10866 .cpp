//배열을 이용하여 덱 만들어보기
#include <iostream>

using namespace std;
#define MAX 20000

class Deque
{
private:
	int a[MAX];
	int first;
	int last;

public:
	Deque();
	void push_front(int x);
	void push_back(int x);
	int pop_front();
	int pop_back();
	int size();
	bool empty();
	int front();
	int back();
	void print()
	{
		cout << "s : " << size() << endl;
		for(int i=first;i<last;i++)
			cout << a[i] << " ";
	}
};

int main()
{
	Deque dq;
	int n;
	cin >> n;
	for(int i=0;i<n;i++)
	{
		string s;
		cin >> s;
		if(s=="push_front")
		{
			int x;
			cin >> x;
			dq.push_front(x);
		}
		else if(s=="push_back")
		{
			int x;
			cin >> x;
			dq.push_back(x);
		}
		else if(s=="pop_front")
			cout << dq.pop_front() << endl;
		else if(s=="pop_back")
			cout << dq.pop_back() << endl;
		else if(s=="size")
			cout << dq.size() << endl;
		else if(s=="empty")
			cout << dq.empty() << endl;
		else if(s=="front")
			cout << dq.front() << endl;
		else if(s=="back")
			cout << dq.back() << endl;
		else
			dq.print();
	}
	return 0;
}

Deque::Deque()
{
	first = 10000;
	last = 10000;
}


void Deque::push_front(int x)
{
	a[--first] = x;
}

void Deque::push_back(int x)
{
	a[last++] = x;
}

int Deque::pop_front()
{
	if(size()==0)
		return -1;
	else
		return a[first++];
}

int Deque::pop_back()
{
	if(size()==0)
		return -1;
	else
		return a[--last];
}

int Deque::size()
{
	return last-first;
}

bool Deque::empty()
{
	return size()==0;
}

int Deque::front()
{
	if(size()==0)
		return -1;
	return a[first];
}

int Deque::back()
{
	if(size()==0)
		return -1;
	return a[last-1];
}
