#include<bits/stdc++.h>
using namespace std;
int sj[100001],q[100001];
int main(){
	freopen("call.in","r",stdin);
	freopen("call.out","w",stdout);
	int n,m,zl,x,y,g,z,p;
	cin>>n;
	for(int i=1;i<=n;i++) cin>>sj[i];
	cin>>m;
	for(int i=1;i<=m;i++){
		cin>>zl;
	if(zl==1){cin>>x>>y;}
	if(zl==2){cin>>z;}
	if(zl==3){cin>>g;
	for(int k=1;k<=g;k++){
	cin>>q[k];}}}
	cin>>p;
	for(int i=1;i<=p;i++){
		cin>>zl;
		if(zl==1){sj[x]+=y;
		}
		if(zl==2){for(int j=1;j<=n;j++) sj[j]*=z;
		}
		if(zl==3){for(int k=1;k<=g;k++){
			if(q[k]==1) sj[x]+=y;
			if(q[k]==2) for(int j=1;j<=n;j++) sj[j]*=z;
		}}  
	}
	for(int i=1;i<=n;i++) cout<<sj[i]%998244353<<" ";
	return 0;}




