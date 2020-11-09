#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long unll;
typedef long long ll;
int nc;
void hx1(int x)
{
	int year=x/1461*4;
	int py=0;
	x%=1461;
	year+=(x/365);
	if(year>=4713) 
	{
		year-=4712;
		py=1;
	}
	else year=4713-year;
	int p=0;
	if(x<=366) p=1;
	else 
	{
		x-=366;
		x%=365;
	}
	if(x<=31)
	{
		printf("%d %d %d",x,1,year);
		if(py==0) printf(" BC");
		printf("\n");
		return;
	}//1
	x-=31;
	if(x<=28+p)
	{
		printf("%d %d %d",x,2,year);
		if(py==0) printf(" BC");
		printf("\n");
		return;
	}//2
	x-=(28+p);
	if(x<=31)
	{
		printf("%d %d %d",x,3,year);
		if(py==0) printf(" BC");
		printf("\n");
		return;
	}//3
	x-=31;
	if(x<=31)
	{
		printf("%d %d %d",x,4,year);
		if(py==0) printf(" BC");
		printf("\n");
		return;
	}//4
	x-=30;
	if(x<=31)
	{
		printf("%d %d %d",x,5,year);
		if(py==0) printf(" BC");
		printf("\n");
		return;
	}//5
	x-=31;
	if(x<=31)
	{
		printf("%d %d %d",x,6,year);
		if(py==0) printf(" BC");
		printf("\n");
		return;
	}//6
	x-=30;
	if(x<=31)
	{
		printf("%d %d %d",x,7,year);
		if(py==0) printf(" BC");
		printf("\n");
		return;
	}//7
	x-=31;
	if(x<=31)
	{
		printf("%d %d %d",x,8,year);
		if(py==0) printf(" BC");
		printf("\n");
		return;
	}//8
	x-=31;
	if(x<=31)
	{
		printf("%d %d %d",x,9,year);
		if(py==0) printf(" BC");
		printf("\n");
		return;
	}//9
	x-=30;
	if(x<=31)
	{
		printf("%d %d %d",x,10,year);
		if(py==0) printf(" BC");
		printf("\n");
		return;
	}//10
	x-=31;
	if(x<=31)
	{
		printf("%d %d %d",x,11,year);
		if(py==0) printf(" BC");
		printf("\n");
		return;
	}//11
	x-=30;
	if(x<=31)
	{
		printf("%d %d %d",x,12,year);
		if(py==0) printf(" BC");
		printf("\n");
		return;
	}//12
	return;
}
int main()
{
	freopen("julian.in","r",stdin);
	freopen("julian.out","w",stdout);
    cin>>nc;
    int s1;
    int zs;
    int t=0;
    for(int i=1;i<=nc;i++)
    {
    	t=0;
    	cin>>s1;
    	if(s1>2299160)
    	{
    		s1+=10;
    		zs=s1-2299160;
    		zs-=6209;
    		if(zs>=35625)
    		{
    			while(zs>35625)
    			{
    				zs-=35625;
    				if(zs<35624) break;
    				zs-=35624;
    				t+=1;
    				if(zs<35624) break;
    				zs-=35624;
    				t+=1;
    				if(zs<35624) break;
    				zs-=35624;
    				t+=1;
    			}
    		}
    	}
		hx1(s1+1+t);
    }
	return 0;
}
