#include<bits/stdc++.h>
using namespace std;
long long n,m,c,k;
long long km(long long x)
{
	if(x==1) return 2;
	if(x==0) return 1;
	long long t=km(x>>1);
	if(x%2==1)
	return t*t*2;
	else return t*t;
}
bool v[5505];
bool s[5505];
int main()
{
	freopen("zoo.in","r",stdin);
	freopen("zoo.out","w",stdout);
	cin>>n>>m>>c>>k;
	long long a;
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a);
		long long nn=0;
		while(a)
		{
			if(a%2==1)
			v[nn]=1;
			a>>=1;
			nn++;
		}
	}
	long long b,d;
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d",&b,&d);
		if(v[b]==1) s[d]=1;
	}
	long long mm=0;
	for(int i=c;i>=1;i--)
	{
		if(s[i]==1) mm+=1;
		mm<<=1;
	}
	cout<<min(km(k),mm)-n;
}
