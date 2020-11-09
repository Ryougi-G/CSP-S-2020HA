#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int lread()
{
	int x=0,f=1;char c=getchar();
	while(c>'9'||c<'0')
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
struct node
{
	int bh;
	int tl;
}a[1000010];
int cmp(node x,node y)
{
	if(x.tl==y.tl) return x.bh<y.bh;
	return x.tl<y.tl;
}
int t,n,k,tot;
int ans[15];
int main()
{
	freopen("snakes.in","r",stdin);
	freopen("snakes.out","w",stdout);
	
	t=lread();
	n=lread();
	for(int i=1;i<=n;++i)
	{
		a[i].bh=i;
		a[i].tl=lread();
    }
    tot=1;
    ans[1]=n;
	while(a[n].tl-a[tot].tl>=a[tot+1].tl&&ans[1]>2)
	{
		++tot;
		ans[1]--;
		a[n].tl-=a[tot].tl;
		sort(a+1,a+n+1,cmp);
	}
	if(ans[1]==2) ans[1]--;
	
	for(int i=2;i<=t;++i)
	{
		ans[i]=n;
		tot=1;
		k=lread();
		for(int j=1;j<=k;++j)
		{
			int xx,yy;
			xx=lread();
			yy=lread();
			for(int i=1;i<=n;++i)
			{
				if(a[i].bh==xx)
				{
					a[i].tl=yy;
					break;
				}
			}
		}
		while(a[n].tl-a[tot].tl>=a[tot+1].tl&&ans[i]>2)
		{
			ans[i]--;
			++tot;
			a[n].tl-=a[tot].tl;
			sort(a+1,a+n+1,cmp);
		}
		if(ans[i]==2) ans[i]--;
	}
	
	for(int i=1;i<=t;++i)
	{
		printf("%d\n",ans[i]);
	}
	
	fclose(stdin);fclose(stdout);
	return 0;
}
