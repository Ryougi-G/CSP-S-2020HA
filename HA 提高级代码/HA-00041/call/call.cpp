#include<bits/stdc++.h>
using namespace std;
int c[12340],a1w[12340],a2w[12340],a1b[12040],a3w[52340],a3e[1100][1234];
int a,m;
int b[20001];
int a1(int o)
{
	b[a1w[o]]+=a1b[o];
}
int a2(int o)
{
	for(int q=1;q<=a;q++) b[q]*=a2w[o];
}
int a3(int o)
{
//	cout<<"a"<<endl;
	for(int i=1;i<=a3w[o];i++)
	{
		
		if(c[a3e[o][i]]==1) 
		{
//			cout<<"a"<<endl;
			a1(a3e[o][i]);
		}
		if(c[a3e[o][i]]==2)
		{
//			cout<<"a"<<endl;
			a2(a3e[o][i]);
		} 
		if(c[a3e[o][i]]==3) a3(a3e[o][i]);
	}
}
int main()
{
	freopen("call.in","r",stdin);
	freopen("call.out","w",stdout);
	cin>>a;
	for(int i=1;i<=a;i++) cin>>b[i];
	cin>>m;
	for(int i=1;i<=m;i++)
	{
		cin>>c[i];
		if(c[i]==1)
		{
			cin>>a1w[i]>>a1b[i];
		}
		if(c[i]==2)
		{
			cin>>a2w[i];
		}
		if(c[i]==3)
		{
			cin>>a3w[i];
			for(int q=1;q<=a3w[i];q++)
			{
				cin>>a3e[i][q];
			}
		}
	}
	int p;
	cin>>p;
	for(int i=1;i<=p;i++)
	{
		int u;
		cin>>u;
		if(c[u]==1) a1(u);
		if(c[u]==2) a2(u);
		if(c[u]==3) {
		a3(u);}
	}
	for(int i=1;i<=a;i++)
	{
		cout<<b[i];
		cout<<' ';
	}
	return 0;
}




