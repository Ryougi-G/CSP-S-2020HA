#include<bits/stdc++.h>
#define ll long long
#define db double
using namespace std;
const int M=1000005;
ll n,m,c,k;
int a[M];
struct node{
	int p,q;
}b[M];
bool check(ll x,int y)
{return x&(1<<y);}
int main()
{
	freopen("zoo.in","r",stdin);
	freopen("zoo.out","w",stdout);
	scanf("%lld%lld%lld%lld",&n,&m,&c,&k);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=m;i++)
		scanf("%d%d",&b[i].p,&b[i].q);
	ll ani=0,si=0;
	for(int i=1;i<=n;i++)
		ani=ani|a[i];
	for(int i=1;i<=m;i++){
		if(!check(ani,b[i].p))
			si=si|(1<<b[i].p);
	}
	ll ans=1;
	for(int i=0;i<k;i++)
		if(!check(si,i)) ans*=2;
	ans-=n;
	printf("%lld",ans);
	return 0;
}
