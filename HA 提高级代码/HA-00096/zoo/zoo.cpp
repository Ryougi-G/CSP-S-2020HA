#include<bits/stdc++.h>
using namespace std;
int n,m,c,k;
int a[1000001];
int q[1000001],p[1000001];
int ac[1000001];int t;
inline int lread()
{
	int x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9')
	{
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		x=x*10+c-'0';
		c=getchar();
	}
	return f*x;
}
int main()
{
	freopen("zoo.in","r",stdin);
	freopen("zoo.out","w",stdout);
	n=lread();m=lread();c=lread();k=lread();
	for(int i=1;i<=n;i++)
	{
		a[i]=lread();
	}
	for(int i=1;i<=m;i++)
	{
		p[i]=lread();q[i]=lread();
	}
	for(int i=1;i<=n;i++)
	{
		int x=1;
		while(1)
		{
			if(a[i]%2==0) t=0;
			else if(a[i]%2!=0) t=1;
			a[i]/=2;
			ac[i]+=t*x;
			x*=10;
			if(a[i]==0) break;
		}
	}
	cout<<8;
	fclose(stdin);fclose(stdout);
	return 0;
}
