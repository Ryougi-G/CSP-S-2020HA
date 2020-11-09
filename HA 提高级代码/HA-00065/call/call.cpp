#include<bits/stdc++.h>
using namespace std;
#define MAX 998244353
long long n,a[100086],m;
struct node{
	long long hsz,jiaxb,jiaz,chengz,hh[1086],hhgs;
}b[100086];
void jia(long long i,long long j)
{
	a[i]+=j;
	return ;
}
void cheng(long long j)
{
	j%=MAX;
	for(long long i=1;i<=n;i++)
	{
		a[i]*=j;
		a[i]%=MAX;
	}
	return ;
}
void hhs(long long x)//xÎª±àºÅ 
{
	for(long long i=1;i<=b[x].hhgs;i++)
	{
		long long w=b[x].hh[i];
		if(b[w].hsz==1) jia(b[w].jiaxb,b[w].jiaz);
		if(b[w].hsz==2) cheng(b[w].chengz);
		if(b[w].hsz==3) hhs(w);
	}
}
int main()
{
	freopen("call.in","r",stdin);
	freopen("call.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++)
	{
		cin>>a[i];
		a[i]%=MAX;
	}
	cin>>m;
	for(long long i=1;i<=m;i++)
	{
		long long t;
		cin>>t;
		if(t==1) cin>>b[i].jiaxb>>b[i].jiaz,b[i].hsz=1;
		if(t==2) cin>>b[i].chengz,b[i].hsz=2;
		if(t==3) 
		{
			b[i].hsz=3;
			cin>>b[i].hhgs;
			for(long long j=1;j<=b[i].hhgs;j++)
			{
				cin>>b[i].hh[j];
			}
		}
	}
	long long q;
	cin>>q;
	while(q--)
	{
		long long t;
		cin>>t;
		if(b[t].hsz==1) jia(b[t].jiaxb,b[t].jiaz);
		if(b[t].hsz==2) cheng(b[t].chengz);
		if(b[t].hsz==3)
		{
			hhs(t);
		}
	}
	cout<<a[1];
	for(long long i=2;i<=n;i++)
	{
		cout<<" "<<a[i];
	}
	return 0;
}
