#include<bits/stdc++.h>
#define MOD 998244353
using namespace std;
int n,a[100001],m,l1,l2,ys[100001],q;
struct node{
	int to,data;
}k1[100001],k2[100001];
vector<int> f1[100001],f[100001];
void find(int t)
{
	queue<int> Q;
	Q.push(t);
	while(!Q.empty())
	{
		int x=Q.front();
		Q.pop();
		for(int i=0;i<f1[x].size();i++)
		{
			if(ys[f1[x][i]]==3) Q.push(f1[x][i]);
			else f[t].push_back(f1[x][i]);
		}
	}
}
int jia(int k,int data)
{
	a[k]=(a[k]+data)%MOD;
}
int cheng(int data)
{
	for(int i=1;i<=n;i++)
	{
		a[i]=(a[i]*data)%MOD;
	}
}
void gusu(int x)
{
	if(ys[x]==1) jia(k1[x].to,k1[x].data);
	if(ys[x]==2) cheng(k2[x].data);
	if(ys[x]==3) {
		for(int i=0;i<f[x].size();i++)
		{
			gusu(f[x][i]);
		}
	}
}
int main()
{
	freopen("call.in","r",stdin);
	freopen("call.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",a+i);
	scanf("%d",&m);
	for(int i=1;i<=m;i++)
	{
		scanf("%d",&ys[i]);
		if(ys[i]==3)
		{
			int x;
			scanf("%d",&x);
			for(int j=1;j<=x;j++)
			{
				int y;
				scanf("%d",&y);
				f1[i].push_back(y);
			}
		}
		if(ys[i]==1)
		{
			scanf("%d%d",&k1[i].to,&k1[i].data);
		}
		if(ys[i]==2)
		{
			scanf("%d",&k2[i].data);
		}
	}
	for(int i=1;i<=m;i++)
	{
		if(ys[i]==3)
		{
			find(i);
		}
	}
	scanf("%d",&q);
	while(q--)
	{
		int x;
		scanf("%d",&x);
		gusu(x);
	}
	for(int i=1;i<=n;i++)
		printf("%d ",a[i]);
	return 0;
}

