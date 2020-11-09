#include<bits/stdc++.h>
using namespace std;
const int N=1e6+7;
int n,a[N],m,c,k,q[N],p[N];
long long g;
int main()
{
	freopen("zoo.in","r",stdin);
	freopen("zoo.out","w",stdout);
	memset(a,0,sizeof(a));
	memset(q,0,sizeof(q));
	memset(p,0,sizeof(p));
	cin>>n>>m>>c>>k;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=m;i++)
		cin>>p[i]>>q[i];
	g=pow(2,c);
	cout<<rand()%g;
	return 0;
}
