#include<bits/stdc++.h>
using namespace std;
int n,m,c,k,a[1000000],b[1000000],d[1000000],l,p,e[1000000]={0},t;
set<int> s;
int low(int x)
{
	return x&(-x);
}
int g(int x)
{
	if(x!=1)
	{
		return g(x/2)+1;
	}else
	{
		return 0;
	}
}
int f(int x)
{
	if(x!=0)
	{
		return 2*f(x-1);
	}else
	return 1;
}
int main(){
freopen("zoo.in","r",stdin);
freopen("zoo.out","w",stdout);
cin>>n>>m>>c>>k;
for(int q=1;q<=n;q++)
{
	scanf("%d",&a[q]);
}
for(int q=1;q<=m;q++)
{
	scanf("%d%d",&b[q],&d[q]);
	s.insert(d[q]);
}
for(int q=1;q<=n;q++)
{
	while(a[q]!=0)
	{
		l=low(a[q]);
		a[q]=a[q]-l;
		p=g(l);
		for(int w=1;w<=m;w++)
		{
			if(b[w]=p)
			{
				s.erase(d[w]);
			}
		}
	}
}
t=s.size();
k=k-t;
cout<<f(k)-n;
return 0;
}
