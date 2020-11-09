#include<bits/stdc++.h>
#define fint register int
#define H 1001
#define N 1000001
using namespace std;
int a[N],b[N];
int n;
inline int read();
inline void sub_a();
inline void sub_b();
int main()
{
	freopen("snakes.in","r",stdin);
	freopen("snakes.out","w",stdout);
	int T;
	T=read();
	for(fint t=1;t<=T;t++)
	{
		if(t==1)
		{
			
			n=read();
			for(fint i=1;i<=n;i++)
			a[i]=read(),b[i]=a[i];
		}
		else
		{
			int k;
			k=read();
			for(fint i=1;i<=n;i++)
			a[i]=b[i];
			int x,y;
			for(fint i=1;i<=k;i++)
			x=read(),y=read(),a[x]=y;
		}
		if(n==3)
		sub_a();
		else
		sub_b();
	}
	return 0;
}

inline int read()
{
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')
		f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
	}
	return x*f;
}

inline void sub_a()
{
	if(a[3]-a[1]<a[2])
	cout<<3<<endl;
	else
	cout<<1<<endl;
	return ;
}

inline void sub_b()
{
	int hea=a[10],now=n,min_id=1,max_id=n;
	while(1)
	{
		if(hea-a[min_id]<a[max_id])
		break;
		else
		hea-=a[min_id],now--,min_id++;
	}
	cout<<now<<endl;
	return ;
}
