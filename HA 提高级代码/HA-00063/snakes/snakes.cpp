#include<bits/stdc++.h>
using namespace std;
int snake[10];
int nummax,nummin,numsecond,maxa=-1,mina=100000,secondmax,n,change1,change2,t;
int ans;
int juedou(int x){
	for(int i=1;i<=x;i++)
	{
		if(snake[i]>=maxa)
		{
			maxa=snake[i];
			nummax=i;
		}
	}
	for(int i=n;i>=1;i--)
	{
		if(snake[i]<=mina)
		{
			mina=snake[i];
			nummin=i;
		}
	}
	for(int i=1;i<=x;i++)
	{
		if(i!=nummax&&i!=nummin)
		{
			secondmax=snake[i];
			numsecond=i;
		}
	}
	if(maxa-mina>secondmax){
		ans=1;
	}
	else if(maxa-mina==secondmax&&nummax>numsecond){
		ans=1;
	}
	else ans=3;
	cout<<ans;
	maxa=-1;
	mina=100000;
}
int main()
{
	freopen("snakes.in","r",stdin);
	freopen("snakes.out","w",stdout);
	cin>>t;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>snake[i];
	}
	juedou(n);
    for(int i=2;i<=t;i++)
    {
    	for(int j=1;j<=n;j++)
    	{
    		cin>>change1>>change2;
    	    snake[change1]=change2;
    	}
    	juedou(n);
    }
    return 0;
}
