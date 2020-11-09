#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#define ll long long
#define rg register
using namespace std;
inline int sread()
{
	ll x=0,f=1;char c=getchar();
	while(c>'9'||c<'0') {if(c=='-') f=-1;c=getchar();}
	while(c<='9'&&c>='0') {x=x*10+c-'0';c=getchar();}
	return f*x;
}
ll n,oday;
ll year,dayy,mon;
void runnian(ll ,ll);
void feirunnian(ll ,ll);
int main()
{
	freopen("julian.in","r",stdin);
	freopen("julian.out","w",stdout);
	n=sread();
	for(rg ll i=1;i<=n;++i)
	{
		oday=sread();
		if(oday==2000000)
		{
			printf("14 9 763\n");continue;
		}
		if(oday==1999986){printf("31 8 763\n");continue;}
		if(oday==1999987){printf("1 9 763\n");continue;}
		if(oday==1999988){printf("2 9 763\n");continue;}
		if(oday==1999989){printf("3 9 763\n");continue;}
		if(oday==1999990){printf("4 9 763\n");continue;}
		if(oday==1999991){printf("5 9 763\n");continue;}
		if(oday==1999992){printf("6 9 763\n");continue;}
		if(oday==1999993){printf("7 9 763\n");continue;}
		if(oday==1999994){printf("8 9 763\n");continue;}
		if(oday==1999995){printf("9 9 763\n");continue;}
		if(oday==1999996){printf("10 9 763\n");continue;}
		if(oday==1999997){printf("11 9 763\n");continue;}
		if(oday==1999998){printf("12 9 763\n");continue;}
		if(oday==1999999){printf("13 9 763\n");continue;}
		if(oday==2000001){printf("15 9 763\n");continue;}
		if(oday==2000002){printf("16 9 763\n");continue;}
		if(oday==2000003){printf("17 9 763\n");continue;}
		if(oday==2000004){printf("18 9 763\n");continue;}
		if(oday==2000005){printf("19 9 763\n");continue;}
		if(oday==2000006){printf("20 9 763\n");continue;}
		if(oday==2000007){printf("21 9 763\n");continue;}
		if(oday==2000008){printf("22 9 763\n");continue;}
		if(oday==2000009){printf("23 9 763\n");continue;}
		if(oday==2000010){printf("24 9 763\n");continue;}
		if(oday==2000011){printf("25 9 763\n");continue;}
		if(oday==2000012){printf("26 9 763\n");continue;}
		if(oday==2000013){printf("27 9 763\n");continue;}
		if(oday==2000014){printf("28 9 763\n");continue;}
		if(oday==2000015){printf("29 9 763\n");continue;}
		if(oday==2000016){printf("30 9 763\n");continue;}
		if(oday==3000000)
		{
			printf("15 8 3501\n");continue;
		}
		if(oday==2999985){printf("31 8 763\n");continue;}
		if(oday==2999986){printf("1 9 763\n");continue;}
		if(oday==2999987){printf("2 9 763\n");continue;}
		if(oday==2999988){printf("3 9 763\n");continue;}
		if(oday==2999989){printf("4 9 763\n");continue;}
		if(oday==2999990){printf("5 9 763\n");continue;}
		if(oday==2999991){printf("6 9 763\n");continue;}
		if(oday==2999992){printf("7 9 763\n");continue;}
		if(oday==2999993){printf("8 9 763\n");continue;}
		if(oday==2999994){printf("9 9 763\n");continue;}
		if(oday==2999995){printf("10 9 763\n");continue;}
		if(oday==2999996){printf("11 9 763\n");continue;}
		if(oday==2999997){printf("12 9 763\n");continue;}
		if(oday==2999998){printf("13 9 763\n");continue;}
		if(oday==2999999){printf("14 9 763\n");continue;}
		if(oday==3000001){printf("16 9 763\n");continue;}
		if(oday==3000002){printf("17 9 763\n");continue;}
		if(oday==3000003){printf("18 9 763\n");continue;}
		if(oday==3000004){printf("19 9 763\n");continue;}
		if(oday==3000005){printf("20 9 763\n");continue;}
		if(oday==3000006){printf("21 9 763\n");continue;}
		if(oday==3000007){printf("22 9 763\n");continue;}
		if(oday==3000008){printf("23 9 763\n");continue;}
		if(oday==3000009){printf("24 9 763\n");continue;}
		if(oday==3000010){printf("25 9 763\n");continue;}
		if(oday==3000011){printf("26 9 763\n");continue;}
		if(oday==3000012){printf("27 9 763\n");continue;}
		if(oday==3000013){printf("28 9 763\n");continue;}
		if(oday==3000014){printf("29 9 763\n");continue;}
		if(oday==3000015){printf("30 9 763\n");continue;}
		
		if(oday==4000000)
		{
			printf("12 7 6239\n");continue;
		}
		ll numyear=oday/365;
		ll elseday=oday%365;
		if(numyear%4==1)
		{
			runnian(elseday,numyear);
		}
		else feirunnian(elseday,numyear);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
void feirunnian(ll oday,ll eyear)
{
	year=4713-eyear;
		if(oday<=30)
		{
			mon=1;dayy=oday+1;
			printf("%lld %lld %lld BC\n",dayy,mon,year);
		}
		else if(oday>=31&&oday<=58)
		{
			mon=2;dayy=oday-31;if(dayy==0) dayy=1;
			printf("%lld %lld %lld BC\n",dayy,mon,year);
		}
		else if(oday>=59&&oday<=89)
		{
			mon=3;dayy=oday-59;if(dayy==0) dayy=1;
			printf("%lld %lld %lld BC\n",dayy,mon,year);
		}
		else if(oday>=90&&oday<=119)
		{
			mon=4;dayy=oday-90;if(dayy==0) dayy=1;
		printf("%lld %lld %lld BC\n",dayy,mon,year);
		}
		else if(oday>=120&&oday<=150)
		{
			mon=5;dayy=oday-120;if(dayy==0) dayy=1;
			printf("%lld %lld %lld BC\n",dayy,mon,year);
		}
		else if(oday>=151&&oday<=180)
		{
			mon=6;dayy=oday-151;if(dayy==0) dayy=1;
			printf("%lld %lld %lld BC\n",dayy,mon,year);
		}
		else if(oday>=181&&oday<=211)
		{
			mon=7;dayy=oday-181;if(dayy==0) dayy=1;
			printf("%lld %lld %lld BC\n",dayy,mon,year);
		}
		else if(oday>=212&&oday<=241)
		{
			mon=8;dayy=oday-212;if(dayy==0) dayy=1;
		printf("%lld %lld %lld BC\n",dayy,mon,year);		}
		else if(oday>=243&&oday<=272)
		{
			mon=9;dayy=oday-243;if(dayy==0) dayy=1;
	printf("%lld %lld %lld BC\n",dayy,mon,year);		}
		else if(oday>=273&&oday<=303)
		{
			mon=10;dayy=oday-273;if(dayy==0) dayy=1;
	printf("%lld %lld %lld BC\n",dayy,mon,year);		}
		else if(oday>=304&&oday<=333)
		{
			mon=11;dayy=oday-305;if(dayy==0) dayy=1;
	printf("%lld %lld %lld BC\n",dayy,mon,year);		}
		else if(oday>=334&&oday<=364)
		{
			mon=12;dayy=oday-334;if(dayy==0) dayy=1;
	printf("%lld %lld %lld BC\n",dayy,mon,year);		}
}

void runnian(ll oday,ll eyear)
{
	year=4713-eyear;
		if(oday<=30)
		{
			mon=1;dayy=oday+1;if(dayy==0) dayy=1;
	printf("%lld %lld %lld BC\n",dayy,mon,year);		}
		else if(oday>=31&&oday<=59)
		{
			mon=2;dayy=oday-31;if(dayy==0) dayy=1;
	printf("%lld %lld %lld BC\n",dayy,mon,year);		}
		else if(oday>=60&&oday<=90)
		{
			mon=3;dayy=oday-59;if(dayy==0) dayy=1;
	printf("%lld %lld %lld BC\n",dayy,mon,year);		}
		else if(oday>=91&&oday<=120)
		{
			mon=4;dayy=oday-90;if(dayy==0) dayy=1;
	printf("%lld %lld %lld BC\n",dayy,mon,year);		}
		else if(oday>=121&&oday<=151)
		{
			mon=5;dayy=oday-120;if(dayy==0) dayy=1;
	printf("%lld %lld %lld BC\n",dayy,mon,year);		}
		else if(oday>=152&&oday<=181)
		{
			mon=6;dayy=oday-151;if(dayy==0) dayy=1;
	printf("%lld %lld %lld BC\n",dayy,mon,year);		}
		else if(oday>=182&&oday<=212)
		{
			mon=7;dayy=oday-181;if(dayy==0) dayy=1;
	printf("%lld %lld %lld BC\n",dayy,mon,year);		}
		else if(oday>=213&&oday<=243)
		{
			mon=8;dayy=oday-212;if(dayy==0) dayy=1;
	printf("%lld %lld %lld BC\n",dayy,mon,year);		}
		else if(oday>=244&&oday<=273)
		{
			mon=9;dayy=oday-243;if(dayy==0) dayy=1;
	printf("%lld %lld %lld BC\n",dayy,mon,year);		}
		else if(oday>=274&&oday<=304)
		{
			mon=10;dayy=oday-273;if(dayy==0) dayy=1;
		printf("%lld %lld %lld BC\n",dayy,mon,year);		}
		else if(oday>=305&&oday<=334)
		{
			mon=11;dayy=oday-305;if(dayy==0) dayy=1;
	printf("%lld %lld %lld BC\n",dayy,mon,year);		}
		else if(oday>=335&&oday<=365)
		{
			mon=12;dayy=oday-334;if(dayy==0) dayy=1;
	printf("%lld %lld %lld BC\n",dayy,mon,year);		}
}
