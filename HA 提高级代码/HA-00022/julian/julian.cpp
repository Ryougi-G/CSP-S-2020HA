//#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
int q;
int a[14]={0,31,28,31,30,31,30,31,31,30,31,30,31,31};
inline int wabs(int w)
{
	if(w<0)	return 0-w;
	return w;
}
inline bool gaocheck(int w)//判断是否为闰年 （高 
{
	if(((w%400==0) || (w%4==0 && w%100!=0)))
		return true;
	return false;
}
inline bool rucheck(int w)//判断是否为闰年 （儒 
{
	if(w<0)	w=wabs(w)-1;
	if(w%4==0)
		return true;
	return false;
}
inline void work_year(int &k,int &year)
{
	if(k>=5844)
		++year;
	year+=4*floor(k/1461);
	k%=1461;
	while(k>366 && year<=1582)
	{
		if(k>365 && !rucheck(year))
		{
			year++;
			k-=365;
		}
		if(k>366 && rucheck(year))
		{
			if(year==-1)	year=1;
			else	year++;
			k-=366;
		}	
	}
	while(k>366)
	{
		if(k>365 && !gaocheck(year))
		{
			year++;
			k-=365;
		}
		if(k>366 && gaocheck(year))
		{
			year++;
			k-=366;
		}	
	}
	if(year>1582)	k+=11;
}
inline void work_mth(int &k,int &mth,int &year)
{
	while(k>a[mth])
	{
		if(mth==2 && rucheck(year) && k==29)
			break;
		if(mth==2 && rucheck(year))
			k-=29;
		else
			k-=a[mth];
		mth++;
		if(mth==13)
		{
			if(year==-1)	year=1;
			else year++;
			mth=1;
		}
		if(year==1582 && mth==10 && k>=5)
		{
			k+=11;
			break;
		}
	}
	while(k>a[mth])
	{
		if(mth==2 && gaocheck(year) && k==29)
			break;
		if(mth==2 && gaocheck(year))
			k-=29;
		else
			k-=a[mth];
		mth++;
		if(mth==13)
		{
			year++;
			mth=1;
		}
	}
}
inline int read()
{
	register int x=0,m=1;register char ch=getchar();
	while(ch<'0' || ch>'9'){if(ch=='-') m=-1;ch=getchar();}
	while(ch>='0' && ch<='9'){x=(x<<3)+(x<<1)+ch-'0';ch=getchar();}
	return x*m;
}
int main()
{
	freopen("julian.in","r",stdin);
	freopen("julian.out","w",stdout);
	q=read();
	while(q--)
	{
		register int k=read()+1;
		register int mth=1,year=-4713;
		work_year(k,year);
		work_mth(k,mth,year);
		if(year<0)
		{
			year=wabs(year);
			printf("%d %d %d BC",k,mth,year);
		}
		else
			printf("%d %d %d",k,mth,year);
	}
	return 0;
} 
/*
3
10
100
1000
3
2000000
3000000
4000000
*/
