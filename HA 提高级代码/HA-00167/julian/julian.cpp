#include <cstdio>
#include <cctype>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
#include <cmath>
#include <map>
using namespace std;

#define rint register int
#define il inline
#define For(i,j,k) for(register int i=(j);i<=(k);++i)
#define Rep(i,j,k) for(register int i=(j);i>=(k);--i)
typedef long long LL;
il int read(int x=0,int f=1,char ch='0')
{
	while(!isdigit(ch=getchar())) if(ch=='-') f=-1;
	while(isdigit(ch)) x=x*10+ch-'0',ch=getchar();
	return f*x;
}
il int run(int x,int pre)
{
	if(pre)
	{
		return ( ((x-1)%4)==0 );
	}
	else
	{
		if(x%400==0) return 1;
		if(x%4==0 && x%100!=0) return 1;
		return 0;
	}
}
const int N=3e6+5;
int c[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
int s[N],q[N];
struct node{int x,y,z,pre;}mp[N];
il void print(int x,int y,int z,int pre)
{ printf("%d %d %d ",z,y,x); if(pre) puts("BC"); else puts("");}
int i=1;
void dfs(int n,int year,int mon ,int day,int pre)
{
//	printf("%d %d %d %d %d\n",n,year,mon,day,pre);
	if(year==0) year=1,pre=0;
	if(year==1582&&mon==10&&day==6) day=15;
	int mons=c[mon]+(mon==2&&run(year,pre));
	if(n<=mons-day) { mp[q[i]]=(node){year,mon,day+n,pre};  return; }	
	if(!pre)
	{
		if(mons==day) dfs(n-1,year+mon/12,mon%12+1,1,pre);
		else dfs(n-mons+day,year,mon,mons,pre);
	}
	else
	{
		if(mons==day) dfs(n-1,year-mon/12,mon%12+1,1,pre);
		else dfs(n-mons+day,year,mon,mons,pre);
	}
}

int main()
{
	freopen("julian.in","r",stdin);
	freopen("julian.out","w",stdout);
	int T=read();
	For(j,1,T) s[j]=q[j]=read();
	sort(q+1,q+T+1); 
	dfs(q[1],4713,1,1,1);
//	print(mp[10].x,mp[10].y,mp[10].z,mp[10].pre);
	for(i=2;i<=T;++i) dfs(q[i]-q[i-1],mp[q[i-1]].x,mp[q[i-1]].y,mp[q[i-1]].z,mp[q[i-1]].pre);
	For(j,1,T) print(mp[s[j]].x,mp[s[j]].y,mp[s[j]].z,mp[s[j]].pre);
	return 0;
}
//1721425
//#include <cstdio>
//#include <cctype>
//#include <iostream>
//#include <algorithm>
//#include <cstring>
//#include <queue>
//#include <cmath>
//#include <map>
//using namespace std;
//
//#define rint register int
//#define il inline
//#define For(i,j,k) for(register int i=(j);i<=(k);++i)
//#define Rep(i,j,k) for(register int i=(j);i>=(k);--i)
//typedef long long LL;
//il int read(int x=0,int f=1,char ch='0')
//{
//	while(!isdigit(ch=getchar())) if(ch=='-') f=-1;
//	while(isdigit(ch)) x=x*10+ch-'0',ch=getchar();
//	return f*x;
//}
//il int run(int x,int pre)
//{
//	if(pre)
//	{
//		return ( ((x-1)%4)==0 );
//	}
//	else
//	{
//		if(x%400==0) return 1;
//		if(x%4==0 && x%100!=0) return 1;
//		return 0;
//	}
//}
//const int N=3e6+5;
//int c[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
//int q[N];
//struct node{int x,y,z,pre;}mp[N];
//int i;
//il void print(int x,int y,int z,int pre)
//{ printf("%d %d %d ",z,y,x); if(pre) puts("BC"); else puts("");}
//void dfs(int n,int year,int mon ,int day,int pre)
//{
//	if(year==0) year=1,pre=0;
//	if(year==1582&&mon==10&&day==6) day=15;
//	int mons=c[mon]+(mon==2&&run(year,pre));
//	if(n<=mons-day) { print(year,mon,day+n,pre); return; }
//	if(!pre)
//	{
//		if(mons==day) dfs(n-1,year+mon/12,mon%12+1,1,pre);
//		else dfs(n-mons+day,year,mon,mons,pre);
//	}
//	else
//	{
//		if(mons==day) dfs(n-1,year-mon/12,mon%12+1,1,pre);
//		else dfs(n-mons+day,year,mon,mons,pre);
//	}
//}
//
//int main()
//{
//	freopen("julian.in","r",stdin);
//	freopen("julian.out","w",stdout);
//	int T=read();
//	while(T--) { int x=read(); dfs(x,4713,1,1,1); }
//	return 0;
//}
//1721425
