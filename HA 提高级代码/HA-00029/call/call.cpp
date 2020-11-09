#include <bits/stdc++.h>
using namespace std;
int n,a[10001],m,t,c,f,b[1000001],p[3][10001],v[3][10001],x,y,t1,t2;
void oN1()
{
	int y;
	y=p[0][++t1];
	a[y]+=p[1][t1];
}
void oN2()
{
	for(int i=1;i<=n;++i)
		a[i]*=p[2][++t2];
}
void oN3()
{
	for(int i=1;i<=c;++i)
		if(b[i]==1)oN1();
		else oN2();
}
int main()
{
	freopen("call.in","r",stdin);
	freopen("call.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;++i)
		scanf("%d",&a[i]);
	cin>>m;
	for(int i=1;i<=m;++i)
	{
		cin>>t;
		if(t==1)
		{
			cin>>x>>y;
			p[0][++t1]=x;
			p[1][t1]=y;
		}
		if(t==2)
		{
			cin>>x>>y;
			p[2][++t2]=x;
		}
		if(t==3)
		{
			cin>>c;
			for(int j=1;j<=c;++j)
				scanf("%d",&b[i]);
		}
	}
	cin>>f;
	t1=0,t2=0;
	for(int i=1;i<=f;++i)
	{
		scanf("%d",&m);
		if(m==1)oN1();
		else if(m==2)oN2();
		else oN3();
	}
	for(int i=1;i<=n;++i)
		cout<<a[i]<<" ";
	return 0;
}
