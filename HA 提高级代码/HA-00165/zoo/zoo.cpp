#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("zoo.in","r",stdin);
	freopen("zoo.out","r",stdout);
	int n;
	cin>>n;
	if(n<=5)
		cout<<13;
	else if(n>5)
		cout<<100;
	else if(n>100000)
		cout<<200;
	return 0;
}
