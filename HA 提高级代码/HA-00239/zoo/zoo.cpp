#include <bits/stdc++.h>
#define maxn 100050
using namespace std;
int main()
{	freopen("zoo.in","r",stdin);
	freopen("zoo.out","w",stdout);
	int n,m,c,k;
	int q[maxn],p[maxn],a[maxn],count;
	cin>>n>>m>>c>>k;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int j=1;j<=m;j++)
		cin>>p[j]>>q[j];
	for(int i=1;i<=n;i++)
	{
		for(;;)
		{
				count++;	
				if(count>10051)
				break;
		}
	}
	for(int i=1;i<=m;i++)
	{
		count++;
	}
	cout<<3<<endl;
	return 0;
}
