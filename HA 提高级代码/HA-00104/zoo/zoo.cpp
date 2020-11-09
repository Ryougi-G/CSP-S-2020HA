#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fint register int
const ll maxn=1e6+90;
ll n,m,c,k,t;
ll q[maxn],p[maxn];
queue <ll> dong [maxn];
bool vis[maxn*100];
int main(){
	freopen("zoo.in","r",stdin);
    freopen("zoo.out","w",stdout);
	cin>>n>>m>>c>>k;
	ll zong=0;
	for(fint i=0;i<=n-1;i++) scanf("%d",&t),zong=zong|t;
	for(fint i=1;i<=m;i++){
		scanf("%d%d",&p[i],&q[i]);
		if(zong&(1<<p[i])) vis[q[i]]=1;
		else dong[p[i]].push(q[i]);
	}
	ll ans=1;
	for(fint i=0;i<=k-1;i++){
		while(vis[dong[i].front()]) dong[i].pop();
		if(dong[i].empty()) ans=ans*2;
	}
	cout<<ans-n<<endl;
}

