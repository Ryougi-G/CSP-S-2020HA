#include<bits/stdc++.h>
using namespace std;
int n,m,c,k,cnt;
int p[1000010],q[1000010];
unsigned long long a[1000010],orsum,ans=1;
bool vis[100000010],wei[70];
inline int read()
{
	int x=0,w=0;char ch=0;
	while(!isdigit(ch)){w|=ch=='-';ch=getchar();}
	while(isdigit(ch)){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
	return w?-x:x;
}
int main()
{
	freopen("zoo.in","r",stdin);
	freopen("zoo.out","w",stdout);
	n=read();m=read();c=read();k=read();
	orsum=0;
	for(int i=1;i<=n;i++){
		scanf("%llu",&a[i]);
		orsum|=a[i];
	}
	for(int i=1;i<=m;i++){
		p[i]=read(),q[i]=read();
		if((orsum>>p[i])&1)
			vis[q[i]]=1;
	}
	for(int i=1;i<=m;i++)
	if(!vis[q[i]])wei[p[i]]=1;
	sort(p+1,p+1+m);
	m=unique(p+1,p+1+m)-p-1;
	for(int i=1;i<=m;i++)
	if(wei[p[i]]==0)continue;
	else k--;
	for(int i=1;i<=k;i++)
	ans=ans*2;
	if(n==0&&k==64){
		cout<<"18446744073709551616\n";
	}else cout<<ans-n<<'\n';
}
