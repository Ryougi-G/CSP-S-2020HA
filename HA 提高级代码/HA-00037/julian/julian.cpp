#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
using namespace std;
int a1[13]={0,31,28,31,30,31,30,31,31,30,31,30,31},a2[13]={0,31,29,31,30,31,30,31,31,30,31,30,31};
pii t1[400],t2[400];//t1 28 t2 29
int main()
{
	freopen("julian.in","r",stdin);
	freopen("julian.out","w",stdout);
	for(int i=1,t=1;i<=12;i++)
	    for(int j=1;j<=a1[i];j++,t++)
	    {
	    	t1[t].first=i;
	    	t1[t].second=j;
		}
	
	for(int i=1,t=1;i<=12;i++)
	    for(int j=1;j<=a2[i];j++,t++)
	    {
	    	t2[t].first=i;
	    	t2[t].second=j;
	    //	cout<<t<<endl;
		}
	int m;
	cin>>m;
	int k1=4713/4*1461+365+1;
	int k2=1580/4*1461+365+277;
	int a,b,c;
	while(m--)
	{
		ll x;
		cin>>x;
		x++;
		if(x<=k1)//¹«ÔªÇ°
		{
			a=x/1461*4;
			x-=a/4*1461;
			int y=x;
			if(y>366)
			{
				a++;
				y-=366;
				a+=y/365;
				if(y%365) y=y%365;
				else y=365;
			}
			x=y;
			a=4713-a;
			if(a%4==1)
			printf("%d %d %d BC\n",t2[x].second,t2[x].first,a);
			else
			printf("%d %d %d BC\n",t1[x].second,t1[x].first,a);
		}
		else
		{
			x-=k1;
			if(x<=k2)//1582.10.4
			{
				a=x/1461*4;
			    x-=a/4*1461;
			    if(x<=3*365)
			    {
			    	a+=x/365;
			    	if(x%365) x=x%365,a++;
			    	else x=365;
				}
				else
				{
					a+=4;
					x-=365*3;
				}
			    if(a%4==0)
			    printf("%d %d %d\n",t2[x].second,t2[x].first,a);
			    else
			    printf("%d %d %d\n",t1[x].second,t1[x].first,a);
			}
		}
	}
	
	return 0;
}
