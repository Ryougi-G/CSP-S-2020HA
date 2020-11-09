#include<bits/stdc++.h>
using namespace std;
int n,m,o;
long long a[100009];
int b[100009];
int p[100009],v[100009],c[100009],q[10002][101];
int s[100009];
int x;
void t1(int x){
	a[p[x]]+=v[x];
	return ;
}
void t2(int x){
	for(int j=1;j<=n;j++)
		a[j]*=v[x];
	return ;
}
void t3(int x){
		for(int j=1;j<=c[x];j++){
	     	if(b[q[x][j]]==1)t1(q[x][j]);
	     	if(b[q[x][j]]==2)t2(q[x][j]);
	     	if(b[q[x][j]]==3)t3(q[x][j]);
		}
			return ;
}
int main(){
	freopen("call.in","r",stdin);
	freopen("call.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	cin>>m;
	for(int i=1;i<=m;i++){
		cin>>b[i];
		if(b[i]==1)cin>>p[i]>>v[i];
		if(b[i]==2)cin>>v[i];
		if(b[i]==3){
			cin>>c[i];
			for(int j=1;j<=c[i];j++)
				cin>>q[i][j];
		}
	}
	cin>>o;
	for(int i=1;i<=o;i++){
		cin>>x;
		if(b[x]==1)t1(x);
		if(b[x]==2)t2(x);
		if(b[x]==3)t3(x);
	}
	for(int i=1;i<n;i++)	cout<<a[i]%998244353<<' ';
	cout<<a[n]%998244353;
	return 0;
}
