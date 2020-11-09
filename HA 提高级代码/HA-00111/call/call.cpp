#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e5+10,mod=998244353;
int n,m,len,s[N];
ll a[N];
struct node
{
	int id,p,v,num;
	int g[1000];
}op[N];

int read()
{
	int x=0,f=1; char ch=getchar();
	while(!isdigit(ch)) {if(ch=='-') f=-1; ch=getchar();}
	while(isdigit(ch)) {x=x*10+ch-'0'; ch=getchar();}
	return x*f;
}
void work(int x)
{
	if(op[x].id==1)
		a[op[x].p]=(a[op[x].p]+op[x].v)%mod;
	else if(op[x].id==2)
	{
		for(int i=1;i<=n;i++)
			a[i]=a[i]*op[x].v%mod;
	}
	else 
	{
		for(int i=1;i<=op[x].num;i++)
			work(op[x].g[i]);
	}
}
int main()
{
	freopen("call.in","r",stdin);
	freopen("call.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	scanf("%d",&m);
	for(int i=1;i<=m;i++)
	{
		int xx;
		xx=read();
		if(xx==1)
		{
			op[i].p=read(); op[i].v=read();
			op[i].id=1;
		}
		else if(xx==2)
		{
			op[i].v=read();
			op[i].id=2;
		}
		else 
		{
			int t;
			scanf("%d",&t);
			for(int j=1;j<=t;j++)
				op[i].g[j]=read();
			op[i].num=t; op[i].id=3;
		}
	}
	scanf("%d",&len);
	for(int i=1;i<=len;i++)
	{
		int x;
		x=read();
		work(x);
	}
	for(int i=1;i<=n;i++)
		printf("%lld ",a[i]);
	return 0;
}
