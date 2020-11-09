#include<bits/stdc++.h>
using namespace std;

inline int read(){
	int x=0,t=1; char ch=getchar();
	while((ch<'0'||ch>'9')&&ch!='-') ch=getchar();
	if(ch=='-') t=-1,ch=getchar();
	while(ch<='9'&&ch>='0') x=x*10+ch-48,ch=getchar();
	return x*t;
}

#define maxn 20010
#define maxm 20010
#define mod 998244353
int n,m,tj;
int a[maxn];
struct C{
	int flag;
	int vj,pj;
}ca[maxm];
int pf,fi;
queue<int> q;

struct EDGE{
	int to,next;
}edge[maxn];
int head[maxn],cnt;

inline void add(int u,int v){
	edge[++cnt].to=v;
	edge[cnt].next=head[u];
	head[u]=cnt;
}
int sum[maxn],cnt1;
inline void work(int s){
		sum[++cnt1]=s;
	for(register int i=head[s];i;i=edge[i].next){
		int v=edge[i].to;
		work(v);
	}	
}

signed main(){
	freopen("call.in","r",stdin);
	freopen("call.out","w",stdout);
	n=read();
	for(register int i=1;i<=n;++i) a[i]=read();
	m=read();
	for(register int i=1;i<=m;++i){
		tj=read();
		ca[i].flag=tj;
		if(tj==1){
			ca[i].pj=read(); ca[i].vj=read();
		}
		else if(tj==2){
			ca[i].vj=read(); ca[i].pj=0;
		}
		else{
			ca[i].pj=0; ca[i].vj=1;
			int cj=read();pf++;
			for(register int j=1;j<=cj;++j){
				int vi=read();
				add(i,vi);
			}
		}
	}
	if(pf==0){
		int Q=read();
		for(register int i=1;i<=Q;++i){
			fi=read();
			if(ca[fi].flag==1){
				a[ca[fi].pj]+=ca[fi].vj;
				a[ca[fi].pj]%=mod;
			}
			else{
				for(register int i=1;i<=n;++i){
					a[i]=a[i]*a[ca[fi].vj]%mod;
				}
			}
		}
		for(register int i=1;i<=n;++i) printf("%d ",a[i]);
	}
	else{
		int Q=read();
		for(register int i=1;i<=Q;++i){
			fi=read();
			if(ca[fi].flag==1){
				a[ca[fi].pj]+=ca[fi].vj;
				a[ca[fi].pj]%=mod;
			}
			else if(ca[fi].flag==2){
				for(register int i=1;i<=n;++i){
					a[i]=a[i]*ca[fi].vj%mod;
				}
			}
			else{cnt1=0;
				work(fi);
				
	for(register int i=cnt1;i>=1;--i){
		int v=sum[i];
			if(ca[v].flag==1){
				a[ca[v].pj]+=ca[v].vj;
				a[ca[v].pj]%=mod;
			}
			else if(ca[v].flag==2){
				for(register int i=1;i<=n;++i){
					a[i]=a[i]*ca[v].vj%mod;
				}
			}
		}
			}
		}
		for(register int i=1;i<=n;++i) printf("%d ",a[i]);
	}
	return 0;
}
