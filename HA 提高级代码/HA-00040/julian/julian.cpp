#include<bits/stdc++.h>
using namespace std;
int m[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
int f1[3]={365,366};
bool Pan(int x)
{
	if(x%4==0) return 1;
	else return 0;
}
bool Pan1(int x)
{
	if(x%100==0)
	{
		if(x%400==0) return 1;
		else return 0;
	}
	else if(x%4==0) return 1;
	else return 0;
}

void work1(int r)
{
	int year=0,month=1,day;
	day=r+1;
	int x=day/1461;
	day%=1461;
	if(day==0)
	{
		x--;
		day=1461;
	}
	year+=4*x;
	if(day-366>0)
	{
		day-=366;
		year++;
	}
	x=day/365;
	day%=365;
	if(day==0)
	{
		x--;
		day=365;
	}
	year+=x;
	bool f=0;
	for(int i=1;i<=12;i++)
	{
		int b=m[i];
		if(i==2&&Pan(year)) b++; 
		if(day>b)
		{
			day-=b;
			month++;
		}
		else break;
	}
	if(year<=4712)
	{
		year=4713-year;
		f=1;
	}
	else year=year-4712;
	if(f==0) cout<<day<<' '<<month<<' '<<year<<endl;
	if(f==1) cout<<day<<' '<<month<<' '<<year<<" BC"<<endl;
}
void work2(int r)
{
	int day=1,month=1,year=1583;
	r-=2299238;
	day=r;
	while(day-f1[Pan1(year)]>0)
	{
		day-=f1[Pan1(year)];
		year++;
	}
	for(int i=1;i<=12;i++)
	{
		int b=m[i];
		if(i==2&&Pan1(year)) b++; 
		if(day>b)
		{
			day-=b;
			month++;
		}
		else break;
	}
	cout<<day<<' '<<month<<' '<<year<<endl;
}
void work3(int r)
{
	int day=1,month=1,year=1600;
	r-=2305447;
	day=r;
	int x=day/146097;
	day%=146097;
	if(day==0)
	{
		x--;
		day=146097;
	}
	year+=400*x;
	if(day-36525>0)
	{
		day-=36525;
		year+=100;
	}
	x=day/36524;
	day%=36524;
	if(day==0)
	{
		x--;
		day=36524;
	}
	year+=100*x;
	
	x=day/1461;
	day%=1461;
	if(day==0)
	{
		x--;
		day=1461;
	}
	if(year%400!=0) day++;
	year+=4*x;
	if(day-366>0)
	{
		day-=366;
		year++;
	}
	x=day/365;
	day%=365;
	if(day==0)
	{
		x--;
		day=365;
	}
	year+=x;
	for(int i=1;i<=12;i++)
	{
		int b=m[i];
		if(i==2&&Pan1(year)) b++; 
		if(day>b)
		{
			day-=b;
			month++;
		}
		else break;
	}
	cout<<day<<' '<<month<<' '<<year<<endl;
	
}
int main()
{
	freopen("julian.in","r",stdin);
	freopen("julian.out","w",stdout);
	int q;
	cin>>q;
	for(int i=1;i<=q;i++)
	{
		int r;
		cin>>r;
		if(r<=2299160) work1(r);
		else if(r<=2299238)
		{
			r+=10;
			work1(r);
		}
		else if(r<=2305447)
		{
			work2(r);
		}
		else work3(r);
	}
	return 0;
}
