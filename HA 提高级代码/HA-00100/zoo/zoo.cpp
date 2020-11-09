#include<bits/stdc++.h>
using namespace std;

inline int read(){
	int x=0,t=1; char ch=getchar();
	while((ch<'0'||ch>'9')&&ch!='-') ch=getchar();
	if(ch=='-') t=-1,ch=getchar();
	while(ch<='9'&&ch>='0') x=x*10+ch-48,ch=getchar();
	return x*t;
}

#define maxn 10
#define maxm 20
#define maxc 20
int n,m,c,k;
int a[maxn];
int p[maxm],q[maxm];
int mapp[50][50];
bool vis_c[maxc];
int all;

signed main(){
	freopen("zoo.in","r",stdin);
	freopen("zoo.out","w",stdout);
	n=read(); m=read(); c=read(); k=read();
	for(register int i=1;i<=n;++i){
		a[i]=read();
	}
	for(register int i=1;i<=m;++i){
		p[i]=read(); q[i]=read();
	}
	for(register int i=1;i<=k;++i){
		if(all==0) all+=2;
		else all*=2;
	}
	printf("%d\n",all-n);
return 0;
}
