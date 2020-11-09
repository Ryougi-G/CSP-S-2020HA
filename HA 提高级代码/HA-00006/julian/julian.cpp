#include<bits/stdc++.h>

using namespace std;

const int N=100100;
int n;
long long ri[N];
struct ans
{
	long long year;
	int mm;
	int dd;
}as[N];
int book1[13]={0,31,29,31,30,31,30,31,31,30,31,30,31};
int book2[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
int book3[5]={0,366,365,365,365};

int cread()
{
	int x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9')
	{
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		x=x*10+c-'0';
		c=getchar();
	}
	return x*f;
}

void bcday(int pan,int a1,int b1)
{
	if(pan%4==0)
	{
		int a2=a1,m1=1;
		for(int i=1;i<=12;i++)
		{
			if(a2-book1[i]>=0)
			{
				m1++;
				a2-=book1[i];
			}
			else
			{
				as[b1].mm=m1;
				as[b1].dd=a2+1;
				break;
			}
		}
	}
	else
	{
		int a2=a1,m1=1;
		for(int i=1;i<=12;i++)
		{
			if(a2-book2[i]>=0)
			{
				m1++;
				a2-=book2[i];
			}
			else
			{
				as[b1].mm=m1;
				as[b1].dd=a2+1;
				break;
			}
		}
	}
	return;
}

void acday(int pan,int a1,int b1)
{
	if((pan%4==0&&pan%100!=0)||pan%400==0)
	{
		int a2=a1,m1=1;
		for(int i=1;i<=12;i++)
		{
			if(a2-book1[i]>=0)
			{
				m1++;
				a2-=book1[i];
			}
			else
			{
				as[b1].mm=m1;
				as[b1].dd=a2+1;
				break;
			}
		}
	}
	else
	{
		int a2=a1,m1=1;
		for(int i=1;i<=12;i++)
		{
			if(a2-book2[i]>=0)
			{
				m1++;
				a2-=book2[i];
			}
			else
			{
				as[b1].mm=m1;
				as[b1].dd=a2+1;
				break;
			}
		}
	}
	return;
}

int main()
{
	freopen("julian.in","r",stdin);
	freopen("julian.out","w",stdout);
	n=cread();
	for(int i=1;i<=n;++i)
	{
		ri[i]=cread();
		as[i].year=-4713;
		as[i].mm=1;
		as[i].dd=1;
	}
	for(int i=1;i<=n;++i)//ms年数,rn闰年数 
	{                    //t儒略日,z闰年周期数 
		long long t=ri[i];
		if(t<1721423)//公元前 
		{
			if(t>=1461)//大于4年 
			{
				long long z=t/1461;
				int yy=t-z*1461;
				int zz=0;
				for(int j=1;j<=4;j++)
				{
					if(yy-book3[j]>=0)
					{
						zz++;
						yy=yy-book3[j];
					}
					else break;
				}
				as[i].year=as[i].year+z*4+zz;
				bcday(as[i].year*-1-1,yy,i);
				printf("%d %d %lld BC",as[i].dd,as[i].mm,as[i].year*-1);
				puts("");
			}
			else
			{
				long long yy=t;
				int zz=0;
				for(int j=1;j<=4;j++)
				{
					if(yy-book3[j]>=0)
					{
						zz++;
						yy-=book3[j];
					}
					else break;
				}
				as[i].year=as[i].year+zz;
				bcday(as[i].year*-1-1,yy,i);
				printf("%d %d %lld BC",as[i].dd,as[i].mm,as[i].year*-1);
				puts("");
			}
		}
		else //公元后 
		{
			long long f=t-1721423;
			as[i].year=1;
			if(f<=578101)
			{
				if(f>=1461)//大于4年 
				{
					long long z=f/1461;
					int yy=f-z*1461;
					int zz=0;
					for(int j=1;j<=4;j++)
					{
						if(yy-book3[j]>=0)
						{
							zz++;
							yy=yy-book3[j];
						}
						else break;
					}
					as[i].year=as[i].year+z*4+zz;
					bcday(as[i].year,yy,i);
					printf("%d %d %lld",as[i].dd,as[i].mm,as[i].year);
					puts("");
				}
				else
				{
					long long yy=f;
					int zz=0;
					for(int j=1;j<=4;j++)
					{
						if(yy-book3[j]>=0)
						{
							zz++;
							yy-=book3[j];
						}
						else break;
					}
					as[i].year=as[i].year+zz;
					bcday(as[i].year,yy,i);
					printf("%d %d %lld",as[i].dd,as[i].mm,as[i].year);
					puts("");
				}
			}
			else//换历 
			{
				long long g=f-578101+10;
				if(g>=1461)//大于4年 
				{
					long long z=g/1461;
					int yy=g-z*1461;
					int zz=0;
					for(int j=1;j<=4;j++)
					{
						if(yy-book3[j]>=0)
						{
							zz++;
							yy=yy-book3[j];
						}
						else break;
					}
					as[i].year=as[i].year+z*4+zz+1582;
					acday(as[i].year,yy,i);
					printf("%d %d %lld",as[i].dd,as[i].mm,as[i].year);
					puts("");
				}
				else
				{
					long long yy=f;
					int zz=0;
					for(int j=1;j<=4;j++)
					{
						if(yy-book3[j]>=0)
						{
							zz++;
							yy-=book3[j];
						}
						else break;
					}
					as[i].year=as[i].year+zz+1582;
					acday(as[i].year,yy,i);
					printf("%d %d %lld",as[i].dd,as[i].mm,as[i].year);
					puts("");
				}
			}
		}
	}
	return 0;
}
