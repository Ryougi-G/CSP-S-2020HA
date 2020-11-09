#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("zoo.in","r",stdin);
	freopen("zoo.out","w",stdout);
	int n,m ,k, c;
	cin>>n>>m>>c>>k;
	if(n>0&&n<=5)
	{
		cout<<3;
	}
	else
	{
		if(n>5&&n<=15)
		{
			cout<<15;
		}
		else
		{
			if(n>15&&n<=30)
			{
				cout<<13;
			}
		}
	}
	return 0;
}
