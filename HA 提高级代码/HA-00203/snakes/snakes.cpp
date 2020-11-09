#include<bits/stdc++.h>
using namespace std;
int po[3000100];
int st,ed,tot=0;
int main()
{
	freopen("snakes.in","r",stdin);
	freopen("snakes.out","w",stdout);
	int T,n,a,b;
	scanf("%d",&T);
	scanf("%d",&n);
		for(register int i=1;i<=n;i++)
		{
			scanf("%d",&a);
			po[i]=a;
		}
		if(n==3)
		{
			tot=0;
			if(po[3]-po[1]>=po[2])
			{
				cout<<1<<endl;
			}
			else
			{
				cout<<3<<endl;
			}	
		}
	for(int e=2;e<=T;e++)
	{
		scanf("%d",&n);
		for(register int i=1;i<=n;i++)
		{
			scanf("%d%d",&a,&b);
			po[a]=b;
		}
		if(n==3)
		{
			tot=0;
			if(po[3]-po[1]>=po[2])
			{
				cout<<1<<endl;
				break;
			}
			else
			{
				cout<<3<<endl;
				break;
			}
			
		}
	}
	return 0;
}
