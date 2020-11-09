#include<bits/stdc++.h>
using namespace std;
int n,m,c,k;
int a[1000010],p[1000010],q[1000010];
bool cc[1000010];
int ans=0,flag=0;
int jin[50]={0,1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,65536,131072,262144,524288,1048576,2097152,4194304,8388608,16777216,33554432,67108864,134217728,268435456,536870912,1073741824};
struct node
{
	bool er[100];
}num[10010];
void zhuan(int x,int ii);
int main()
{
	freopen("zoo.in","r",stdin);
	freopen("zoo.out","w",stdout);
	scanf("%d%d%d%d",&n,&m,&c,&k);
	for(int i=1;i<=n;++i)
	{
		scanf("%d",&a[i]);
		zhuan(a[i],i);
	}
	for(int i=1;i<=m;++i)
	{
		scanf("%d%d",&p[i],&q[i]);
		for(int j=1;j<=n;++j)
		{
			if(num[j].er[p[i]]==1)
			{
				flag=1;
				break;
			}
		}
		if(flag==0)
		{
			cc[q[i]]=1;
		}
	}
	memset(num,0,sizeof(num));
	flag=0;
	for(int i=0;i<jin[k+1];++i)
	{
		for(int j=1;j<=n;++j)
		{
			if(i==a[j])
			{
				continue;
			}
		}
		zhuan(i,i);
		for(int j=1;j<=m;++j)
		{
			if(num[j].er[p[j]]==1)
			{
				flag=1;
			}
		}
		if(flag==0)
		{
			ans++;
		}
	}
	printf("%d",ans);
	return 0;
}
void zhuan(int x,int ii)
{
	int t=33;
	while(x>0)
	{
		for(int i=1;i<=t;++i)
		{
			if(jin[i]>x)
			{
				x=x-jin[i-1];
				t=i-1;
			}
		}
		num[ii].er[t]=1;
	}
	
}
