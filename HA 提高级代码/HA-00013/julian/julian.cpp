#include<bits/stdc++.h>
using namespace std;
int y,m,d,f[10001],ld,n,li;
int main()
{
	int b;
	freopen("julian.in","r",stdin);
	freopen("julian.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&f[i]);
	}
	for(int i=1;i<=n;i++)
	{
		if(f[i]<=1723779)
		{
			int a=0,d;
			for(int j=-4713;j<=-1;j++)
			{
				if(j<0)
				{
					if((j+1)%4==0)
					{
					a+=365;
					}
					else
					a+=366;
				}
				if(a>f[i])
				{
					li=j;
					if((li+1)%4==0)
					d=365-a+f[i];
					else
					d=366-a+f[i];
					ld=d;
					break;
				}
			}
		}
		printf("%d %d %d",li,ld);
	}
	return 0;
}
