#include<bits/stdc++.h>
using namespace std;
const int N=1900000;
int a[N];
int p[N],q[N];
int n,m,k;
long long num=0;
long long c;
vector<int> dic[100];
map<int,int> vis;
inline long long read()
{
	long long num=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9') {if(ch=='-') f=-1; ch=getchar();}
	while(ch>='0'&&ch<='9') {num=(num<<1)+(num<<3)+ch-'0'; ch=getchar();}
	return num*f;
}
long long now=0;
inline int get(long long c)
{
	for(int i=0;i<=64;i++) if(c&(1<<i)) return i;
}
inline void dicc(long long xx)
{
	for(long long i=xx;i;i-=i&-i) 
	{
		long long x=i&-i; int t=get(x);
		for(int j=0;j<dic[t].size();j++) vis[dic[t][j]]=1; 
	} 
}
inline void solve()
{
	long long ans=num; 
	for(int i=now;i;i-=i&-i)
	{
		int x=i&-i; 
		ans-=(long long)(num/(long long)(c*2))*c;
	}
	cout<<ans-n;
}
int main()
{
	freopen("zoo.in","r",stdin);
	freopen("zoo.out","w",stdout);
	n=read(),m=read(),c=read(),k=read(); num=(long long)1<<k;
	long long cc=0;
	for(int i=1;i<=n;i++)
	{
		a[i]=read();
		cc|=a[i];
	}
	for(int i=1;i<=m;i++) 
	{
		p[i]=read(),q[i]=read();
		dic[p[i]].push_back(q[i]);
	}
//	for(int i=0;i<dic[1].size();i++) printf("%d ",dic[1][i]);
	dicc(cc); 
	// 找不能有1的位置 
	for(int i=1;i<=m;i++) 
	{
		if(vis[q[i]]) continue;		
		now|=p[i]; 
	} 
	solve();
	return 0;
}
