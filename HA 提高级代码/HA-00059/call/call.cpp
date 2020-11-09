#include<bits/stdc++.h>
using namespace std;
vector<int> Group[100500];
long long a[10050],n,m,q;
int top[100500],op[100500];
long long Chen=1,C[100500];
int x,y;
void dfs(int x)
{
	if(op[x]==1)
	{
		a[Group[x][0]]=(Chen/C[Group[x][0]])*a[Group[x][0]]+Group[x][1];
		C[Group[x][0]]=Chen;
		return;
	}
	if(op[x]==2)
	{
		Chen*=Group[x][0];
		return;
	}
	else
	{
		for(int i=0;i<top[x];i++)
		{
			dfs(Group[x][i]);
		}
	}
}
int main()
{
	freopen("call.in","r",stdin);
	freopen("call.out","w",stdout);	
	cin>>n;
	for(int i=1;i<=n;i++)
	C[i]=1;
	for(int i=1;i<=n;i++)
	scanf("%d",&a[i]);
	cin>>m;
	for(int i=1;i<=m;i++)
	{
		int opt,len;
		scanf("%d",&opt);
		op[i]=opt;
		if(opt==3)
		{
		scanf("%d",&len);
			top[i]=len;
			for(int j=1;j<=len;j++)
			{
				scanf("%d",&x);
				Group[i].push_back(x);		
			}			
		}
		if(opt==1)
		{
			scanf("%d%d",&x,&y);
			Group[i].push_back(x);
			Group[i].push_back(y);			
		}
		if(opt==2)
		{
			scanf("%d",&x);
			Group[i].push_back(x);		
		}		
	}
	cin>>q;
	for(int i=1;i<=q;i++)
	{
		scanf("%d",&x);
		dfs(x);
	}
	for(int i=1;i<=n;i++)
	{
		printf("%lld ",a[i]*(Chen/C[i]));
	}
	return 0;
}

