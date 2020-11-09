#include<bits/stdc++.h>
using namespace std;
int T,n,sum=0,k;
struct she
{
	int xu;
	long long zhi;
}a[10000000];
bool mysep(she x,she y)
{
	return (x.zhi>y.zhi)||(x.zhi==y.zhi&&x.xu>y.xu);
}
bool mysp(she x,she y)
{
	return x.xu<y.xu;
}
long long huan[10000000];
int main()
{
	freopen("snakes.in","r",stdin);
	freopen("snakes.out","w",stdout);
	scanf("%d",&T);
//		memset(a,0,sizeof(a));
//		memset(huan,0,sizeof(huan))
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i].zhi),a[i].xu=i,huan[i]=a[i].zhi;
	sort(a+1,a+1+n,mysep);
	while((a[1].zhi-a[n-sum].zhi>a[n-sum-1].zhi)||(a[1].zhi-a[n-sum].zhi==a[n-sum-1].zhi&&a[1].xu>a[n-sum-1].xu))
	{
		sum++;
		a[1].zhi-=a[n-sum].zhi;
		sort(a+1,a+n-sum+1,mysep);
	}
	if(n-sum==2) 
	{
		if(a[1].zhi-a[2].zhi>0||(a[1].zhi==a[2].zhi&&a[1].xu>a[2].xu)) sum++;
	}
	cout<<n-sum;
	if(T!=1) cout<<endl;	
	for(int o=2;o<=T;o++)
	{
	sum=0;
	sort(a+1,a+n+1,mysp);
	scanf("%d",&k);
	for(int i=1;i<=2*k;i++)
	{
		long long liu;
		scanf("%lld",&liu);
		if(i%2==0)
		{
			int q=i/2;
			a[q].zhi=liu;
		}
	}
	for(int i=k+1;i<=n;i++)
	{
		a[i].zhi=huan[i];
	}
	sort(a+1,a+1+n,mysep);
	while((a[1].zhi-a[n-sum].zhi>a[n-sum-1].zhi)||(a[1].zhi-a[n-sum].zhi==a[n-sum-1].zhi&&a[1].xu>a[n-sum-1].xu))
	{
		sum++;
		a[1].zhi-=a[n-sum].zhi;
		sort(a+1,a+n-sum+1,mysep);
	}
	if(n-sum==2) 
	{
		if(a[1].zhi-a[2].zhi>0||(a[1].zhi==a[2].zhi&&a[1].xu>a[2].xu)) sum++;
	}
	cout<<n-sum;
	if(o!=T) cout<<endl;
	}
	return 0;
}
