#include<bits/stdc++.h>
using namespace std;
const int N=2100,inf=1e9;
int a[N];
int n,cnt;
void work()
{
	if(cnt==1) return ;
	if(cnt==2) 
	{
		cnt--;
		return;
	} 
	if(a[cnt]-a[1]<a[2]&&cnt>=3) return;
	a[cnt]-=a[1]; a[1]=inf; 
	sort(a+1,a+1+cnt);
	cnt--;
	work();
}
int main()
{
	freopen("snakes.in","r",stdin);
	freopen("snakes.out","w",stdout);
	int T;
	scanf("%d",&T);
	for(int ka=1;ka<=T;ka++)
	{
		if(ka==1)
		{
			scanf("%d",&n);
			for(int i=1;i<=n;i++)
				scanf("%d",&a[i]);
		}
		else 
		{
			int k;
			scanf("%d",&k);
			for(int i=1;i<=k;i++)
			{
				int x,y;
				scanf("%d%d",&x,&y);
				a[x]=y;
			}
		}
		cnt=n;
		work();
		printf("%d\n",cnt);
	}
	return 0;
}
