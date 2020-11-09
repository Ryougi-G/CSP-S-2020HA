#include<bits/stdc++.h>
using namespace std;
typedef long long int ull;
int q;
ull bcd=1721422;
ull mid=578101;
int month[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
int runmon[13]={0,31,29,31,30,31,30,31,31,30,31,30,31};
int yrun[312312];
inline int read()
{
	int sum=0;
	char ch=getchar();
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9') {
		sum=sum*10+ch-48;
		ch=getchar();
	}
	return sum;
}
inline long long int lread()
{
	ull sum=0;
	char ch=getchar();
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9') {
		sum=sum*10+ch-48;
		ch=getchar();
	}
	return sum;
}
int main()
{
	freopen("julian.in","r",stdin);
	freopen("julian.out","w",stdout);
	q=read();
	for(int i=1582;i<=312312;i++)
	{	if(i%4==0&&i%100!=0) yrun[i]=1;
		if(i%400==0) yrun[i]=1;
	}
	for(int i=1;i<=q;i++)
	{
		ull date;
		date=lread();
		if(date<=bcd)
		{
			int year=4713;
			int yue=1;
			int day=1;
			if(date<365)
			{
				while(date-month[yue]>=0)
				{
					date=date-month[yue];
					yue++;
				}
				if(yue==1)
				day=date+1;
				else
				day=date;
				printf("%d %d %d ",day,yue,year);
				cout<<"BC"<<endl;
			}
			else
			{
				while(date-365>=0)
				{
					if(year%4==0)
					{
						if(date==366)
						{
							date=date-366;
							day=1;yue=1;
							year--;
							printf("%d %d %d ",day,yue,year);
							cout<<"BC"<<endl;
						}
						else
						{
							date-=366;
							year--;
						}
					}
					else
					{
						date=date-365;
						year--;
					}	
				}
				if(year%4==0&&year>=4)
				{
					while(date-runmon[yue]>=0)
					{
						date-=runmon[yue];
						yue++;
					}
					day=date+1;
				}
				if(year%4!=0)
				{
					while(date-month[yue]>=0)
					{
						date-=month[yue];
						yue++;
					}
					day=date+1;
				}
				printf("%d %d %d ",day,yue,year);
							cout<<"BC"<<endl;
			}
			
			
		}
		if(date>bcd)
		{
			date-=bcd;
			if(date<mid)
			{
				int year=1;
				int yue=1;
				int day=0;
				if(date<=365)
				{
					while(date-month[yue]>0)
					{
						date=date-month[yue];
						yue++;
					}
					day=date;
					printf("%d %d %d\n",day,yue,year);
				}
				if(date>365)
				{
						while(date-365>=0)
					{
						if(year%4==0)
						{
							if(date==366)
							{
								date=date-366;
								day=1;yue=1;
								year++;
								printf("%d %d %d\n",day,yue,year);
							}
							else
							{
								date-=366;
								year++;
							}
						}
						else
						{
								date=date-365;
								year++;
						}	
					}
					if(year%4==0)
					{
						while(date-runmon[yue]>=0)
						{
							date-=runmon[yue];
							yue++;
						}
						day=date;
					}
					if(year%4!=0)
					{
						while(date-month[yue]>=0)
						{
							date-=month[yue];
							yue++;
						}
						day=date;
					}
					printf("%d %d %d\n",day-1,yue,year);
				}
			}
			
		}
	}
	return 0;
}
