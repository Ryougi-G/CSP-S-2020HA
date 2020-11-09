#include<bits/stdc++.h>
using namespace std;
int q,n,day,month,year;
void work(int a)
{
	if(a<=365)
	{
		year=4713;
		day=1;
		month=1;
		if (a<31)  
		{
			day+=a;
		}
		else if(31<=a&&a<59)
		{
			month++;
			day=a-30;
		}
		else if(59<=a&&a<90)
		{
			month=month+2;
			day=a-58;
		}
		else if(90<=a&&a<120)
		{
			month=month+3;
			day=a-89;
		} 
		else if(120<=a&&a<151)
		{
			month=month+4;
			day=a-119;
		}
		else if(151<=a&&a<181)
		{
			month=month+5;
			day=a-150;
		}
		else if(181<=a&&a<212)
		{
			month=month+6;
			day=a-180;
		}
		else if(212<=a&&a<243)
		{
			month=month+7;
			day=a-211;
		}
		else if(243<=a&&a<273)
		{
			month=month+8;
			day=a-242;
		}
		else if(273<=a&&a<304)
		{
			month=month+9;
			day=a-272;
		}
		else if(304<=a&&a<334)
		{
			month=month+10;
			day=a-303;
		}
		else if(334<=a&&a<365)
		{
			month=month+11;
			day=a-333;
		}
		else if(a==365)
		{
			year=year-1;
		}
		cout<<day<<' '<<month<<' '<<year<<' '<<"BC";
	}
}
int main()
{
	freopen("julian.in","r",stdin);
	freopen("julian.out","w",stdout);
	scanf("%d",&q);
	for(int i=1;i<=q;i++)
	{
		scanf("%d",&n);
		work(n);
	} 
	return 0;
}
