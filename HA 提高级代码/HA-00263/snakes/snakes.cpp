#include<bits/stdc++.h>
using namespace std;
int t,n,b[50010];
#define rint register int
struct snake
{
	int pos,i;
} a[50010];
bool cmp(snake A,snake B)
{
	if(A.i==B.i)
	return A.pos>B.pos;
	else
	return A.i>B.i;
}
int main()
{
	freopen("snakes.in","r",stdin);
    freopen("snakes.out","w",stdout);
	cin>>t;
	int tot=0;
	while(t--)
	{
		int k;
		cin>>k;
		tot++;
		if(tot==1)
		{
			n=k;
			for(int i=1;i<=k;i++)
			scanf("%d",&b[i]);
		}
		else
		{
			for(int i=1;i<=k;i++)
		    {
			int x,y;
			scanf("%d%d",&x,&y);
			b[x]=y;
		    }
		}
		for(int i=1;i<=n;i++)
		a[i].pos=i,a[i].i=b[i];
		sort(a+1,a+n+1,cmp);
		if(n==3)
		{
			if(a[1].i>a[2].i+a[3].i)
			cout<<1<<endl;
			else if(a[1].i==a[2].i+a[3].i&&a[1].pos>a[2].pos)
			cout<<1<<endl;
			else
			cout<<3<<endl;
		}
		
	}
	return 0;
}
