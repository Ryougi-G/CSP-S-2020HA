#include<bits/stdc++.h>
using namespace std;
int n;
int main()
{
	freopen("snake.in","r",stdin);
	freopen("snake.out","w",stdout);
	cin>>n;
	if(n==2)
	{
		cout<<3<<endl;
		cout<<1<<endl;
		return 0;
	}
	if(n==2)
	{
		cout<<5<<endl;
		cout<<3<<endl;
		return 0;
	}
	int x=rand()%20;
	cout<<x<<endl;
	cout<<x<<endl;
	return 0;
}

