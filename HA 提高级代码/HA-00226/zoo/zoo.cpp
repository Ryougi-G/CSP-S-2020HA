#include<bits/stdc++.h>
using namespace std;
typedef long long int ull;
inline int read()
{
	int sum=0;
	char ch=getchar();
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9') {
		sum=sum*10+ch-48;
		ch=getchar();
	}
	return sum;
}
inline long long int lread()
{
	ull sum=0;
	char ch=getchar();
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9') {
		sum=sum*10+ch-48;
		ch=getchar();
	}
	return sum;
}
int n,m,c,k;
int a[1000001][64],num[65];
void zhuanhuan(ull ai,int i)
{
	int ki=1;
	while(ai>0)
	{
		int numi;
		numi=ai%2;
		a[i][ki]=numi;
		ai=ai/2;
		ki++;
	}
	ki--;
	a[i][0]=ki;
	return ;
}
int main()
{
	freopen("zoo.in","r",stdin);
	freopen("zoo.out","w",stdout);
	n=read();m=read();c=read();k=read();
	for(int i=1;i<=n;i++)
	{
		ull ai=lread();
		zhuanhuan(ai,i);
	}
	for(int i=1;i<=k;i++)
	num[i]=1;
	for(int i=1;i<=m;i++)
	{
		int x=read(),y=read();
		int flag=0;
		for(int j=1;j<=n;j++)
		{
			if(a[j][x+1]==1) flag=1;
		}
		if(flag==0)
		{
			num[x+1]=0;
		}
	}
	ull ans=1;
	for(int i=1;i<=k;i++)
	if(num[i]==1)
	ans=ans*2;
	ans-=n;
	printf("%lld",ans);
	return 0;
}
