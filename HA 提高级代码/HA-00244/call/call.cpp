#include<bits/stdc++.h>
using namespace std;
long long a[100001],b[100002];
long long addp[100001],adda[100001];
int cheng[100001];
int num[100001],useing[100001][1001];
long long q,w,e,r;

int aadd(int x,int y)
{
	a[x]=a[x]+y;
}

int ccxx(int x)
{
	for(int i=1;i<=q;i++)
	{
		a[i]=a[i]*x;
	}
}

int main()
{
	freopen("call.in","r",stdin);
	freopen("call.out","w",stdout);
	cin>>q;
	for(int i=1;i<=q;i++)
	{
		cin>>a[i];
	}
	cin>>w;
	for(int i=1;i<=w;i++)
	{
		cin>>b[i];
		if(b[i]==1)
		{
			cin>>addp[i]>>adda[i];
		}
		if(b[i]==2)
		{
			cin>>cheng[i];
		}
		if(b[i]==3)
		{
			cin>>num[i];
			for(int l=1;l<=num[i];l++)
			{
				cin>>useing[i][l];
			}
		}
	}
	cin>>e;
	for(int i=1;i<=e;i++)
	{
		cin>>r;
		if(b[r]==1)
		{
			aadd(addp[r],adda[r]);
		}
		if(b[r]==2)
		{
			ccxx(cheng[r]);
		}
		if(b[r]==3)
		{
			for(int l=1;l<=num[r];l++)
			{
				if(useing[r][l]==1)
				{
					aadd(addp[useing[r][l]],adda[useing[r][l]]);
				}
				if(useing[r][l]==2)
				{
					ccxx(cheng[useing[r][l]]);
				}
			}
		}
	}
	for(int i=1;i<=q;i++)
	{
		cout<<a[i]<<" ";
	}
	return 0;
}
