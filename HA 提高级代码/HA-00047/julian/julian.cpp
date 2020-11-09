#include<bits/stdc++.h>
using namespace std;
int rq[]={31,28,31,30,31,30,31,31,30,31,30,31};
int q;int year,month,date;
bool check(int k)
{
	if(k%4==0) return 1;
	return 0;
}
bool check2(int k)
{
	if((k%4==0&&k%100!=0)||k%400==0) return 1;
	return 0;
}
void js(int x)
{
	bool flag=true;
	while(x>=355)
		{
			if(year<1582)
			{
				if(year==0) year++;
				if(x>=365)
				{
					int year1;
					if(year>0) year1=year;
						else year1=abs(year)-1;
					if(check(year1)&&x<366) ;
						else if(check(year1)) year++,x-=366;
					else year++,x-=365;
				}
			}
			if(year==1582&&x>=355)
			{
				year++,x-=355;
			}
			if(year>1582)
			{
					while(year>=1600&&x>=146097000000)
					{
						year+=400000000;x-=146097000000;
					}
					while(year>=1600&&x>=14609700000)
					{
						year+=40000000;x-=14609700000;
					}
				
					while(year>=1600&&x>=1460970000)
					{
						year+=4000000;x-=1460970000;
					}
				
				
					while(year>=1600&&x>=146097000)
					{
						year+=400000;x-=146097000;
					}
				
				
					while(year>=1600&&x>=14609700)
					{
						year+=40000;x-=14609700;
					}
				
					while(year>=1600&&x>=1460970)
					{
						year+=4000;x-=1460970;
					}
				
				
					while(year>=1600&&x>=146097)
					{
						year+=400;x-=146097;
					}
				
				if(x>=365)
				if(check2(year)&&x<366) ;
						else if(check2(year)) year++,x-=366;
					else year++,x-=365; 
			}
		}
		if(year==0) year++;
		int tt=0;
		int year1;
		if(year>0) year1=year;
			else year1=abs(year)-1;
		if(check(year1)&&year<=1582) rq[1]=29;
		if(year==1582) rq[9]-=10;
		if(year>1582&&check2(year)) rq[1]=29;
		while(x>rq[tt]) 
		{
			x-=rq[tt];
			tt++;
			month++;
		}
		date+=x;
		cout<<date<<' ';
		cout<<month<<' ';
		if(year<0) cout<<abs(year)<<' '<<"BC"<<endl;
		else cout<<year<<endl;
}
int main()
{
	//for(int i=1;i<=12;i++)
	//cout<<rq[i]<<' ';
	freopen("julian.in","r",stdin);freopen("julian.out","w",stdout);
	long long n;
	cin>>q;
	for(int i=1;i<=q;i++)
	{
		rq[1]=28;rq[9]=31;
		year=-4713,month=1,date=1;
		cin>>n;
		js(n);
	}
	return 0;
}

