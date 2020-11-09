#include <bits/stdc++.h>
using namespace std;
long long month[13]={0,31,28,31,30,31,30,31,31,30,31,30,31}; 
bool flag;
int main()
{
	freopen("julian.in","r",stdin);
	freopen("julian.out","w",stdout);
	long long n,x,y=0,year=0; //y月份 year年份 
	cin>>n;
	for(long long i=1;i<=n;i++)
	{
		cin>>x;
		if(1+x<=month[1]) cout<<1+x<<" 1 4713 BC"<<endl;
		else if(x+1<=365) 
		{
			if(x<=1724958) flag=1;
			for(long long j=1;j<=12;j++)
			{
				while(x>month[j])
				{
					x-=month[j];
					j++;
					y++;
				}		
			}
			if(flag) cout<<x<<' '<<1+y<<' '<<4713-year<<' '<<"BC"<<endl;
			else cout<<cout<<x<<' '<<1+y<<' '<<4713<<endl;
			y=0;year=0;
		}
		else 
		{
			if(x<=1724958) flag=1;
			for(long long j=1;j<=x/365*12;j++)
			{
				while(x>month[j])
				{
					x-=month[j];
					j++;
					if(j>12) 
					{
						year++;
						j=j%12;
					}
					if(abs(year)%4==0) month[2]=29;
					y++;
					if(y>12) y=y%12;
				} 
			}
			if(flag) cout<<x<<' '<<1+y<<' '<<4713-year<<' '<<"BC"<<endl;
			else cout<<cout<<x<<' '<<1+y<<' '<<4713<<endl;
			y=0;year=0;
		}
	}
	return 0;
}
