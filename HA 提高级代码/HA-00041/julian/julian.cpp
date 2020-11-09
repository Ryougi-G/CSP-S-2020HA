#include<bits/stdc++.h>
using namespace std;
int q;
bool BC=1;
int a[100010];
int year[100010],day[100010],month[100010];
int main()
{
//	freopen("julian.in","r",stdin);
//	freopen("julian.out","w",stdout);
	memset(year,4713,sizeof(year));
	memset(month,1,sizeof(month));
	memset(day,1,sizeof(day));
	scanf("%d",&q);
	for(int i=0;i<q;i++) cin>>a[i];
	for(int i=0;i<q;i++)
	{
		for(int j=a[i];j!=0;j=a[i])
		{
			
			if(year[i]>=1582)
			{
				if(year[i]==1582&&month[i]==10)
				{
					if(a[i]>=4) day[i]=4,a[i]-=4;
				}
				if(month[i]==1||month[i]==3||month[i]==5||month[i]==7||month[i]==8||month[i]==10||month[i]==12)
				{
					if(a[i]>=31) 
					{
						month[i]=month[i]+1;
						a[i]=a[i]-31;
					}
					else day[i]+=a[i];
				}
				if(month[i]==4||month[i]==6||month[i]==9||month[i]==11)
				{
					if(a[i]>=30)
					{
						month[i]=month[i]+1;
						a[i]=a[i]-30;
					}
					else day[i]+=a[i];
				}
				if(year[i]%4==0&&month[i]==2)
				{
					if(a[i]>=29)
					{
						month[i]=month[i]+1;
						a[i]=a[i]-29;
					}
					else day[i]+=a[i];
				}
				else 
				{
					if(a[i]>=28)
					{
						month[i]=month[i]+1;
						a[i]=a[i]-28;
					}
					else day[i]+=a[i];
				}
				if(month[i]>12)
				{
					year[i]-=1;
					month[i]=month[i]-12;
				}
			}
			if(year[i]<=1582)
			{
				if(year[i]==0)
				{
					BC=0;
				}
				if(month[i]==1||month[i]==3||month[i]==5||month[i]==7||month[i]==8||month[i]==10||month[i]==12)
				{
					if(a[i]>=31) 
					{
						month[i]=month[i]+1;
						a[i]=a[i]-31;
					}
					else day[i]+=a[i];
				}
				if(month[i]==4||month[i]==6||month[i]==9||month[i]==11)
				{
					if(a[i]>=30)
					{
						month[i]=month[i]+1;
						a[i]=a[i]-30;
					}
					else day[i]+=a[i];
				}
				if(year[i]%4==0&&year[i]%100!=0&&month[i]==2||year[i]%400==0&&month[i]==2)
				{
					if(a[i]>=29)
					{
						month[i]=month[i]+1;
						a[i]=a[i]-29;
					}
					else day[i]+=a[i];
				}
				else 
				{
					if(a[i]>=28)
					{
						month[i]=month[i]+1;
						a[i]=a[i]-29;
					}
					else day[i]+=a[i];
				}
				if(month[i]>12&&BC==1)
				{
					year[i]-=1;
					month[i]=month[i]-12;
				}
				if(month[i]>12&&BC==0)
				{
					year[i]+=1;
					month[i]=month[i]-12;
				}
			}
		}
	}
	for(int i=1;i<q;i++)
	{
		if(BC==1)
	cout<<day[i]<<month[i]<<year[i]<<"BC";
		if(BC==0)
	cout<<day[i]<<month[i]<<year[i];
	}
	return 0;
}
