#include <bits/stdc++.h>
using namespace std;
int t,n,a[1000010],num,xx,yy;
bool mysort(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("snakes.in","r",stdin);
	freopen("snakes.out","w",stdout);
	scanf("%d",&t);
	scanf("%d",&n);
	for(int j=1;j<=n;j++)
	{
		scanf("%d",&a[j]);
	}
	sort(a+1,a+1+n,mysort);
	if(n>4)
	while(((a[1]-a[n])>=a[2])||((a[2]-(a[1]-a[n]))>=a[3])||((a[3])-(a[2]-(a[1]-a[n]))>=a[4]))
	{
		a[1]-=a[n];
		n--;
		sort(a+1,a+1+n,mysort);
	}
	else
	while(((a[1]-a[n])>=a[2]))
	{
		a[1]-=a[n];
		n--;
		sort(a+1,a+1+n,mysort);
	}
	printf("%d\n",n);
	for(int i=2;i<=t;i++)
	{
		scanf("%d",&num);
		for(int j=1;j<=num;j++)
		{
			scanf("%d%d",&xx,&yy);
			a[xx]=yy;
		}
		sort(a+1,a+1+n,mysort);
		if(a[1]==0)
		{
			printf("%d\n",n);
			continue;
		}
		if(n>4)
		while(((a[1]-a[n])>=a[2])||((a[2]-(a[1]-a[n]))>=a[3])||((a[3])-(a[2]-(a[1]-a[n]))>=a[4]))
		{
			a[1]-=a[n];
			n--;
			sort(a+1,a+1+n,mysort);
		}
		else
		while(((a[1]-a[n])>=a[2]))
		{
			a[1]-=a[n];
			n--;
			sort(a+1,a+1+n,mysort);
		}
		printf("%d\n",n);
	}
	return 0;
}
