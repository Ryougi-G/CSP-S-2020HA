#include<bits/stdc++.h>
using namespace std;
#define rint register int
int q;
int nian,yue,ri;
long long int read()
{
	long long int x=0,f=1;
	char c=getchar();
	while(!isdigit(c))
	{
		if(c=='-')
		f=-1;
		c=getchar();
	}
	while(isdigit(c))
	{
		x=x*10+c-'0';
		c=getchar();
	}
	return x*f;
}
int main()
{
	freopen("julian.in","r",stdin);
	freopen("julian.out","w",stdout);
	q=read();
	while(q--)
	{
		long long int x=read();
		if(x>=2299161)
		{
			x=x-2299161;
			nian=1582;
			yue=10;
			ri=15;
			int t=x%146097;
			int s=x/146097;
			nian=nian+s*400;
			x=x-s*146097;
	
			t=x%36524;
			s=x/36524;
			nian=nian+s*100;
			x=x-s*36524;
			
			t=x%1461;
			s=x/1461;
			nian=nian+s*4;
			x=x-s*1461;
			
			int tot=0;
	while(tot<x)
	{
		ri++;
		tot++;
		if(yue==1||yue==3||yue==5||yue==7||yue==8||yue==10||yue==12)
			if(ri==32) 
			{
			    ri=1;
			    yue++;
			}
		if(yue==4||yue==6||yue==9||yue==11)
		{
			if(ri==31) 
			{
			    ri=1;
			    yue++;
			}
		}
		if(yue==2)
		{
			if(nian%400==0||(nian%4==0&&nian%100!=0))
			{
				if(ri==30)
				{
				ri=1;yue++;
				}
			}
			else 
			    if(ri==29)
			    {
				ri=1;
				yue++;
			    }
		}
		if(yue==13)
		{
			yue=1;
			nian++;
		}
	}
			printf("%d %d %d\n",ri,yue,nian);
		}
		else
		{
			nian=-4712;yue=1;ri=1;
			int t=x%1461;
			int s=x/1461;
			nian=nian+s*4;
			x=x-s*1461;
			
			int tot=0;
	while(tot<x)
	{
		ri++;
		tot++;
		if(yue==1||yue==3||yue==5||yue==7||yue==8||yue==10||yue==12)
			if(ri==32) 
			{
			    ri=1;
			    yue++;
			}
		if(yue==4||yue==6||yue==9||yue==11)
		{
			if(ri==31) 
			{
			    ri=1;
			    yue++;
			}
		}
		if(yue==2)
		{
			if(nian%4==0)
				if(ri==30)
				{
				ri=1;yue++;
				}
			if(nian%4!=0)
			if(ri==29)
			{
				ri=1;
				yue++;
			}
		}
		if(yue==13)
		{
			yue=1;
			nian++;
		}
	}
	
			if(nian>=1)
			printf("%d %d %d\n",ri,yue,nian);
			else
			printf("%d %d %d BC\n",ri,yue,abs(nian-1));
		}
	}
	return 0;
}
