#include<bits/stdc++.h>
using namespace std;
int main()
{	
	freopen("julian.in","r",stdin);
	freopen("julian.out","w",stdout);
	int Q;
	long long n;
	cin>>Q;
	while(Q--)
	{
		int day=1,yue=1,year=-4713,run=0,cshao=0;
		scanf("%lld",&n);
		while((run==0&&n>=365)||(run==1&&n>=366))
		{	
			if(year<0)
			{
				if((year+1)%4==0)
					n=n-366;
				else 
					n=n-365;
				year++;
			}
			else if(year==0)
				year++;
			else if(year>0&&year<=1582)
			{
				if(year%4==0)
					n=n-366;
				else 
					n=n-365;
				year++;
			}	
			else if(year>1582)
			{
				if((year%4==0&&year%100!=0)||year%400==0)
					n=n-366;
				else 
					n=n-365;
				year++;		
			}
		}
		if(year<0&&(year+1)%4==0)
			run=1;
		else if(year>0&&year<=1582&&year%4==0)
			run=1;
		else if(year>1582&&((year%4==0&&year%100!=0)||year%400==0))
			run=1;
		if(year>1582||(year==1582&&n>=277))
			n=n+10;
		for(int i=1;i<=12;i++)
		{
			if(i==1||i==3||i==5||i==7||i==8||i==10||i==12)
			{
				if(n>31)
					n-=31,yue++;
				else
					break;
			}
			else if(i==4||i==6||i==9||i==11)
			{
				if(n>30)
					n-=30,yue++;
				else
					break;
			}
			else if(i==2&&run==0)
			{	
				if(n>28)
					n-=28,yue++;
				else
					break;
			}
			else if(i==2&&run==1)
			{	
				if(n>29)
					n-=29,yue++;
				else
					break;
			}
		}
		day+=n;
		if(year<0)
			printf("%d %d %d BC\n",day,yue,abs(year));
		else
			printf("%d %d %d\n",day,yue,year);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
