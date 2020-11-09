#include<cstdio>
#include<iostream>
#define rt register int
using namespace std;
long long int q,x,p,m=0;
int month1[13]={0,31,28,31,30,31,30,31,31,30,31,30,31},
	month2[13]={0,31,29,31,30,31,30,31,31,30,31,30,31};
int year(long long int y)
{
	int k1=365,k2=366;
	if(y)
	{
		if(y>=1582)
		{
			if(y%400==0 || (y%4==0 && y%100!=0)) return k2;
			return k1;
		}
		else
		{
			if(y%4==0) return k2;
			return k1;
		}
	}
	else
	{
		y=-y;
		y-=1;
		if(y%4==0) return k2;
		else return k1;
	}
}
int main()
{
	freopen("julian.in","r",stdin);
	freopen("julian.out","w",stdout);
	scanf("%lld",&q);
	for(rt i=1;i<=q;i++)
	{
		scanf("%lld",&x);
		if(x>1721423)
		{
			p=1;
			x-=1721390;printf("%lld\n",x);
			int num_y=146100;
			int num_yy=1461;
			while(x>=num_y) {x-=num_y;p+=400;}
			while(x>=num_yy) {x-=num_yy;p+=4;}
			int yyy=year(p);
			while(x>yyy) {x-=yyy;yyy=year(++p);}
			if(p%4==0) while(x>month2[m]) {x-=month2[m];m++;}
			else while(x>month1[m]) {x-=month1[m];m++;}
			printf("%lld %lld %lld\n",x,m,p);
		}
		else
		{
			p=-4713;
			m=0;
			int num_y=146100;
			int num_yy=1461;
			while(x>=num_y) {x-=num_y;p+=400;}
			while(x>=num_yy) {x-=num_yy;p+=4;}
			int yyy=year(p);
			while(x>yyy) {x-=yyy;yyy=year(++p);}
			if((-p-1)%4==0) while(x>month2[m]) {x-=month2[m];m++;}
			else while(x>month1[m]) {x-=month1[m];m++;}
			printf("%lld %lld %lld BC\n",x+1,m,-p);
			continue;
		}
		
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
