#include<bits/stdc++.h>
using namespace std;
int q,m,y,d,a[15]={0,31,28,31,30,31,30,31,31,30,31,30,31};
bool bc=1;
bool check(int x)//ÈòÄêÅÐ¶Ï 
{
	if(x>1582)
	{
		if(x%400==0) return 1;
		if(x%4==0&&x%100!=0) return 1;		
	}
	else
	{
		if(x<0) if(x%4==-1) return 1;
		if(x>0&&x<1582) if(x%4==0) return 1;
	}
	return 0;
}
void day(int d,int month,int year)
{
	bool f=0;
	if(check(year)==1&&year!=1582)
	{
		if(d>366) d-=366,year++,f=1;
	}
	else
	{
		if(year!=1582&&d>365) d-=365,year++,f=1;	
	}
if(f==0)
{
		for(int i=1;i<=12;i++)
	{
		if(year==1582&&i==10)
		{
			if(d>21) d-=21,month++;
			else
			{
				if(d>4&&d<=21) cout<<d+10<<" "<<month<<" "<<year<<endl;
				else cout<<d<<" "<<month<<" "<<year<<endl;
				
			}
		}//´¦Àí1582.10 
		if(check(year)==1&&i==2)
		{
			if(d>29) d-=29,month++;
		}
		else if(d>a[i]) d-=a[i],month++;
			 else
			 {
			 	 if(bc==1) cout<<d<<" "<<month<<" "<<abs(year)<<" "<<"BC"<<endl;
			 	 else cout<<d<<" "<<month<<" "<<abs(year)<<endl;
				 return ;	
			 }
	}
	month-=12;
	year++;
	
}
	if(year==0) year=1,bc=0;
	day(d,month,year);
}
int main()
{
	freopen("julian.in","r",stdin);
	freopen("julian.out","w",stdout);
	cin>>q;
	while(q--)
	{
		int n;
		cin>>n;
		if(n>=4000000) n-=1;
		bc=1;
		day(n+1,1,-4713);
	}
	return 0;
}

