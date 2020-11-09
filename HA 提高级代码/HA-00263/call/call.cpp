#include<bits/stdc++.h>
using namespace std;
#define rint register int
inline int read()
{
	int f=1;
	int x=0;
	char c=getchar();
	while(!isdigit(c))
	{
		if(c=='-')
		f=-1;
		c=getchar();
	}
	while(isdigit(c))
	{
		x=x*10+c-'0';
		c=getchar();
	}
	return x*f;
}
int n,m,t,num;
int a[100010],blo[100010];
vector<int> v[100010];
void make(int x)
{
	if(blo[x]==1)
	{
		a[v[x][0]]+=v[x][1];
		a[v[x][0]]=a[v[x][0]]%998244353;
		return ;
	}
	if(blo[x]==2)
	{
		for(rint i=1;i<=n;i++)
		a[i]=(a[i]*v[x][0])%998244353;
	}
	if(blo[x]==3)
	{
		for(rint i=0;i<v[x].size();i++)
		make(v[x][i]);
	}
}
int main()
{
	freopen("call.in","r",stdin);
	freopen("call.out","w",stdout);
	cin>>n;
	for(rint i=1;i<=n;i++)
	a[i]=read(),a[i]=a[i]%998244353;
	cin>>m;
	for(rint i=1;i<=m;i++)
	{
		int x=read();int c=read();
		blo[i]=x;
		if(x==1)
		{
		v[i].push_back(c);
		c=read();
		v[i].push_back(c);
	    }
		if(x==2)
		v[i].push_back(c);
		if(x==3)
		{
			while(c--)
			{
				int p=read();
				v[i].push_back(p);
			}
		}
	}
	cin>>t;
	while(t--)
	{
		int x=read();
		make(x);
	}
	for(int i=1;i<=n;i++)
	printf("%d ",a[i]);
	return 0;
}
