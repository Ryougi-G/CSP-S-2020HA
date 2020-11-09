#include<bits/stdc++.h>
#define DMY_AK_CSP2020 return 0
using namespace std;
int k,n,m,c,tmp[3];
int a[100001],q[100001],ans;
bool s[100000001][2],f[100000001];
bool v[100000001];
bool w;
inline lowbit_(int x){return x&(-x);}
bool search(int x){
	if(v[x]) return f[x];
	if(x-lowbit_(x)){
		bool res;
		res=search(x-lowbit_(x));
		res=(res&(s[q[lowbit_(x)]][1]));
		v[x]=1;
		return f[x]=res;
	}else{
		v[x]=1;
		return f[x]=(!s[q[x]][0])|(s[q[x]][1]);
	}
}
int main()
{
	freopen("zoo.in","r",stdin);
	freopen("zoo.out","w",stdout);
	scanf("%d%d%d%d",&n,&m,&c,&k);
	memset(q,0,sizeof(q));
	memset(s,0,sizeof(s));
	for(int i=1;i<=n;++i) scanf("%d",&a[i]);
	for(int i=1;i<=m;++i){
		scanf("%d%d",tmp+0,tmp+1); 
		q[tmp[0]]=tmp[1];s[tmp[1]][0]=1;
	}
	for(int i=1;i<=n;++i){
		int tmp=a[i];
		for(int j=0;j<k&&tmp<=(1<<j);++j)
		{ 
			if((tmp&(1<<j))&&q[j])
				s[q[j]][1]=1;		
		}
	}
	for(int w=0;w<(1<<k);++w){
		if(!v[w]) search(w);
		if(f[w]) ++ans;
	}
	printf("%d",0);
	DMY_AK_CSP2020;
}
