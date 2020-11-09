#include<bits/stdc++.h>
using namespace std;
int n;
int run=0;
int ds(int x)
{
	if(x==1)return 31;
	if(x==2)return run==1?29:28;
	if(x==3)return 31;
	if(x==4)return 30;
	if(x==5)return 31;
	if(x==6)return 30;
	if(x==7)return 31;
	if(x==8)return 31;
	if(x==9)return 30;
	if(x==10)return 31;
	if(x==11)return 30;
	if(x==12)return 31;
}
bool rn(int x)
{
//	if(x%4!=0)
//	return 0;
//	if(x%400==0)
//	return 1;
//	if(x%100==0)
//	return 0;
//	//if(x%4==0)
//	return 1;
//	
	if(x%4==0)
	{
		if(x%400==0)
		return 1;
		if(x%100!=0)
		return 1;
	}
	return 0;
}
int main()
{
	freopen("julian.in","r",stdin);
	freopen("julian.out","w",stdout);
	long long day,m,y;
	unsigned long long d;
	cin>>n;
	while(n--)
	{
		day=1,m=1,y=4713;
		run=0;
		cin>>d;
		++d;
		if(d==1143875)//de
		{
			cout<<"4 10 1582 BC"<<endl;
			continue;
		}
		if(d<1143875)//rl//de
		{
			while(d>=1461)//year
			{
				d-=1461;
				y-=4;
			}
			while(d>=366)
			{
				d-=365;
				if(y%4==0)// !!!
				d--;
				y--;
			}
			if(d>365&&(y-1)%4)
			d-=365;
			if((y-1)%4==0)run=1;
			while(d>=31)
			{
				d-=ds(m);
				++m;
				//cout<<m<<' '<<d<<endl;
			}
			
			//d++;
			
			if(d>ds(m))
			{
				d-=ds(m);
				++m;
			}
			
			printf("%lld %lld %lld BC\n",d,m,y);
			continue;
		}
		///公元前///
		else if(d<1721423)
		{
			d-=1143875;
			m=10,y=1582;
			d+=14;
//			while(d>1461)//year
//			{
//				d-=1461;
//				y-=4;
//			}
			while(d>=366)
			{
				d-=365;
				if(rn(y-1))// !!!
				d--;
				y--;
			}
			if(d>=365&&rn(y)==0)
			{
				d-=365;
				y++;
			}
			if(rn(y))run=1;
			//cout<<"*"<<run<<endl;
			while(d>=31)
			{
				d-=ds(m);
				++m;
				//m+=12,m%=13;
				//cout<<m<<' '<<d<<endl;
			}
			//day+=d;
			if(day>ds(m))
			{
				day-=ds(m);
				++m;
			}
			printf("%lld %lld %lld BC\n",d,m,y);
			continue;
		}
		else if(d==1721423)
		{
			cout<<"31 12 1 BC"<<endl;
		}
		
		/*********公元**********/
		else if(d>1721423)
		{
			d-=1721423;
			m=1,y=1;
//			while(d>0)//year
//			{
//				d-=1461;
//				y+=4;
//			}
			
			while(d>366)
			{
				if(rn(y))
				d--;
				
				d-=365;
				
				++y;
				
				//printf("%lld %lld %lld \n",d,m,y);
				
			}
			if(d>365&&!rn(y))
			{
				d-=365;
				y++;
			}
			//cout<<y<<endl;
			
//			if(d>366&&rn(y))
//			{
//				d-=366;
//				y++;
//			}
			run=rn(y);
			while(d>31)
			{
				//cout<<m<<' '<<d<<endl;
				
				d-=ds(m);
				++m;
				//m+=12,m%=13;
				
			}
			//day+=d;
			if(d>ds(m))
			{
				d-=ds(m);
				++m;
			}
			printf("%lld %lld %lld \n",d,m,y);
		}
	}
	return 0;
}
