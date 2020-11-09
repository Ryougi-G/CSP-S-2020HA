#include<bits/stdc++.h>
using namespace std;
long long int day[13]={0,31,28,31,30,31,30,31,31,30,31,30,31},wmonth=0,wday=0;
int iread()
{
	int x=0,f=1; char c=getchar();
	while(c<'0'||c>'9'){ if(c=='-') f=-1; c=getchar();
	}
	while(c>='0'&&c<='9') {
		x=x*10+c-'0'; c=getchar();
	}
	return f*x;
}
int n;
long long int wyear=4713,wwyear=1583;
long long int r;
void jisuan(int x)
{
		if(x>=365)
			{
				if((wyear-1)%4==0){x-=366;} else{ x-=365;} wyear--; return jisuan(x);
			}
		if(x<365&&(wyear-1)%4!=0)
		{	day[2]=28;
			for(int i=1;i<=12;i++)
			{
				x=x-day[i]; 
				if(x<=0) {
					x+=day[i]; wmonth=i; break;
				}
			}
		}
		if(x<365&&(wyear-1)%4==0)
		{	
			day[2]=29;
			for(int i=1;i<=12;i++)
			{
				x=x-day[i];
				if(x<=0) {
					x+=day[i];wmonth=i; break;
				}
			}
		}
		wday=x;
}
void  wjisuan(int x)
{
		if(x>=365)
			{
				if((wwyear%4==0&&wwyear%100!=0)||(wwyear%400==0)) {x-=366;} else{ x-=365;} wwyear++; return jisuan(x);
			}
		if(x<365&&wwyear%4!=0)
		{
	
			for(int i=1;i<=12;i++)
			{
				day[2]=28;
				x=x-day[i]; 
				if(x<=0) {
					x+=day[i]; wmonth=i; wday=x; break;
				}
			}
		}
		if(x<366&&((wwyear%4==0&&wwyear%100!=0)||(wwyear%400==0)))
		{
			day[2]=29;
			for(int i=1;i<=12;i++)
			{
				x=x-day[i];
				if(x<=0) {
					x+=day[i];wmonth=i; wday=x; break;
				} 
			}
		}
		
}
int main()
{
	freopen("julian.in","r",stdin);
	freopen("julian.out","w",stdout);
	n=iread();
	for(int i=1;i<=n;i++)
	{
		r=iread();
		if(r<1721423)
		{
			jisuan(r+1);
			printf("%lld %lld %lld BC",wday,wmonth,wyear); 
		}
		if(r==1721423)
		{
			printf("1,1,1");
		}
		if(1721423<r&&r<=2298871)
		{
			jisuan(r-1721423+1);
			printf("%lld %lld %lld",wday,wmonth,4713-wyear+1);
		}
		if(r<=2299226&&r>2299148)
		{
			for(int i=10;i<=12;i++)
			{
				r=r-2299148-day[i];
				if(r<=0){
					r+=day[i]; printf("%lld %lld %lld",r,i,1582);
				}
			}
		}
		if(r>2299226)
		{
			wjisuan(r-2299226+1);
			printf("%lld %lld %lld",wday,wmonth,wwyear+1);
		}
	}
	return 0;
	fclose(stdin); fclose(stdout);
}
