#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=1000001;
int t,n,val[N],ans;
inline void work()
{
	ans=0;
	register int l=1,r=n;
	while(l<=r)
	{
		register int w=val[r]-val[l];
		register int getw=upper_bound(val+l,val+r-l+2,w)-val-1;
		if(val[getw]>w)	l++;
		else
		{
			register int k=lower_bound(val+l,val+r-l+2,w)-val-1;
			r--,l--,ans++;
			val[l]=w;
		}
	}
	printf("%d\n",ans);
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
	freopen("snakes.in","r",stdin);
	freopen("snakes.out","w",stdout);
	t=read()-1,n=read();
	for(register int i=1;i<=n;i++)
		val[i]=read();
	work();
	while(t--)
	{
		register int w=read();
		for(register int i=1;i<=w;i++)
		{
			register int x=read(),z=read();
			val[x]=z;
		}
		work();
	}
	return 0;
} 

