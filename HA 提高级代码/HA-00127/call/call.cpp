#include <bits/stdc++.h>
using namespace std;
const int mod=998244353;
int a[1005];
int t[1005],x[1005],y[1005],z[1005],c[1005],p[1005][1005];
int n;
int dfs(int s){
	if (t[s]==1){
		a[x[s]]+=y[s];a[x[s]]%=mod; 
	}
	if (t[s]==2){
		for (int j=1;j<=n;j++){
			a[j]*=x[s];a[j]%=mod;
		}
	}
	if (t[s]==3){
		for (int j=1;j<=c[s];j++){
			dfs(p[s][j]);
		}
	}
	return 0;
}
int main(){
	freopen ("call.in","r",stdin);
	freopen ("call.out","w",stdout);
	cin>>n;
	for (int i=1;i<=n;i++){
		cin>>a[i];
	}
	int m;
	cin>>m;
	for (int i=1;i<=m;i++){
		cin>>t[i];
		if (t[i]==1){
			cin>>x[i]>>y[i];
		}
		if (t[i]==2){
			cin>>x[i];
		}
		if (t[i]==3){
			cin>>c[i];
			for (int j=1;j<=c[i];j++){
				cin>>p[i][j];
			}
		}
	}
	int q;
	cin>>q;
	for (int i=1;i<=q;i++){
		int f;cin>>f;
		dfs(f);
	}
	for (int i=1;i<=n;i++){
		cout<<a[i]%mod<<" ";
	}
	return 0;
}
