//배열을 이용하여 큐 
#include <iostream>

using namespace std;
#define MAX 10000

class Queue
{
private:
	int a[MAX];
	int last;
	int first;

public:
	Queue();
	void push(int n);
	int pop();
	int size();
	bool empty();
	int front();
	int back();
};


int main()
{
	Queue q;
	int n;
	cin >> n;
	for(int i=0;i<n;i++)
	{
		string s;
		cin >> s;
		if(s=="push")
		{
			int x;
			cin >> x;
			q.push(x);
		}
		else if(s=="pop")
			cout << q.pop() << endl;
		else if(s=="size")
			cout << q.size() << endl;
		else if(s=="empty")
			cout << q.empty() << endl;
		else if(s=="front")
			cout << q.front() << endl;
		else if(s=="back")
			cout << q.back() << endl;
	}

	return 0;
}

Queue::Queue()
{
	last = 0;
	first = 0;
}

void Queue::push(int n)
{
	a[last] = n;
	last++;
}

int Queue::pop()
{
	if(last==first)
		return -1;
	else
		return a[first++];
}

int Queue::size()
{
	return last-first;
}

bool Queue::empty()
{
	return first==last;
}

int Queue::front()
{
	if(size()==0)
		return -1;
	return a[first];
}

int Queue::back()
{
	if(size()==0)
		return -1;
	return a[last-1];
}
