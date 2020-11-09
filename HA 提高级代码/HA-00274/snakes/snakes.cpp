#include<bits/stdc++.h>
#define N 1000006
#define LL long long 
#define mod 998244353
#define ull unsigned long long
using namespace std;

int t;
int n;
int a[1111];

inline int qr()
{
	int x=0,w=1;char a=0;
	while(a<'0'||a>'9'){if(w=='-')w=-1;a=getchar();}
	while(a<='9'&&a>='0'){x=(x<<3)+(x<<1)+(a^48);a=getchar();}
	return x*w;
}
int flag=1;

int main()
{
	freopen("snakes.in","r",stdin);
	freopen("snakes.out","w",stdout);
	t=qr();
	for(register int ol=1;ol<=t;ol++)
	{
		if(ol==1)
		{
			n=qr();
			for(register int i=1;i<=n;i++)
				a[i]=qr();
			int maxx=max(max(a[1],a[2]),a[3]);
			int minn=min(min(a[1],a[2]),a[3]);
			int wei1=0,wei2=0,wei3=0;
			for(register int i=1;i<=n;i++)
			{
				if(maxx==a[i])
					wei1=i;
				if(minn==a[i])
					wei3=i;
				if(a[i]!=maxx&&a[i]!=minn)
					wei2=i;
			}
			if(maxx-minn>=a[wei2])
			{
				cout<<3<<endl;
			}
			else
			{
				cout<<1<<endl;
				flag=0;
			}
				
			continue;
		}
		int k=qr();
		if(flag==0)
		{
			cout<<1<<endl;
			continue;
		}
		for(register int i=1;i<=k;i++)
		{
			int wei=qr();
			int zhi=qr();
			a[wei]=zhi;
		}
		int maxx=max(max(a[1],a[2]),a[3]);
		int minn=min(min(a[1],a[2]),a[3]);
		int wei1=0,wei2=0,wei3=0;
		for(register int i=1;i<=n;i++)
		{
			if(maxx==a[i])
				wei1=i;
			if(minn==a[i])
				wei3=i;
			if(a[i]!=maxx&&a[i]!=minn)
				wei2=i;
		}
		if(maxx-minn>=a[wei2])
			{
				cout<<3<<endl;
			}
			else
			{
				cout<<1<<endl;
				flag=0;
			}
				
	}
	return 0;
}
//2299160
