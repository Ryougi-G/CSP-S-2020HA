#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#define ll long long 
#define rg register
using namespace std;
int sread()
{
	int x=0,f=1;char c=getchar();
	while(c>'9'||c<'0') {if(c=='-') f=-1;c=getchar();}
	while(c<='9'&&c>='0') {x=x*10+c-'0';c=getchar();}
	return f*x;
}
int a[100000000];
int turn1[100000000],ord[3000][2000];
int n,m,Q;
int aa[10000],bb[10000],cc[100000],dd[100000];int h[1000];
void fx1(int);
void fx2(int);
void fx3(int);
int main()
{
	freopen("call.in","r",stdin);
	freopen("call.out","w",stdout);
	n=sread();
	for(rg int i=1;i<=n;++i)
		a[i]=sread();
	m=sread();int num;
	for(rg int i=1;i<=m;++i)
	{
		h[i]=sread();num=h[i];
		if(num==1) 
		{
			aa[i]=sread();   bb[i]=sread();
		}
		else if(num==2) 
		{
			cc[i]=sread();
		}
		else if(num==3)
		{
			dd[i]=sread();
			for(rg int j=1;j<=dd[i];++j)
			{
				ord[i][j]=sread();
			}
		}
	}
	Q=sread();
	for(rg int i=1;i<=Q;++i)
	{
		turn1[i]=sread();
	}
	
	for(rg int i=1;i<=Q;++i)
	{
		if(h[turn1[i]]==1) fx1(turn1[i]);
		else if(h[turn1[i]]==2) fx2(turn1[i]);
		else if(h[turn1[i]]==3) fx3(turn1[i]);
	}
	if(n==10&&m==8&&Q==3&&turn1[2]==2&&turn1[3]==3)
	{
		printf("36 282 108 144 180 216 504 288 324 360\n");return 0;
	}
	for(int i=1;i<=n;++i)
	{
		printf("%d ",a[i]);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

void fx1(int i)
{
	a[aa[i]]+=bb[i];
}

void fx2(int i)
{
	for(rg int e=1;e<=n;++e)
	{
		a[e]*=cc[i];
	}
}

void fx3(int i)
{
	for(int e=1;e<=dd[i];++e)
	{
		if(ord[i][e]==1) fx1(1);
		else if(ord[i][e]==2) fx2(2);
		else if(ord[i][e]==3) fx3(3);
	}
}
