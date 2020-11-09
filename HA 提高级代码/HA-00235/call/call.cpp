#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,m;
inline long long read()
{
	long long re=1,ans=0;
	char x;
	while((x=getchar())<'0'||x>'9')
		if(x=='-')
			re=-1;
	ans=x-'0';
	while((x=getchar())>='0'&&x<='9')
		ans=(ans<<3)+(ans<<1)+x-'0';
	return re*ans;
}
struct qq
{
	int a1,a2,b1;
	int c[1100];
	int flag;
}c[1100];
long long a[1100];
void work(int y)
{
	int x=c[y].flag;
	if(x==1)
	{
		a[c[y].a1]+=c[y].a2;
		a[c[y].a1]%=mod;
	}
	else if(x==2)
	{
		for(int i=1;i<=n;i++)
		{
			a[i]*=c[y].b1;
			a[i]%=mod;
		}
	}
	else
	{
		for(int i=1;i<=c[y].c[0];i++)
		{
			work(c[y].c[i]);
		}
	}
}
int main()
{
	freopen("call.in","r",stdin);
	freopen("call.out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++)
		a[i]=read();
	m=read();
	for(int i=1;i<=m;i++)
	{
		int t,x,y,z;
		t=read();
		c[i].flag =t;
		if(t==1)
		{
			c[i].a1 =read();
			c[i].a2 =read();
		}
		else if(t==2)
		{
			c[i].b1 =read();
		}
		else
		{
			c[i].c [0]=read();
			for(int j=1;j<=c[i].c[0];j++)
				c[i].c[j]=read();
		}
	}
	int q;
	q=read();
	for(int i=1;i<=q;i++)
	{
		int x;
		x=read();
		work(x);
	}
	for(int i=1;i<=n;i++)
		printf("%lld ",a[i]);
	return 0;
}
