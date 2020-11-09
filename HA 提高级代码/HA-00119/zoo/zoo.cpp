#include<iostream>
#include<cstdio>
using namespace std;
long long int a[1000010];
bool pd[65];
int main()
{
	freopen("zoo.in","r",stdin);
	freopen("zoo.out","w",stdout);
	long long int s=1;
	long long int x=0,y=0,n=0,m=0,c=0,k=0;
	cin>>n>>m>>c>>k;
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		for(int j=0;j<k;j++)
		{
			if((a[i]&(1<<j))!=0)
			{
				pd[j]=1;
			}
		}
	}
	for(int i=1;i<=m;i++)
	{
		scanf("%lld%lld",&x,&y);
		if(pd[x]==0)
		{
			k--;
			pd[x]=1;
		}
	}
	for(int i=1;i<=k;i++)
	{
		s=s<<1;
	}
	s=s-n;
	cout<<s<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
