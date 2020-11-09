#include<bits/stdc++.h>
using namespace std;
template<typename T>
inline void read(T &x)
{
	int f=1;x=0;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-') f=-1;ch=getchar();}
	while(isdigit(ch)){x=x*10+ch-'0';ch=getchar();}x*=f;
}
const int mod=998244353,N=2e4+10;
struct node
{
	int type,p,v,c,g[N];
}fun[N];
int n,a[N],m,Q;

void opt(int now)
{
	if(fun[now].type==1) a[fun[now].p]=(a[fun[now].p]+fun[now].v)%mod;
	else if(fun[now].type==2) for(int i=1;i<=n;i++) a[i]=(1ll*a[i]*fun[now].v)%mod;
	else for(int i=1;i<=fun[now].c;i++) opt(fun[now].g[i]);
}

int main()
{
	freopen("call.in","r",stdin);
	freopen("call.out","w",stdout);
	read(n);for(int i=1;i<=n;i++) read(a[i]);
	read(m);
	for(int i=1,T;i<=m;i++)
	{
		read(T);
		if(T==1) read(fun[i].p),read(fun[i].v),fun[i].type=1;
		if(T==2) read(fun[i].v),fun[i].type=2;
		if(T==3){read(fun[i].c);for(int j=1;j<=fun[i].c;j++) read(fun[i].g[j]);} 
	}
	read(Q);
	for(int i=1,f;i<=Q;i++) read(f),opt(f);
	for(int i=1;i<=n;i++) printf("%d ",a[i]);
	return 0;
}
