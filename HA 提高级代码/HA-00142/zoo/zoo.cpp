#include<cstdio>
#include<cstdlib>
#include<cctype>
#include<algorithm>
#include<vector>
#include<queue>
#include<stack>
#include<cstring>
#include<iostream>
#include<cmath>
#include<map>

#define int long long
#define MAXN 100005

using namespace std;

inline int read(){
	int w=0,f=1;
	char ch=getchar();
	while(!(ch>='0'&&ch<='9')){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch>='9'){
		w=(w<<1)+(w<<3)+(ch-48);
	}
	return w*f;
}

int n,m,c,k;
int a[MAXN],p[MAXN],q[MAXN];
vector<int>v;
bool vis[MAXN];

int e1[MAXN];
bool ejz(int x,int k){
	int cnt=0;
	while(x){
		e1[cnt++]=x%2;
		x/=2;
	}
	if(e1[k]==1)return 1;
	else return 0;
}

bool check(int x){
	for(vector<int>::iterator it=v.begin();it!=v.end();it++){
		if(ejz(x,p[*it]))return 0;
	}
	return 1;
}

int ans=0;
bool mp[1100000];

signed main(void){
	
	freopen("zoo.in","r",stdin);
	freopen("zoo.out","w",stdout);
	
	scanf("%lld%lld%lld%lld",&n,&m,&c,&k);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		mp[a[i]]=1;
	}
	for(int i=1;i<=m;i++){
		scanf("%lld%lld",&p[i],&q[i]);
	}
	
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(ejz(a[j],p[i]))vis[i]=1;
		}
	}
	
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){
			if(i==j)continue;
			if(q[i]==q[j]){
				if(vis[i]||vis[j]){
					vis[j]=vis[i]=1;
				}
			}
		}
	}
	
//	puts("QAQ");
//	for(int i=1;i<=m;i++)cout<<vis[i]<<" ";
//	puts("QAQ\n");
	
	for(int i=1;i<=n;i++){
		if(!vis[i])v.push_back(i);
	}
	
//	for(vector<int>::iterator it=v.begin();it!=v.end();it++){
//		printf("QwQ: %d\n",*it);
//	}
	
	for(int i=0;i<(1<<k);i++){
		if(mp[i])continue;
//		printf("%d\n",i);
		if(check(i)){
//			printf("qwq: %d\n",i);
			ans++;
		}
	}
	
	printf("%lld\n",ans);

	return 0;
}


