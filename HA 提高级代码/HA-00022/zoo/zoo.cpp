#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define int long long
using namespace std;
const int N=1000001;
signed n,m,c,k,a[N],p[N],q[N];
int sum,w,ans;
inline signed read()
{
	register signed x=0,m=1;register char ch=getchar();
	while(ch<'0' || ch>'9'){if(ch=='-') m=-1;ch=getchar();}
	while(ch>='0' && ch<='9'){x=(x<<3)+(x<<1)+ch-'0';ch=getchar();}
	return x*m;
}
signed main()
{
	freopen("zoo.in","r",stdin);
	freopen("zoo.out","w",stdout);
	n=read(),m=read(),c=read(),k=read();
	sum=(1<<(k+1))-1;
	for(register int i=1;i<=n;i++)	a[i]=read();
	for(register int i=1;i<=m;i++)
	{
		p[i]=read(),q[i]=read();
		if(!(w&(1<<p[i])))
		w|=(1<<p[i]);
	}
	for(register int i=0;i<=sum;i++)
		if((i&w)==w)	++ans;
	printf("%lld\n",ans-n);
	return 0;
} 
/*
3 3 5 4
1 4 6
0 3
2 4
2 5
*/ 
