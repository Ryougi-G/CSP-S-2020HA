#include<bits/stdc++.h>
using namespace std;
struct node
{
	int num,val;
}a[200000];
int bas[300000];
bool cmp(node a,node b)
{
	if(a.val==b.val) return a.num<b.num;
	return a.val<b.val;
}
int vis[100000];
int main()
{
	freopen("snakes.in","r",stdin);
	freopen("snake.out","w",stdout);
	int T;
	scanf("%d",&T);
	for(int i=1;i<=T;++i)
	{
		int k;int n;
		if(i==1)
		{
			scanf("%d",&n);
			for(int j=1;j<=n;++j)
			{
				a[j].num=j;
				scanf("%d",&bas[j]);
				a[j].val=bas[j];
			}
		}
		else
		{
			scanf("%d",&k);
			for(int j=1;j<=k;++j)
			{
				int x,y;
				scanf("%d%d",&x,&y);
				bas[x]=y;
			}
			for(int j=1;j<=n;++j)
			{
				a[j].val=bas[j];
			}
		}
		sort(a+1,a+n+1,cmp);
		int l=1,r=n;
		int ans=n;
		int f;
		while(l<r)
		{
			if(a[r].val-a[l].val>=a[r-1].val)
			{
				a[r].val-=a[l].val;++l;--ans;
			}
			else --r;
		}
		printf("%d\n",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
