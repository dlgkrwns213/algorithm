#include<iostream>
using namespace std;
int main(){
	int n,a,s=0;
	cin>>n;
	while(n--){cin >> a;s+=abs(a);}
	cout << 2*s;
}
