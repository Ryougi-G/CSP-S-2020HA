#include<bits/stdc++.h>
using namespace std;
const int maxn=2010;
int n;
struct node1
{
	int ax,x;
	bool operator < (const node1 X) const 
	{
		if(X.ax==ax) return X.x<x;
		else return X.ax<ax;
	}
	bool operator == (const node1 X) const
	{
		if(ax==X.ax&&x==x) return true;
		else return false;
	}
};
node1 operator - (const node1 A,const node1 B)
{
	node1 C;
	C.ax=A.ax-B.ax;
	C.x=A.x;
	return C;
}
int q;
int a,b;
int data[maxn];
set<node1>S1;
int main()
{
	freopen("snakes.in","r",stdin);
	freopen("snakes.out","w",stdout);
	cin>>q;
	for(int o=1;o<=q;o++)
	{
		if(o==1)
		{
			cin>>n;
			for(int i=1;i<=n;i++) cin>>data[i];
			for(int i=1;i<=n;i++) S1.insert((node1){data[i],i});
			bool flag=true;
			while(flag)
			{
				if(S1.size()==1) {break;}
				set<node1>::iterator it;
				it=S1.begin(); node1 u=*it; 
				it=S1.end(); it--; node1 v=*it; 
				it--; node1 u1=*it;
				node1 tmp=u-v;
				if(tmp<u1||S1.size()==2)
				{
					S1.erase(u);
					S1.erase(v);
					S1.insert(tmp);
				}
				else {flag=false; continue;}
			}
			cout<<S1.size()<<endl;
		}
		else
		{
			cin>>n;
			for(int i=1;i<=n;i++)
			{
				cin>>a>>b;
				data[a]=b;
			}
			S1.clear();
			for(int i=1;i<=n;i++) S1.insert((node1){data[i],i});
			bool flag=true;
			while(flag)
			{
				if(S1.size()==1) {break;}
				set<node1>::iterator it;
				it=S1.begin(); node1 u=*it; 
				it=S1.end(); it--; node1 v=*it; 
				it--; node1 u1=*it;
				if(u==v) {flag=false; continue;}
				node1 tmp=u-v;
				if(tmp<u1||S1.size()==2)
				{
					u=u-v;
					it=S1.begin(); S1.erase(it);
					it=S1.end(); it--; S1.erase(it);
					S1.insert(u);
				}
				else {flag=false; continue;}
			}
			cout<<S1.size()<<endl;
		}
	}
}


