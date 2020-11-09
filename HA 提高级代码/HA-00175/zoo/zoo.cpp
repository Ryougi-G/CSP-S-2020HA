#include<bits/stdc++.h>
#define rint register int
#define N 1000005
#define UL  long long
inline int read(){
	int f=1,x=0;char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
	return x*f;
}
int n,m,c,k,del,cnt,del2,pm;
int a[N],p[N],q,x[N];
bool vis[N],vis2[N];
int ans;
using namespace std;
int main(){
	freopen("zoo.in","r",stdin);
	freopen("zoo.out","w",stdout);
	memset(vis,0,sizeof(vis));
	n=read();m=read();c=read();k=read();
	/*for(int i=1;i<=n;i++){
		a[i]=read();
		del=(del|a[i]);
	}
	for(int i=1;i<=m;i++){
		p=read();q=read();
		if(((del>>p)&1)==1) vis[q]=1,vis2[p]=1;
		del2=(del2|(1<<p));
		pm=max(pm,p);
	}
	//del2=(del2&del);
	cout<<del2<<pm<<endl;
	for(int i=0;i<(1<<k);i++){
		int xx=i%(1<<(pm+1));
		if(del2>=(del2|xx)) 
		{
			cout<<i<<" "<<(del2|xx)<<endl;
		}
	}*/
	for(rint i=1;i<=n;i++){
		a[i]=read();
		del=(del|a[i]);
	}
	for(rint i=1;i<=m;i++){
		p[i]=read();q=read();
		vis[i]=((del>>p[i])&1);
		for(rint j=0;j<(1<<k);j++){
			if(!vis2[j])
			{
			    if(((j>>p[i])&1)==1&&vis[i]==0) 
				{
					ans++,vis2[j]=1;
				}
			}
			
		}
	}
	cout<<(1<<k)-n-ans;
	return 0;
}
