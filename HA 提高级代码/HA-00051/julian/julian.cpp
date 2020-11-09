#include<bits/stdc++.h>
using namespace std;
#define int long long
int ping[15]={0,31,28,31,30,31,30,31,31,30,31,30,31};
int rui[15]={0,31,29,31,30,31,30,31,31,30,31,30,31};
int p[10]={0,366,365,365,365};
int pp[10]={0,365,365,365,366};
signed main()
{
	freopen("julian.in","r",stdin);
	freopen("julian.out","w",stdout);
	int T;
	for(int i=1;i<=12;i++)
	{
		ping[i]+=ping[i-1];
	}
	for(int i=1;i<=12;i++)
	{
		rui[i]+=rui[i-1];
	}
	cin>>T;
	while(T--)
	{
		int n;
		cin>>n;
		if(n<=1721424)
		{
			int y=n/1461;
			n%=1461;
			y*=4;
			for(int i=1;i<=4;i++)
			{
				if(n-p[i]>=0)
				{
					n-=p[i];
					y++;
				}
			}
			y=4713-y;
			int m;
			if((y+3)%4==0)
			{
				for(int i=1;i<=12;i++)
				{
					if(n-rui[i]>=0)
					{
						continue;
					}
					m=i;
					n-=rui[i-1];
					break;
				}
			}
			else
			{
				for(int i=1;i<=12;i++)
				{
					if(n-ping[i]>=0)
					{
						continue;
					}
					m=i;
					n-=ping[i-1];
					break;
				}
			}
			int d=n+1;
			cout<<d<<' '<<m<<' '<<y<<' '<<"BC"<<endl;
		}
		else if(n>1721424&&n<=2298796)
		{
			n-=1721424;
			int y=n/1461;
			n%=1461;
			y*=4;
			for(int i=1;i<=4;i++)
			{
				if(n-pp[i]>=0)
				{
					n-=pp[i];
					y++;
				}
			}
			y++;
			int m;
			if((y)%4==0)
			{
				for(int i=1;i<=12;i++)
				{
					if(n-rui[i]>=0)
					{
						continue;
					}
					m=i;
					n-=rui[i-1];
					break;
				}
			}
			else
			{
				for(int i=1;i<=12;i++)
				{
					if(n-ping[i]>=0)
					{
						continue;
					}
					m=i;
					n-=ping[i-1];
					break;
				}
			}
			int d=n+1;
			cout<<d<<' '<<m<<' '<<y<<' '<<endl;
		}
		else
		{
			n-=2298796;
//			n+=11;
			int y=0,m=0,d=0;
			if(n<=365+17+30+31)
			{
				if(n<=17+30+31)
				{
					y=1582;
					if(n<=17)
					{
						m=10;
						d=4+10+n;
					}
					if(n>17&&n<=17+30)
					{
						m=11;
						d=n-17;
					}
					if(n>17+30&&n<=17+30+31)
					{
						m=12;
						d=n-17-30;
					}
				}
				else
				{
					y=1583;
					n-=17+30+31;
					for(int i=1;i<=12;i++)
					{
						if(n-ping[i]>=0)
						{
							continue;
						}
						m=i;
						n-=ping[i-1];
						break;
					}
					d=n+1;
				}
			}
			else
			{
				n-=365+17+30+31;
				y+=n/1461;
				n%=1461;
				y*=4;
				y+=1;
				y+=1582;
			for(int i=1;i<=4;i++)
			{
				if(n-p[i]>=0)
				{
					n-=p[i];
					y++;
				}
			}
			int cnt1=0,cnt2=0;
			for(int i=1582;i<=y;i++)
			{
				if((i%4==0&&i%100!=0)||i%400==0)
				cnt1++;
			}
			for(int i=1582;i<=y;i++)
			{
				if(i%4==0)
				cnt2++;
			}
			n+=cnt2-cnt1;
			if((y)%4==0)
			{
				for(int i=1;i<=12;i++)
				{
					if(n-rui[i]>=0)
					{
						continue;
					}
					m=i;
					n-=rui[i-1];
					break;
				}
			}
			else
			{
				for(int i=1;i<=12;i++)
				{
					if(n-ping[i]>=0)
					{
						continue;
					}
					m=i;
					n-=ping[i-1];
					break;
				}
			}
			
			d=n+1;
			}
			
			cout<<d<<' '<<m<<' '<<y<<' '<<endl;
		}
	}
	return 0;
}
