#include<bits/stdc++.h>
using namespace std;
int n,ans[100010],m;
vector <int> a[100010];
void work1(int x,int y)
{
	ans[x]+=y;
}
void work2(int x)
{
	for(int i=1;i<=n;i++) ans[i]*=x;
}
void work3(int x)
{
	for(int i=1;i<a[x].size();i++)
	{
		int z=a[x][i];
		int y=a[z][0];
		if(y==1) work1(a[z][1],a[z][2]);
		else if(y==2) work2(a[z][1]);
		else if(y==3) work3(z);
	}
}

int main()
{
	freopen("call.in","r",stdin);
	freopen("call.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&ans[i]);
	scanf("%d",&m);
	for(int i=1;i<=m;i++)
	{
		int x;
		scanf("%d",&x);
		a[i].push_back(x);
		if(x==1) 
		{
			int y,z;
			scanf("%d%d",&y,&z);
			a[i].push_back(y);
			a[i].push_back(z);
		}
		else if(x==2)
		{
			int y;
			scanf("%d",&y);
			a[i].push_back(y);
		}
		else
		{
			int y;
			scanf("%d",&y);
			for(int j=1;j<=y;j++)
			{
				int z;
				scanf("%d",&z);
				a[i].push_back(z);
			}
		}
	}
	int k;
	scanf("%d",&k);
	for(int i=1;i<=k;i++)
	{
		int x;
		scanf("%d",&x);
		int y=a[x][0];
		if(y==1) work1(a[x][1],a[x][2]);
		else if(y==2) work2(a[x][1]);
		else if(y==3) work3(x);
	}
	for(int i=1;i<=n;i++) printf("%d ",ans[i]);
	return 0;
}
