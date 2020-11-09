#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#define il inline
#define res register int
#define pb push_back
using namespace std;

const int N=1e5+10;

il int read()
{
	int x=0,f=0,c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=1;c=getchar();}
	while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
	return f?-x:x;
}

int n,m;
int a[N];
vector<int> v[N];
int T[N];


void add(int x,int y) 
{
	a[x]+=y; 
} 

void mul(int x)
{
	for(res i=1;i<=n;i++) a[i]=a[i]*x;
}

void dfs(int x)
{
	if(T[x]==1)
	{
		int xx=v[x][0],yy=v[x][1];
		add(xx,yy);
		return;
	}
	if(T[x]==2)
	{
		int xx=v[x][0];
		mul(xx);
		return;
	}
	int sz=v[x].size();
	for(res i=0;i<sz;i++)
	{
		int xx=v[x][i];
		dfs(xx);
	}
}

int main()
{

	freopen("call.in","r",stdin);
	freopen("call.out","w",stdout);

	n=read(); for(res i=1;i<=n;i++) a[i]=read();
	m=read();
	for(res i=1;i<=m;i++)
	{
		T[i]=read();
		if(T[i]==1)
		{
			int x=read(); int y=read(); v[i].pb(x); v[i].pb(y);	
		}
		if(T[i]==2) 
		{
			int x=read(); v[i].pb(x);	
		}
		if(T[i]==3)
		{
			int tot=read();
			for(res j=1;j<=tot;j++) 
			{
				int x=read(); v[i].pb(x);
			}
		}
	}
	
	int q=read();
	
	while(q--)
	{
		int x=read(); dfs(x);
	}

	for(res i=1;i<=n;i++) printf("%d ",a[i]);
	return 0;
	
}
