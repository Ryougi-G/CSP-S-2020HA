#include<bits/stdc++.h>
using namespace std;
int szyear;
int szday;
int szmonth;
int T;
int mday[13];
int main()
{
	freopen("julian.in","r",stdin);
	freopen("julian.out","w",stdout);
	scanf("%d",&T);
	mday[1]=mday[3]=mday[5]=mday[7]=mday[8]=mday[10]=mday[12]=31;
	mday[4]=mday[6]=mday[9]=mday[11]=30;
	mday[2]=28;
	for(int i=1;i<=T;++i)
	{
		szyear=-4713;
		szmonth=1;
		szday=1;
		int d;
		scanf("%d",&d);
		while(d--)
		{
			++szday;
			if(szyear<1582)
			{
				int f=0;
				if(szyear<0&&szyear%4==-1) f=1;
				if(szyear>0&&szyear%4==0) f=1;
				if(szday>mday[szmonth])
				{
					if(f!=1||szmonth!=2||szday!=29)
					{
						++szmonth;szday=1;
						if(szmonth>12)
						{
							szmonth=1;
							if(szyear==-1) szyear=1;
							else ++szyear;
						}
					}
				}
			}
			else if(szyear==1582)
			{
				if(szmonth==10&&szday==5) szday+=10;
				if(szday>mday[szmonth])
				{
					++szmonth;szday=1;
					if(szmonth>12)
					{
						++szyear;szmonth=1;
					}
				}
			}
			else if(szyear>1582)
			{
				int f=0;
				if((szyear%4==0&&szyear%100!=0)||(szyear%400==0)) f=1;
				if(szday>mday[szmonth])
				{
					if(f!=1||szmonth!=2||szday!=29)
					{
						++szmonth;szday=1;
						if(szmonth>12)
						{
							szmonth=1;
							++szyear;
						}
					}
				}
			}
			
		}
		int fl=0;
		if(szyear<0)
		{
			szyear*=(-1);fl=1;
		}
		if(fl==1) printf("%d %d %d BC\n",szday,szmonth,szyear);
		else printf("%d %d %d\n",szday,szmonth,szyear);
		
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
