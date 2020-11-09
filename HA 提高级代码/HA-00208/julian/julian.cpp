#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
int monthday[]={0,31,28,31,30,31,30,31,31,30,31,30,31};
ll readint()
{
	bool neg=false;
	ll x=0;
	char c=getchar();
	while(c<'-')c=getchar();
	if(c=='-'){neg=true;c=getchar();}
	for(;c>='0'&&c<='9';c=getchar())
		x=x*10+c-'0';
	return neg?-x:x;
}
const int Y1582[]={344,365,366,365,365,365,366,365,365,365,366,365,365,365,366,365,365,365};
void solve(ll d)
{	
	monthday[2]=28;monthday[10]=31;
	int year=-4713,month=0;
	bool run=false;
	
	if(d<=2408458){
		year+=d/1461*4;
		d=d%1461;
		if(d<=366){
			run=true;
		}else{
			d--;
			year+=d/365;
			d%=365;
		}
		if(year>=0)year++;
		goto CalMD;
	}
	d-=2408458;
	if(d<6188){
		for(year=1582;d>Y1582[year-1582];year++)
			d-=Y1582[year-1582];
		if(Y1582[year-1582]==366)run=true;
		goto CalMD;
	}
	d-=6188;
	year=1600;
	for(;;)
	{
		int day=year%400==0||year%100!=0&&year%4==0?366:365;
		if(d<day)break;
		d-=day;
	}
CalMD:
	if(run)monthday[2]=29;
	if(year==1582)monthday[10]=21;
	d++;
	for(month=1;d>monthday[month];month++)
		d-=monthday[month];
	if(year==1582&&month==10&&d>4)d+=10;
	if(year<0)printf("%d %d %d BC\n",(int)d,month,-year);
	else printf("%d %d %d\n",(int)d,month,year);
}
int main()
{
	freopen("julian.in","r",stdin);
	freopen("julian.out","w",stdout);
	int Q=readint();
	while(Q--)
	{
		solve(readint());
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
