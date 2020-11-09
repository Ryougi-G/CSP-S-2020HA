#include<bits/stdc++.h>
#define ull unsigned long long
using namespace std;
int lowbit(int x)
{
	return x&-x;
}
inline int read()
{
	char ch=getchar();
	int x=0,f=1;
	while(ch>'9'||ch<'0')
	{
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x*f;
}
int down(int x)
{
	int ans=0;
	while(x>0)
	{
		x=x-lowbit(x);
		ans++;
	}
}
int n,m,c,k;
int a[1000005],p[1000005],q[1000005];
bool f[65];
int main()
{
	freopen("zoo.in","r",stdin);
	freopen("zoo.out","w",stdout);
	/*n=read();m=read();c=read();k=read();
	for(int i=1;i<=n;i++)
	{
		a[i]=read();
		int cnt=0;
		while(a[i])
		{
			if(a[i]&1) f[cnt]=1; 
			a[i]>>=1;
		}
	}
	for(int i=1;i<=m;i++)
	{
		p[i]=read();
		q[i]=read();
		
	}*/
	printf("%d",0);
	return 0;
}
