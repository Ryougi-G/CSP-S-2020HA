#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<cstring>
using namespace std;
long long int bo[65],a[20000],b[20000];
int cc[200000];
bool wei[2000],ps[2000];
long long int cbow(int x);
int main()
{
	freopen("zoo.in","r",stdin);
	freopen("zoo.out","w",stdout);
	long long int n,m,c,k;
	bool ff;
	cin>>n>>m>>c>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int j=1;j<=m;j++)
	{
		cin>>b[j]>>cc[j];
	}
	for(int i=0;i<=k;i++)
	{
		ps[i]=true;
	}
	int tt;
	
	for(int i=1;i<=m;i++)
	{
		ps[b[i]]=false;
		
		for(int j=1;j<=n;i++)
		{
			ff=a[j] & cbow(b[i]);
			if(ff||wei[cc[i]])
			{
				
				tt=cc[i];
				wei[tt]=true;
				ps[b[i]]=true;
				break;
			}
	    }
	}
	
	int ans=0;
	for(int i=0;i<=k;i++)
	{
		if(ps[i])
		{
			ans++;
		}
	}
	cout<<cbow(ans)-n;
}

long long int cbow(int x)
{
	if(bo[32]!=0)
	{
		return bo[x];
	}
	if(x==0)
	{
		bo[x]=1;
		return bo[x];
	}
	if(x==1)
	{
		bo[x]=2;
		return bo[x];
	}
	if(x%2==0)
	{
		bo[x]=cbow(x/2)*cbow(x/2);
		return bo[x];
	}
	else
	{
		bo[x]=cbow(x-1)*2;
		return bo[x];
	}
}
