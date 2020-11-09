#include<bits/stdc++.h>
#define N 1000006
#define LL long long 
#define mod 998244353
#define ull unsigned long long
using namespace std;

int n,m,q;
LL a[N],tr[N];
vector<int>c[100005];
int book[100006];
int jia[100006][2];
int cao[1000003],tot=0;
LL blo,laz[100000],bl[100005];

inline int qr()
{
	int x=0,w=1;char a=0;
	while(a<'0'||a>'9'){if(w=='-')w=-1;a=getchar();}
	while(a<='9'&&a>='0'){x=(x<<3)+(x<<1)+(a^48);a=getchar();}
	return x*w;
}

inline int lb(int x)
{
	return x&(-x);
}

inline void add(int x,LL k)
{
	while(x<=n)
	{
		tr[x]+=k;
		tr[x]%=mod;
		x+=lb(x);
	}
}

inline void mul(int x,LL k)
{
	while(x<=n)
	{
		tr[x]*=k;
		tr[x]%=mod;
		x+=lb(x);
	}
}

inline LL que(int x)
{
	LL ans=0;
	while(x)
	{
		ans+=tr[x];
		ans%=mod;
		x-=lb(x);
	}
	return ans;
}

void dfs(int x)
{
	if(book[x]!=3)
	{
		cao[++tot]=x;
		return ;
	}
	int jk=c[x].size();
	for(register int i=0;i<jk;i++)
		dfs(c[x][i]);
}

int main()
{
	freopen("call.in","r",stdin);
	freopen("call.out","w",stdout);
	n=qr();
	blo=sqrt(n);
	for(register int i=1;i<=n;i++)
		bl[i]=(i-1)/blo+1;
	for(register int j=1;j<=n/blo+1;j++)
		laz[j]=1;
	for(register int i=1;i<=n;i++)
	{
		a[i]=qr();
		add(i,a[i]);
	}
	m=qr();
	for(register int i=1;i<=m;i++)
	{
		int op=qr();
		if(op==3)
		{
			book[i]=3;
			int cj=qr();
			for(register int j=1;j<=cj;j++)
			{
				int ko=qr();
				c[i].push_back(ko);
			}
			continue;
		}
		if(op==1)
		{
			book[i]=2;
			jia[i][0]=qr();
			jia[i][1]=qr();
			continue;
		}
		book[i]=1;
		jia[i][0]=qr();
	}
	q=qr();
	for(register int i=1;i<=q;i++)
	{
		int ok=qr();
		if(book[ok]!=3)
		{
			cao[++tot]=ok;
			continue;
		}
		dfs(ok);
	}
	//for(register int i=1;i<=n;i++)
	//	cout<<bl[i]<<' ';
	//cout<<endl;
	for(register int i=1;i<=tot;i++)
	{
		if(book[cao[i]]==2)
		{
			int x=jia[cao[i]][0];
			int k=jia[cao[i]][1];
			//cout<<x<<' '<<k<<endl;
			for(register int j=(bl[x]-1)*blo+1;j<=bl[x]*blo;j++)
			{
				a[j]*=laz[x];
				a[j]%=mod;
			}
			a[x]+=k;
			laz[x]=1;
		}
		else
		{
			int lr=n/blo+1;
			for(register int j=1;j<=lr;j++)
				laz[j]=(laz[j]*jia[cao[i]][0])%mod;
		//	for(register int j=1;j<=lr;j++)
			//	cout<<laz[j]<<' ';
			//cout<<endl;
		}
	}
	for(register int i=1;i<=n;i++)
	{
		if(laz[bl[i]])
			a[i]=(a[i]*laz[bl[i]])%mod;
		printf("%lld ",a[i]);
	}
	printf("\n");
	return 0;
}
/*
10
1 2 3 4 5 6 7 8 9 10
8
3 2 2 3
3 2 4 5
3 2 5 8
2 2
3 2 6 7
1 2 5
1 7 6
2 3
3
1 2 3
*/
/*
5
1 2 3 4 5
3 
1 1 1 
2 3
2 3
4
1 2 1 2
 
*/
