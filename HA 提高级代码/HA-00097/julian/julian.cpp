#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define rint register int
ll r;
int q;
int month1[15]={0,31,28,31,30,31,30,31,31,30,31,30,31};
int main()
{
	freopen("julian.in","r",stdin);
	freopen("julian.out","w",stdout);
	scanf("%d",&q);
	for(rint i=1;i<=q;i++)
	{
		int year=-4713,month=1,day=1;
		scanf("%lld",&r);
		int ppp=0;
		if(r>=1721424) ppp=1;
		if(r<2299249)
		{
			year+=r/1461*4;
			r%=1461;
			if(r>=366)
			{
				year++;
				r-=366;
			}
			while(r>=365)
			{
				year++;
				r-=365;
			}
		}
		else
		{
			r-=2299249;
			year=1583;
			while(r>=146097)
			{
				year+=400;
				r-=146097;
			}
			while(1)
			{
				int pan=0;
				if(year%400==0||(year%4==0&&year%100!=0))
				pan=1;
				if(pan==1&&r<366) break;
				if(pan==0&&r<365) break;
				if(pan==1&&r>=366)
				{
					year++;
					r-=366;
				} 
				if(pan==0&&r>=365)
				{
					year++;
					r-=365;
				}
			}
		}
		if(year<=1582)
		{
			if(ppp==1) year++;
			if((abs(year)-1)%4!=0) 
			month1[2]=28;
			else
			month1[2]=29;
			for(int i=1;i<=12;i++)
			{
				if(r>=month1[i])
				{
					month++;
					r-=month1[i];
				}      
			}
			day+=r;
			if(year==1582)
			{
				if((month==10&&day>4)||(month>10))
				{
					day+=10;
				}
			}
			if(day>month1[month])
			{
				day-=month1[month];
				month++;
			}
			if(month>12)
			{
				year++;
				month-=12;
			}
			if(ppp==0)
			printf("%d %d %d BC\n",day,month,abs(year));
			else
			printf("%d %d %d\n",day,month,abs(year));
		}
		else
		{
			if(year%400==0||(year%4==0&&year%100!=0))
			month1[2]=29;
			else month1[2]=28;
			for(int i=1;i<=12;i++)
			{
				if(r>month1[i])
				{
					month++;
					r-=month1[i];
				}
				else break;
			}
			day+=r;
			day+=10;
			if(day>month1[month])
			{
				day-=month1[month];
				month++;
			}
			if(month>12)
			{
				month-=12;
				year++;
			}
			printf("%d %d %d\n",day,month,year); 
		}
	}
	return 0;
}
