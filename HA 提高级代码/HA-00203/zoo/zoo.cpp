#include<bits/stdc++.h>
#define N 1000100
using namespace std;
int n,m,c,k;
int a[N],p[N],q[N];bool f[N];
vector<int> ap[77];
vector<int> as[40];
int main()
{
	freopen("zoo.in","r",stdin);
	freopen("zoo.out","w",stdout);
	scanf("%d%d%d%d",&n,&m,&c,&k);
	int ym=1;
	for(register int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		f[a[i]]=1;
	}
	for(register int i=1;i<=m;i++)
	{
		scanf("%d%d",&p[i],&q[i]);
		ap[p[i]].push_back(q[i]);
	}
	for(int i=1;i<=k;i++)
		ym<<1;
	for(int i=1;i<=n;i++)
	{
		int t=k;
		int im=i;
		while(im)
		{
			t--;
			int pu=i&1;
			if(pu == 1)
			{
				
			}
			im>>1;
		}
	}
	return 0;
}
