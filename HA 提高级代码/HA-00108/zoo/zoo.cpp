#include<bits/stdc++.h>
#define ll long long
using namespace std;
template<typename T>
inline void read(T &x)
{
	int f=1;x=0;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-') f=-1;ch=getchar();}
	while(isdigit(ch)){x=x*10+ch-'0';ch=getchar();}x*=f;
}
const int N=1e6+10;
int n,m,c,k,a[N],p[N],q[N];
bool v[N];

int main()
{
	freopen("zoo.in","r",stdin);
	freopen("zoo.out","w",stdout);
	read(n),read(m),read(c),read(k);
	for(int i=1;i<=n;i++) read(a[i]);
	for(int i=1;i<=m;i++)
	{
		read(p[i]),read(q[i]);
		for(int j=1;j<=n;j++)
			if((a[j]>>p[i])&1) v[i]=1;
	}
	printf("%d",(1<<k)-n);return 0;
}
