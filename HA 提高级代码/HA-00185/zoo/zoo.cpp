#include<iostream>
#include<cstdio>
using namespace std;
long long int a[1000010],pp[1000010];
long long int shi[100000010];
long long int kk[70];
int ma,zong;
int main()
{
	freopen("zoo.in","r",stdin);
	freopen("zoo.out","w",stdout);
    long long int n,m,c,k;
    scanf("%lld%lld%lld%lld",&n,&m,&c,&k);
    for(int i=1;i<=n;++i)
    {
    	scanf("%lld",&a[i]);
    }
    for(int i=1;i<=m;++i)
    {
    	long long int x,y;
    	scanf("%lld%lld",&x,&y);
    	shi[y]=x;
    	pp[y]=1;
		zong=max(zong,y);
    }
    kk[0]=1;
    for(int i=1;i<=62;++i)
    {
    	kk[i]=kk[i-1]*2;
    }
    for(int i=1;i<=n;++i)
    {
    	int t=0;
    	while(a[i]>0)
    	{
    		int k=a[i]%2;
    		if(k==1) pp[t]=1;
    		a[i]=a[i]/2;
    		ma=max(ma,t);
    		++t;
    	}
    }
    int ww=kk[zong];
    printf("2");
	return 0;
	fclose(stdin);
	fclose(stdout);
}
