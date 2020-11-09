#include<bits/stdc++.h>
using namespace std;
#define int long long
int p[10000021];
int *pos=p;
int cnt;
struct cxk
{
	int t,a,b;
	int *kai;
}q[100005];
int n;
int a[1000001];
int m;
int mod=998244353;
void chu(int aa)
{
	if(q[aa].t==1)
	{
		a[q[aa].a]+=q[aa].b;
		a[q[aa].a]%=mod;
	}
	if(q[aa].t==2)
	{
		for(int i=1;i<=n;i++)
		{
			a[i]*=q[aa].a;
			a[i]%=mod;
		}
	}
	if(q[aa].t==3)
	{
		for(int i=0;i<q[aa].a;i++)
		{
			chu(q[aa].kai[i]);
		}
	}
}
signed main( )
{
	freopen("call.in","r",stdin);
	freopen("call.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	cin>>m;
	for(int i=1;i<=m;i++)
	{
		cin>>q[i].t;
		if(q[i].t==1)cin>>q[i].a>>q[i].b;
		if(q[i].t==2)cin>>q[i].a;
		if(q[i].t==3)
		{
			cin>>q[i].a;
			q[i].kai=pos;
			for(int j=0;j<q[i].a;j++)cin>>q[i].kai[j];
			pos=pos+q[i].a;
		}
	}
	int o;
	cin>>o;
	for(int i=1;i<=o;i++)
	{
		int aa;
		cin>>aa;
		chu(aa);
	 } 
	 for(int i=1;i<=n;i++)cout<<a[i]<<" "; 
	
 } 
