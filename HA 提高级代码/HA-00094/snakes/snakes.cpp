#include<bits/stdc++.h>
using namespace std;
#define rint register int
inline int read()
{
	int x=0,f=1;
	char c=getchar();
	while(!isdigit(c))
	{
		if(c=='-')
		f=-1;
		c=getchar();
	}
	while(isdigit(c))
	{
		x=(x<<3)+(x<<1)+c-'0';
		c=getchar();
	}
	return x*f;
}
const int maxn=1000007;
int te,k,x,y,n,b[maxn],pre,head;
long long s1,s2,a[maxn],l[maxn];
bool cmp(int a1,int b)
{
	return a[a1]>a[b];
}
inline void pwork()
{
	if(n==3)
	{
		if(a[3]>a[1]+a[2])
		printf("1\n");
		else
		printf("3\n");
		return ;
	}
	for(rint i=1;i<=n;i++)
		l[i]=i;
	int h=0;
	sort(l+1,l+n-h+1,cmp);
	while(1)
	{
		h++;
		if(b[l[n-h+1]])
		{
			printf("%d\n",n-b[l[n-h+1]]+1);
			return ;
		}
		a[n+h]=a[l[1]]-a[l[n-h+1]];
		b[n+h]=h;
		l[1]=n+h;
		sort(l+1,l+n-h+1,cmp);
	}
}
int main()
{
	freopen("snakes.in","r",stdin);
	freopen("snakes.out","w",stdout);
	te=read();
	n=read();
	for(rint i=1;i<=n;i++)
	a[i]=read();
	pwork();
	while(te>1)
	{
		te--;
		k=read();
		for(rint i=1;i<=k;i++)
		{
			x=read();
			y=read();
			a[x]=y;
		}
		pwork();
	}
	return 0;
}
