#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <map>
#define ll long long
using namespace std;
namespace IO
{
	char ss[1<<17|1],*A,*B;
	inline char gc()
	{
		if(A==B)
		{
			B=(A=ss)+fread(ss,1,1<<17,stdin);
			if(A==B) return EOF;
		}
		return *A++;
	}
	template<class T>inline void read(T &x)
	{
		x=0; char ch=gc();
		while(ch<'0' || ch>'9') ch=gc();
		while(ch>='0'&&ch<='9') x=(x<<1)+(x<<3)+(ch^48),ch=gc();
	}
}
inline void file()
{
	freopen("julian.in","r",stdin);
	freopen("julian.out","w",stdout);
}
int yf[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
const ll before=2299160;
inline void output(ll year,ll left,ll bef)
{
	ll month=1,day=1;
	for(register int i=1;i<=12;i++)
	{
		int dy=yf[i];
		if(i==2)
		{
			if(bef) 
			{
				if(year%4==0) dy++;
			}
			else 
			{
				if(year%400==0 || (year%4==0 && year%100!=0)) dy++;
			}
		}
		if(left<dy) { month=i,day=left+1; break; }
		else left-=dy;
	}
	if(year<1) printf("%lld %lld %lld BC\n",day,month,-year+1);
	else printf("%lld %lld %lld\n",day,month,year);
}
inline void solve(ll num)
{
	if(num<=2299239)
	{
		if(num>2299160) num+=10;
		int yy=num/1461 *4; num%=1461;
		if(num>=366) num-=366,yy++;
		if(num>=365) num-=365,yy++;
		if(num>=365) num-=365,yy++;
		if(num>=365) num-=365,yy++;
		output(yy-4712,num,1);
	}
	else 
	{
		num-=2299239;
		ll yy=1583; 
		yy+=1ll*(num/146097)*400; num%=146097;
		for(;;yy+=4)
		{
			ll rn=yy+1,tt=1460;
			if(rn%400==0 || (rn%4==0 && rn%100!=0)) tt++;
			if(num<tt) break;
			num-=tt;
		}
		for(;;yy++)
		{
			ll rn=yy,tt=365;
			if(rn%400==0 || (rn%4==0 && rn%100!=0)) tt++;
			if(num<tt) break;
			num-=tt;
		}
		output(yy,num,0);
	}
}
int main()
{
	file();
	int n; scanf("%d",&n);
	while(n--)
	{
		ll x; IO::read(x);
		solve(x);
	}
	return 0;
}
