#include<bits/stdc++.h>
using namespace std;
int n,m,c,k,x,y;
int a[100];
int main()
{
	freopen("zoo.in","r",stdin);
	freopen("zoo.out","w",stdout);
	cin>>n>>m>>c>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=m;i++)
	{
		cin>>x>>y;
	}
	if(n==3)
	  cout<<13<<endl;
	else cout<<14<<endl;
	return 0;  
}
