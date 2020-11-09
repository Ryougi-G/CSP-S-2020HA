#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <iomanip>
#include <algorithm>
#include <cmath>
using namespace std;
long long n,m;
long long  t;
long long  a;
long long  p,v1;
long long  v2;
long long  c;
long long  q;
long long  we[100000],v[100000];
long long  f;
void fc1(long long  p,long long  v)
{
	we[p]+=v;
}

void fc2(long long  v)
{
	for(int i=1; i<=n; i++)
	{
		we[i] = we[i]*v;
	}
}

void fc3(long long  c)
{
	for(int i=1; i<=c; i++)
	{
		if(v[i]==1)
		{
			fc1(p,v1);
		}
		else if(v[i]==2)
		{
			fc2(v2);
		}
	}
}

int main()
{
 	freopen("call.in","r",stdin);
 	freopen("call.out","w",stdout);
	cin>>n;
	for(int i=1; i<=n; i++)
	{
		cin>>we[i];
	}
	cin>>m;
	for(int i=1; i<=m; i++)
	{
		cin>>t;
		if(t==1)
		{
			cin>>p>>v1;
		}
		else if(t==2)
		{
			cin>>v2;
		}
		else if(t==3)
		{
			cin>>c;
			for(int j=1; j<=c; j++)
			{	
				cin>>v[j]; 
			}
		}
	}
	cin>>q;
	for(int i=1; i<=q; i++)
	{
		cin>>f;
		if(f==1)
		{
			fc1(p,v1);
		}
		else if(f==2)
		{
			fc2(v2);
		}
		else if(f==3)
		{
			fc3(c);
		}
	}
	
	for(int i=1; i<=n; i++)
	{
		cout<<we[i]%998244353<<" ";
	}
	fclose(stdin);
	fclose(stdout);

	return 0;
}

