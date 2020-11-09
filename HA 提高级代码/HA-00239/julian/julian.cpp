#include <bits/stdc++.h>
using namespace std;
int x[100500];
int main()
{	freopen("julian.in","r",stdin);
	freopen("julian.out","w",stdout);
	int q,year=-4713,month=1,day=1,count=0;
	bool t=false;
	cin>>q;
	for(int i=1;i<=q;i++)
	{
		cin>>x[i];
		count++;
		while(1>0)
		{	if(t==false)
			{
			day=day+x[count];
			t=true;
			}
		if(year>=1582)
		{
		if(day<28)
			{
			break;
			}
		else
		{	if(t==false)
			{
			day=day+x[count];
			t=true;
			}
			
			if(month!=2)
			{
				if(month==1 || month==3 || month ==5 || month ==7 || month ==8 || month==12)
				{	if(day>31)
					{
						day=day-31;
						month++;
					}
					if(month>12)
					{
						year++;
						month=1;
					}
				}
				if(month==4 || month ==6 || month ==9 || month==11)
				{	if(day>30)
					{
					day=day-30;
					month++;
					}
					if(month>12)
					{
						year++;
						month=1;
					}
				}
				if(month==2)
				{
					if(year%4==0)
					{	if(day>29)
						{
						day=day-29;
						month++;
						}
						
						if(month>12)
						{
						year++;
						month=1;
						}
					}
					else
					{	if(day>28)
						{
						day=day-28;
						month++;
						}	
						if(month>12)
						{
						year++;
						month=1;
						}
					}
				}
			}
		}	
		}
		else if(year<1582)
		{
		if(day<28)
			{
			break;
			}
		else
		{	if(t==false)
			{
			day=day+x[count];
			t=true;
			}
			
			if(month!=2)
			{
				if(month==1 || month==3 || month ==5 || month ==7 || month ==8 || month ==10 || month==12)
				{	if(day>31)
					{
						day=day-31;
						month++;
					}
					if(month>12)
					{
						year++;
						month=1;
					}
				}
				if(month==4 || month ==6 || month ==9 || month==11)
				{	if(day>30)
					{
					day=day-30;
					month++;
					}
					if(month>12)
					{
						year++;
						month=1;
					}
				}
				if(month==2)
				{
					if(year%4==0)
					{	if(day>29)
						{
						day=day-29;
						month++;
						}
						
						if(month>12)
						{
						year++;
						month=1;
						}
					}
					else
					{	if(day>28)
						{
						day=day-28;
						month++;
						}	
						if(month>12)
						{
						year++;
						month=1;
						}
					}
				}
			}
		}	
		}
			
		}
				
		if(x[count]==0)
		{
			
		}
		if(year<0)
			cout<<day<<" "<<month<<" "<<-year<<" "<<"BC"<<endl;
		else
			{
			 	cout<<day<<" "<<month<<" "<<year+1<<endl;	
			}	
	}	
	return 0;
}
