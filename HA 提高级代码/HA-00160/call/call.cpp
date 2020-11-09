#include<bits/stdc++.h>
using namespace std;
const int p=998244353;
struct node{
	int na,x,y;
	int c[1003];
}a[213013];
long long dp[1231212];
int n,m;
int k;
int b[1230312];
inline int read()
{
	int num=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9') {if(ch=='-') f=-1; ch=getchar();}
	while(ch>='0'&&ch<='9') {num=(num<<1)+(num<<3)+ch-'0'; ch=getchar();}
	return num*f;
}
int main()
{
	freopen("call.in","r",stdin);
	freopen("call.out","w",stdout);
	n=read();for(int i=1;i<=n;i++) dp[i]=read();
	m=read();
	for(int i=1;i<=m;i++)
	{
		a[i].na=read();
		if(a[i].na==1)
			a[i].x=read(),a[i].y=read();
		if(a[i].na==2)
			a[i].x=read();
		if(a[i].na==3)
		{
			a[i].c[0]=read();
			for(int j=1;j<=a[i].c[0];j++) a[i].c[j]=read();
		}
	}	
	k=read();
	for(int i=1;i<=k;i++)
	{
		int x=read();
		if(a[x].na==1) dp[a[x].x]=dp[a[x].x]+a[x].y%p;
		if(a[x].na==2) for(int j=1;j<=n;j++) dp[j]=dp[j]*a[x].x%p;
		else for(int j=1;j<=a[x].c[0];j++)
		{
			int c1=a[x].c[j];
			if(a[c1].na==1) dp[a[c1].x]=dp[a[c1].x]+a[c1].y%p;
			if(a[c1].na==2) for(int k=1;k<=n;k++)  dp[k]=dp[k]*a[c1].x%p;
		}
	 } 
	for(int i=1;i<=n;i++) printf("%lld ",dp[i]%p);
	return 0;
}
