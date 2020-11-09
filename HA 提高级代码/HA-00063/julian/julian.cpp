#include<bits/stdc++.h>
using namespace std;
int year=4713,num,month=1,day=1,julian,ryear=0;
int yyds()
{
		if(year%4==0)
		  ryear=1;
		else ryear=0;
		if(month==2)
		{
			if(ryear==1)
			{
				if(day>=29)
				{
					month++;
					day=day-29;
					if(month>12)
					{
						month=month-12;
						year--;
					}
					yyds();
				}
			}
			else {
				if(day>=28)
				{
					month++;
					day=day-28;
					if(month>12)
					{
						month=month-12;
						year--;
					}
					yyds();
				}
			}
		}
		else {
			if(month==4||month==6||month==9||month==11)
			{
				if(day>=30)
				{
					month++;
					day=day-30;
					if(month>12)
					{
						month=month-12;
						year--;
					}
					yyds();
				}
			}
			else {
				if(day>=31)
				{
					month++;
					day=day-31;
					if(month>12)
					{
						month=month-12;
						year--;
					}
					yyds();
				}
			}
		}

}
int main()
{
	freopen("julian.in","r",stdin);
	freopen("julian.out","w",stdout);
	cin>>num;
	for(int i=1;i<=num;i++)
	{
		cin>>julian;
		day=1+julian;
        yyds();
        if(year<=0)
        {
        	year=-year+1;
        	printf("%d %d %d\n",day,month,year);
        }
        else
        printf("%d %d %d BC\n",day,month,year);
        year=4713;
		month=1;
		day=1;
		ryear=0;
	}
	return 0;
}
