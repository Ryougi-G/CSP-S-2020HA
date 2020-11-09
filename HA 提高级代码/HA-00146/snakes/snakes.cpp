#include<bits/stdc++.h>
#define rint register int
using namespace std;
int n,m,t,a[10005],k,x,y,b[10005];
priority_queue<pair<int,int> > q,p;
int main()
{
	freopen("snakes.in","r",stdin);
	freopen("snakes.out","w",stdout);
	cin>>t;
	for(rint j=1;j<=t;j++)
	{
		if(j==1)
		{
			scanf("%d",&n);
			for(rint i=1;i<=n;i++)
			scanf("%d",&a[i]),b[i]=a[i];
		}
		else
		{
			scanf("%d",&k);
			//q.clear();p.clear();
			for(rint i=1;i<=k;i++)
			{
				scanf("%d%d",&x,&y);
				b[x]=y;
			}
			int l=0,r=n;
			while(!q.empty())
			{
				q.pop();p.pop();
			}
			for(rint i=1;i<=n;i++)
			q.push(make_pair(b[i],i)),p.push(make_pair(-b[i],i));
			while(l<r-1&&!q.empty())
			{
				int u=q.top().second,v=p.top().second;
				q.pop();p.pop();
				if(b[u]-b[v]<q.top().first||(b[u]-b[v]==q.top().first&&u<q.top().second)) break;
				q.push(make_pair(b[u]-b[v],u));p.push(make_pair(-(b[u]-b[v]),u));
				l++;
			}
			cout<<l;
		}
	}
	return 0;
}
