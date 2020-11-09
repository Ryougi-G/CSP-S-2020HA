#include<bits/stdc++.h>
using namespace std;
unsigned long long a[1000001],s=0;
bool l[65]={0};
int main()
{
	freopen("zoo.in","r",stdin);
	freopen("zoo.out","w",stdout);
	unsigned long long i,j,n,m,c,k,p,q;
	cin>>n>>m>>c>>k;
	int e=k;
	for(i=1;i<=n;i++)
		cin>>a[i];
	for(j=1;j<=m;j++)
	{
		cin>>p>>q;
		if(l[p]==1)
			continue;
		unsigned long long w=1;
		for(i=1;i<=p+1;i++)
			w=w*2;
		int f=0;
		for(i=1;i<=n;i++)
		{
			int a1=a[i]%w;
			unsigned long long t=w/2;
			if(a1>=t)
			{
				f=1;
				break;
			}
		}
		if(f==0)
			l[p]=1;
	}
	unsigned long long w=1;
	for(i=1;i<=64;i++)
		if(l[i]==1)
			e--;
	for(i=1;i<=e;i++)
		w=w*2;
	cout<<w-n<<endl;
}
