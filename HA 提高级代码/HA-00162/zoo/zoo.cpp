	#include<bits/stdc++.h>
	#define ll long long
	using namespace std;
	const int maxn=1e6+5;
 	ll r[maxn],s[maxn],vis[66],cnt,v[66],w;
	ll q[maxn];
	int c[maxn];
 	void work(ll x){
 	for(int i=0;i<=31;i++){
	ll o=(1<<i);
 	if((o&x)==o) vis[i]=1;
	}}
	void work2(ll x){
 	for(int i=0;i<=64;i++){
	ll o=(1<<i);
 	if((o&x)==o) vis[i]=1;
	}}
 	map<int,int>mp;
	int main(){
	freopen("zoo.in","r",stdin);
	freopen("zoo.out","w",stdout);
	int n,m,z,k;
	
	cin>>n>>m>>z>>k;
	for(int i=1;i<=n;i++){
	cin>>q[i];
	if(w<q[i])w=q[i];}

	for(int i=1;i<=m;i++){
	if(w<=2147483647)work(q[i]);
	else 	work2(q[i]);}
	
	for(int i=1;i<=m;i++){
	cin>>r[i]>>s[i],v[r[i]]=1;
	if(vis[r[i]])mp[s[i]]=1;}
	
	for(int i=1;i<=m;i++){
	if(mp[s[i]]==1&&c[r[i]]==0) {
	c[r[i]]=1;
	++cnt;}}
	for(int i=0;i<k;i++)
	if(v[i]==0)
	++cnt;
	ll ans=pow(2,cnt)-n;cout<<ans;
	return 0;
	}
