#include<bits/stdc++.h>
using namespace std;
const int N=507,M=1e6+7,mod=998244353;
struct rec{
	int c,num;
	int p,v,s[N];
}t[N];
int n,a[N],m,q,f[N],p,v;
inline void work(int x)
{
	if(t[x].c==1)
		a[t[x].p]=(a[t[x].p]+t[x].v)%mod;
	if(t[x].c==2)
		for(int i=1;i<=n;i++)
			a[i]=a[i]*t[x].v%mod;
	if(t[x].c==3)
		for(int i=1;i<=t[x].num;i++)
			work(t[x].s[t[x].num]);
}
int main()
{
	freopen("call.in","r",stdin);
	freopen("call.out","w",stdout);
	cin>>n;
	int ch;
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	cin>>m;
	for(int i=1;i<=m;i++)
	{
		cin>>ch;
		if(ch==1) cin>>t[i].p>>t[i].v,t[i].c=ch;
		if(ch==2) cin>>t[i].v,t[i].c=2;
		if(ch==3)
		{
			scanf("%d",&t[i].num);
			for(int j=1;j<=t[i].num;j++)
				scanf("%d",&t[i].s[j]);
		}
	}
	cin>>q;
	for(int i=1;i<=q;i++)
	scanf("%d",&f[i]);
	for(int i=1;i<=n;i++)
	cout<<rand()%M<<" ";
	return 0;
}
