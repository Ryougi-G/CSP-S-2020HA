#include<bits/stdc++.h>
using namespace std;
int n,m,c,k;
int z[31],chuan[31][31]={0},flagliang[100]={0},flagzoo[31]={0},ans=0,lk[31],jk[31],lg=0;
int main()
{
	freopen("zoo.in","r",stdin);
	freopen("zoo.out","w",stdout);
	cin>>n>>m>>c>>k;
	for(int i=1;i<=n;i++)cin>>z[i];
	for(int i=1;i<=m;i++)cin>>lk[i]>>jk[i];
	for(int i=1;i<=30;i++)
	{
		int g=i,ls=1,lchuan[31]={0};
		while(g)
		{
			lchuan[ls]=g%2;
			g/=2;
//			cout<<lchuan[ls];
			ls++;
		}
		for(int j=ls;j>=1;j--)chuan[i][j]=lchuan[j];
	}
	for(int i=1;i<=m;i++)
	{
		int s=lk[i],l=jk[i];
		for(int j=1;j<=n;j++)
			if(chuan[z[j]][s]==1){flagzoo[l]=1;lg++;}
	}
	for(int i=1;i<=m;i++)
	{
		int s=lk[i],l=jk[i];
		for(int j=1;j<=30;j++)
			if(chuan[j][s]==1&&flagzoo[l]==1)ans++;
	}
	cout<<ans-n;
	return 0;
}
