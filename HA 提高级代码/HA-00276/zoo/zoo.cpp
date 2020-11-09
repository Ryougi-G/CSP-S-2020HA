#include <bits/stdc++.h>
#define rint register int
#define ull unsigned long long
using namespace std;

int n,m,k,c;
const int maxn=1e6+10;
ull a[maxn],req,satis;
ull ans;
int main()
{
//	freopen("D:\\csp-s(windows)\\zoo\\zoo3.in","r",stdin);
	freopen("zoo.in","r",stdin);
	freopen("zoo.out","w",stdout);
	scanf("%d%d%d%d",&n,&m,&c,&k);
	for(rint i=1;i<=n;i++)
		cin>>a[i],satis|=a[i];
	ans=1;
	for(rint i=1;i<=m;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		req|=(ull)(1ull<<x);
	}
	for(rint i=0;i<k;i++)
	{
		if((req&(1<<i))==0)
			ans*=2;
		else
			if(satis&(1<<i))
				ans*=2;
	}
	ans-=n;
	cout<<ans;
	return 0;
}

