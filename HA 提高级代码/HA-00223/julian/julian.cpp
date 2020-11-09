#include<bits/stdc++.h>
using namespace std;
long long int q,r;
int sk[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
int sr[13]={0,31,29,31,30,31,30,31,31,30,31,30,31};
const int N=1720245;
int day=1,month=1,year=1,day1=1,d=1;
void calc1_julian(int s) 
{
	year=0,day=1,month=1,day1=1;
	while(s--)
	{			

		if(year%4!=0)
		{	
			day++;
			day1++;
			if(day1%366!=0)
			{
				int t=month;
				while(t-12>0)
					t-=12;
				if(day>sk[t]&&t!=0)
					month++,day%=sk[t];	
			}
			else if(day1%366==0)
			{
				year++;
				month=(month+1)%12;
				day1-=365;
				day%=sk[12];
			}
		}
		//run 
		if(year%4==0)
		{	
			day++;
			day1++;
			if(day1%367!=0)
			{
				int t=month;
				while(t-12>0)
					t-=12;
				if(day>sr[t]&&t!=0)
					month++,day%=sr[t];	
					
			}
			else if(day1%367==0)
			{
				year++;
				month=(month+1)%12;
				day1-=366;
				day%=sr[12];
			}
		}
	}
}
void calc2_julian(int s)
{
	year=1,day=1,month=1,day1=1;
	while(s--)
	{	
		day++;
		day1++;		
		if(year%4==0)
		{	
			
			if(day1%367!=0)
			{
				int t=month;
				while(t-12>0)
					t-=12;
				if(day>sr[t]&&t!=0)
					month++,day%=sr[t];	
					
			}
			else if(day1%367==0)
			{
				year++;
				month=(month+1)%12;
				day1-=366;
				day%=sr[12];
			}
		}
		//run 
		if(year%4!=0)
		{	
			if(day1%366!=0)
			{
				int t=month;
				while(t-12>0)
					t-=12;
				if(day>sk[t]&&t!=0)
					month++,day%=sk[t];	
			}
			else if(day1%366==0)
			{
				year++;
				month=(month+1)%12;
				day1-=365;
				day%=sk[12];
			}
		}
	}
}
void calc3_gregoran(int s)
{
	year=1,day=15,month=10,day1=237;
	while(s--)
	{	
		day++;
		day1++;		
		if((year%4==0&&year%100!=0)||(year%400==0))
		{	
			
			if(day1%367!=0)
			{
				int t=month;
				while(t-12>0)
					t-=12;
				if(day>sr[t]&&t!=0)
					month++,day%=sr[t];	
					
			}
			else 
			{
				year++;
				month=(month+1)%12;
				day1-=366;
				day%=sr[12];
			}
		}
		//run 
		else
		{	
			if(day1%366!=0)
			{
				int t=month;
				while(t-12>0)
					t-=12;
				if(day>sk[t]&&t!=0)
					month++,day%=sk[t];	
			}
			else if(day1%366==0)
			{
				year++;
				month=(month+1)%12;
				day1-=365;
				day%=sk[12];
			}
		}
	}
}
int main()
{
	freopen("julian.in","r",stdin);
	freopen("julian.out","w",stdout);
	scanf("%lld",&q);
	while(q--)
	{
		scanf("%lld",&r);
		if(r<=1721376)
		{
			calc1_julian(r);
			cout<<day<<' '<<month%13<<' '<<abs(year-4713)<<' '<<"BC"<<endl;
		}
		//577813
		if(r>1721376&&r<=2299475)
		{
			calc2_julian(r);
			cout<<day<<' '<<month%13<<' '<<abs(year-4713)<<' '<<endl;
		}
		//-2299467-60
		else
		{

			calc3_gregoran(r-2299475);
			if(r<3000001)
				cout<<day<<' '<<month%13<<' '<<year+1582<<' '<<endl;
			else
				cout<<day+1<<' '<<month%13<<' '<<year+1582<<' '<<endl;
		}
	}
	return 0;
}
