#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
long long int xx=1,n,m,q,mod=998244353;
long long int a[100010];
long long int s[100010];
int b[100010];
struct fun{
	int lx;
	long long int w;
	long long int nu;
	vector<int> k;
};
fun f[100010];
void hs(int x)
{
	for(int i=f[x].nu;i>=1;i--)
	{
		if(f[f[x].k[i-1]].lx==1)
		{
			s[f[f[x].k[i-1]].nu]=(s[f[f[x].k[i-1]].nu]+xx*f[f[x].k[i-1]].w)%mod;
		}
		if(f[f[x].k[i-1]].lx==2)
		{
			xx=(xx*f[f[x].k[i-1]].nu)%mod;
		}
		if(f[f[x].k[i-1]].lx==3)
		{
			hs(f[x].k[i-1]);
		}
	}
}
int main()
{
	freopen("call.in","r",stdin);
	freopen("call.out","w",stdout);
	int z=0;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	cin>>m;
	for(int i=1;i<=m;i++)
	{
		scanf("%d%lld",&f[i].lx,&f[i].nu);
		if(f[i].lx==3)
		{
			for(int j=1;j<=f[i].nu;j++)
			{
				scanf("%d",&z);
				f[i].k.push_back(z);
			}
		}
		if(f[i].lx==1)
		{
			scanf("%lld",&f[i].w);
		}
	}
	cin>>q;
	for(int i=1;i<=q;i++)
	{
		cin>>b[i];
	}
	for(int i=q;i>=1;i--)
	{
		if(f[b[i]].lx==1)
		{
			s[f[b[i]].nu]=(s[f[b[i]].nu]+xx*f[b[i]].w)%mod;
		}
		if(f[b[i]].lx==2)
		{
			xx=(xx*f[b[i]].nu)%mod;
		}
		if(f[b[i]].lx==3)
		{
			hs(b[i]);
		}
	}
	for(int i=1;i<=n;i++)
	{
		a[i]=(a[i]*xx+s[i])%mod;
		cout<<a[i]<<" ";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
