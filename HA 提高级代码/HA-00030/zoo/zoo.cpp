#include <bits/stdc++.h>
using namespace std;
#define fo(i,a,b) for(register int i=a;i<=b;i++)
typedef long long ll;
const int maxn=1e6+5;
const int maxm=1e8+5;
ll n,m,c,k,a[maxn],q[maxn],p[maxn],f1[maxm],f2[maxm];
inline ll read(){
	bool f=0;char c=getchar();ll x=0;
	while(!isdigit(c)){
		if(c=='-') f=1;
		c=getchar();
	}
	while(isdigit(c)){
		x=(x<<1)+(x<<3)+(c^48);
		c=getchar();
	}
	return f==1?-x:x;
}

int main(){
	freopen("zoo.in","r",stdin);
	freopen("zoo.out","w",stdout);
	n=read();m=read();c=read();k=read();
	fo(i,1,n) a[i]=read();
	fo(i,1,m) p[i]=read(),q[i]=read(),f1[p[i]]++,f2[q[i]]=1;
	unsigned long long ans=0;
	ans=1<<k;
	ans-=m;
	cout<<ans<<endl;
	return 0;
	
}
