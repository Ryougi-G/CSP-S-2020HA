#include<cstdio>
#include<iostream>
using namespace std;
const int MAXN=100001;
const int month[14]={31,28,31,30,31,30,31,31,30,31,30,31,29,21};
int main()
{
	freopen("julian.in","r",stdin);
	freopen("julian.out","w",stdout);
	int q,r[MAXN],mon=1,year=-4713,day=1;
	bool flag,used=false; 
	scanf("%d",&q);
	for(int i=1;i<=q;i++)
	{
		scanf("%d",r+i);
	}
	for(int i=1;i<=q;i++)
	{
		mon=1,year=-4713,day=1;
		while(r[i]>=0)
		{
			if(year==0)	year=1;	
			if(used==false&&year>=1583&&r[i]>=277)
			{
				used=true;
				r[i]+=10;
			}	
			if((year<0&&year%4==-1)||(year>0&&year<1582&&year%4==0)||(year>1582&&(year%400==0||(year%4==0&&year%100!=0))))
			{
				r[i]-=366;
				year++;
				flag=true;
			}
			else 
			{
				r[i]-=365;
				year++;
				flag=false;
			}
		}
		if(flag)	r[i]+=366;
		else	r[i]+=365;
		year--;
		for(int j=0;j<=11;j++) 
		{
			if(flag)
			{
				if(r[i]>month[j])
				{
					if(j==1)
					{
						r[i]-=month[12];
						mon++;						
					} 
					else
					{
						r[i]-=month[j];
						mon++;						
					}
				}
				else
				{
					day+=r[i];break;
				}
			} 
			else 
			{
				if(r[i]>month[j])
				{
					r[i]-=month[j];
					mon++;				
				}
				else
				{
					day+=r[i];break;
				}						
			}
		}
		if(year<0)
		{
			year=-year;
			printf("%d %d %d BC\n",day,mon,year);				
		}
		else
		{
			printf("%d %d %d\n",day,mon,year);
		}
	}
	return 0;
}
