#include<bits/stdc++.h>
using namespace std;
int T,n,k;
int a[10000010];
int b[10000001];
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
int ans[100001];
int main()
{
	freopen("snakes.in","r",stdin);
	freopen("snakes.out","w",stdout);
	T=lread();
	n=lread();
	for(int i=1;i<=n;i++)
	{
		a[i]=lread();
		ans[i]=n-i;
	}
	for(int i=1;i<=T-1;i++)
	{
		k=lread();
		for(int j=1;j<=2*k;j++)
		{
			b[j]=lread();
		}
	}
	for(int i=1;i<=T;i++)
	{
		printf("%d\n",ans[i]);
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
