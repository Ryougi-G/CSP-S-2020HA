#include<bits/stdc++.h>
using namespace std;
int n,m,c,k;
#define ll long long
int wei[105];
int a[1000005];
ll ans;
int main(){
	freopen("zoo.in","r",stdin);
	freopen("zoo.out","w",stout);
	cin>>n>>m>>c>>k;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=m;i++){
		int x,y;
		cin>>x>>y;
		a[x]=y;
	}
	for(int i=1;i<=k;i++){
		ans+=pow(2,i-1);
	}
	cout<<ans-m+1;
}
