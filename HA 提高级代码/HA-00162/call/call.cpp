	#include<bits/stdc++.h>
	#define ll long long
	using namespace std;
	const int maxn=1e3+5;
	const int mod=998244353;
	struct qw{int to,next;
	}a[maxn*2];
	int viss[maxn][maxn],n,cnt[maxn],bh[maxn][maxn],vis[maxn],head[maxn],tot,s[maxn],tp[maxn],num[maxn],add[maxn],ru[maxn];
	void adde(int x,int y){
	a[++tot].to=y;a[tot].next=head[x];head[x]=tot;}
	
	void dfs(int x,int sta){
	//cout<<x<<sta<<endl;
	for(int i=head[x];i;i=a[i].next){
	int to=a[i].to;
	if(vis[to])continue;
	vis[to]=1;
	if(viss[to][sta]==0){
	viss[to][sta]=1;
	bh[to][++cnt[to]]=sta;	
	}
	
	dfs(to,sta);
	}}
	
	void work(int x){
	//cout<<"W"<<x<<endl;
	if(tp[x]==1) s[num[x]]+=add[x],s[num[x]]%=mod;
	else for(int i=1;i<=n;i++)s[i]*=num[x],s[i]%=mod;
	//for(int j=1;j<=n;j++)cout<<s[j]<<' ';cout<<endl;
	}
	int main(){
	freopen("call.in","r",stdin);
	freopen("call.out","w",stdout);
	int m,q,w,e;
	cin>>n;
	for(int i=1;i<=n;i++)cin>>s[i];
	cin>>m;
	for(int i=1;i<=m;i++){
	cin>>q;
	if(q==1)cin>>w>>e,tp[i]=1,num[i]=w;add[i]=e;
	if(q==2) cin>>w,tp[i]=2,num[i]=w;
	if(q==3){
	cin>>w;
	for(int j=1;j<=w;j++)cin>>e,adde(e,i),++ru[i];}}
	for(int i=1;i<=n;i++){
	if(ru[i]==0){
	memset(vis,0,sizeof(vis));
	dfs(i,i);	
	}}
	cin>>q;
	//for(int i=1;i<=n;i++)cout<<cnt[i];
	for(int i=1;i<=q;i++){
	cin>>w;
	if(ru[w]==0)work(w);
	else for(int j=1;j<=cnt[w];j++)
	work(bh[w][j]);	
	}
	for(int i=1;i<=n;i++)cout<<s[i]<<' ';
	return 0;
	}
