#include<bits/stdc++.h>
using namespace std;
int t,n,a[1000001];
bool v[1000001];
struct node{
	int name,data;
	bool operator < (const node &x) const{
		if(x.data==data) return x.name>name;
		return x.data<data; 
	}
	bool operator > (const node &x) const{
		if(x.data==data) return x.name<name;
		return x.data>data; 
	}
};
int main()
{
	freopen("snakes.in","r",stdin);
	freopen("snakes.out","w",stdout);
	scanf("%d",&t);
	for(int ttt=1;ttt<=t;ttt++)
	{
		priority_queue<node> qmin;
		priority_queue<node,vector<node>,greater<node> > qmax;
		if(ttt==1)
		{
			scanf("%d",&n);
			for(int i=1;i<=n;i++)
			{
				scanf("%d",a+i);
				qmax.push(node{i,a[i]});
				qmin.push(node{i,a[i]});
				v[i]=1;
			}
		}
		else
		{
			int k;
			scanf("%d",&k);
			for(int i=1;i<=k;i++)
			{
				int xx,yy;
				scanf("%d%d",&xx,&yy);
				a[xx]=yy;
			}
			for(int i=1;i<=n;i++)
			{
				qmax.push(node{i,a[i]});
				qmin.push(node{i,a[i]});
				v[i]=1;
			}
		}
		int len=n;
		while(!qmax.empty()&&!qmin.empty()&&len>=1)
		{
			if(len==1) {
				puts("1");
				break;
			}
			while(!v[qmax.top().name]) qmax.pop();
			node x=qmax.top(),y=qmin.top();
			qmin.pop();
			node z=qmin.top();
			if(x.data-y.data<z.data||(z.name>x.name&&x.data-y.data==z.data))
			{
				printf("%d\n",len);
				break;
			}
			else {
				qmin.push(node{x.name,x.data-y.data});
				qmax.push(node{x.name,x.data-y.data});
				v[y.name]=0;
				qmax.pop();
			}
		}
	}
	return 0;
}

