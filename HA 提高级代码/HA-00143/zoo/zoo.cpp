#include <bits/stdc++.h>
using namespace std;
unsigned long long w;
unsigned long long zoo(long long k)
{
	w=1;
	for(int i=1;i<=k;i++)
	{
		w*=2;
	}
	return w;
}
unsigned long long s[10000000];
long long jinzhi(long long q)
{
	//ch.clear();
	int i=0;
	long long a[10000000];
	while(q!=0||q!=1)
	{
		
		a[i]=q%2;
		q/=2;
		i++;
	}
	a[i]=q;
	for(;i>=0;i--)
	{
		s[i]+=a[i];
		cout<<s[i]<<endl;
	}
}
unsigned long long animal[100000000];//a[10000],b[10000];
int main(void)
{
	bool flag=true;
	long long n,k,c,m,ans=0;
	cin>>n>>m>>c>>k;
	zoo(k);
	for(int i=1;i<=n;i++)
	{
		cin>>animal[i];
	}
	for(int i=1;i<=n;i++)
	{
		int p,l;
		cin>>p>>l;
		for(int o=0;o<w;o++)
		{
			flag=true;
			jinzhi(i);
			for(int j=0;j<n;j++)
			{
				if(o==animal[j])
				{
					flag=false;
					break;
				}
			}
			if(s[p]==l&&flag)
			{
				ans++;
			}
		}
	}
cout<<ans<<endl;
	return 0;
}
