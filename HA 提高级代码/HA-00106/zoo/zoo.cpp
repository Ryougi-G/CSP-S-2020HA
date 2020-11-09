#include<bits/stdc++.h>
#define int long long
using namespace std;

int read()
{
	int x=0,f=1;
	char ch;
	ch=getchar( );
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')f=-1;
		ch=getchar( );
	}
	while(ch>='0'&&ch<='9')
	{
		x=x*10+ch-'0';
		ch=getchar( );
	}
	return x*f;
}

unsigned long long a[1000001];
unsigned long long da;
int ru[65];
int cnt;
int l[65];
unsigned long long u[64];
void fen(unsigned long long x)
{
	int ans=0;
	while(x>0)
	{
		if(x%2==1)
		{
			l[ans]=1;
		}	ans++;
		x=x/2;
	}

}

int n,m,c,k;
signed main( )
{
	freopen("zoo.in","r",stdin);
	freopen("zoo.out","w",stdout);
	n=read( );
	m=read( );
	c=read( );
	k=read( );
	for(int i=1;i<=n;i++)a[i]=read( );
	for(int i=1;i<=m;i++)
	{
		int x,y;
		cin>>x>>y;
		ru[x]++;
	}
	long long o=0;
	for(int i=1;i<=n;i++)fen(a[i]);
	for(int i=0;i<k;i++)
	{
		if(ru[i]==0)l[i]=1;
		if(l[i]==1)o++;
	}
	u[0]=1;
	for(int i=1;i<=63;i++)
	{
		u[i]=u[i-1]*2;
	}
	if(o<=63)
	{
		da=u[o]-n;
		cout<<da;
	}
	if(o==64)
	{
		if(n==0)
		{
			cout<<"18446744073709551616";
		}
		else 
		{
			da=u[63]-n+u[63];
			cout<<da;	
		}
		
	}
	
}

