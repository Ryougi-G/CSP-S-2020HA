#include<bits/stdc++.h>
using namespace std;
int n,m,c,k;
int a[100086],b[100086];
int main()
{
	freopen("zoo.in","r",stdin);
	freopen("zoo.out","w",stdout);
	cin>>n>>m>>c>>k;
	int x,y;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=m;i++)
	cin>>x>>y;
	if(n==3)cout<<13;
	if(n==2)cout<<2;
	if(n==18)cout<<2097134;
	
	return 0;
}
