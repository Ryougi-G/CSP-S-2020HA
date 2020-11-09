#include<bits/stdc++.h>
using namespace std;
int a[100];
int main()
{
	freopen("call.in","r",stdin);
	freopen("call.out","w",stdout);
	int n,m;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		printf("%d ",a[i]);
	}
	return 0;
}
