#include<bits/stdc++.h>
using namespace std;
int n,m,k,c,a[100001],p[100001],q[100001],food[10001],cnt=1;
bool mxy=false;
int main(){
	freopen("zoo.in","r",stdin);
	freopen("zoo.out","w",stdout);
	cin>>n>>m>>c>>k;
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1;i<=m;i++)scanf("%d%d",&p[i],&q[i]);
for(int i=1;i<n;i++){
	a[i]=a[i]^a[i+1];
}cout<<(1<<k)-a[n]<<endl;
	return 0;
}
