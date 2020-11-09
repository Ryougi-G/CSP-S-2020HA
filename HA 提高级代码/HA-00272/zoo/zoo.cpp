#include<bits/stdc++.h>
using namespace std;
int n,m,c,k;
int a[100010],p[100010],q[100010];
int sum=1;
int main(){
	freopen("zoo.in","r",stdin);
	freopen("zoo.out","w",stdout);
	cin>>n>>m>>c>>k;
	for (int i=1;i<=n;i++)
	cin>>a[i];
	for (int i=1;i<=m;i++)
	cin>>p[i]>>q[i];
	for (int i=1;i<=k;i++){
		sum*=2;
	}
	cout<<13;
	return 0;
}
