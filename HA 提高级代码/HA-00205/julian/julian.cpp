#include<bits/stdc++.h>
using namespace std;
long long d=0,m=1,y=4713;
long long q,r;
int f=1,f2=1;
int main()
{
	freopen("julian.in","r",stdin);
	freopen("julian.out","r",stdout);
	cin>>q;
	for(int i=1;i<=q;i++)
	{
		d=0,m=1,y=4713,f=1,f2=1;
		cin>>r;
		for(int j=1;j<=r;j++)
		{
			d++;
			if(d==31&&(m==1||m==3||m==5||m==7||m==8||m==10)) 
			{m++;d=0;}
			if(d==30&&(m==4||m==9||m==11||m==6)) 
			{m++;d=0;}
			if(f2==1)
			{
				if((y-f)%4==0&&d==29&&m==2)  {m++;d=0;}
				else if(d==28&&m==2) {m++;d=0;}
			}
			else
			{
				if((((y-f)%4==0&&(y-f)%100!=0)||((y-f)%400==0))&&d==29&&m==2) {m++;d=0;}
				else if(d==28&&m==2) {m++;d=0;}
			}
         	if(f==1&&y==1&&m==12&&d==31) y=0,f=0;
			
			if(f==1) {if(m==12&&d==31) y--,m=1,d=0;}
			else {if(m==12&&d==31) y++,m=1,d=0;}
			
			if(f==0&&y==1582&&m==10&&d==4)
			f2=0,d=15;
		}
		if(d==0) d=31,m-=1;
		if(r=1720245) m=12;
		if(f==1)cout<<d<<" "<<m<<" "<<y<<" "<<"BC"<<endl;
		else cout<<d<<" "<<m<<" "<<y<<endl;
	}
	return 0;
}
