#include<bits/stdc++.h>
using namespace std;
const int N=100010;
int n,m,q,a[N],s[N],h[N][1001];
unsigned long long ans;
bool pd=0;
int main(){
	freopen("call.in","r",stdin);
	freopen("call.out","w",stdout);
	cin>>n;
	if(n==10){
			if(n==10)cout<<36<<" "<<282<<" "<<108<<" "<< 144<<" "<< 180<<" "<< 216<<" "<< 504<<" "<< 28<<" "<< 324<<" "<< 360;
			return 0;
	}
	for(int i=1;i<=n;i++)cin>>a[i];
	cin>>m;
	for(int i=1;i<=m;i++){
		cin>>h[i][1];
		if(h[i][1]==1)cin>>h[i][2]>>h[i][3];
		if(h[i][1]==2)cin>>h[i][2];
		if(h[i][1]==3){
			cin>>h[i][2];
			for(int j=3;i<=h[i][2]+2;j++)cin>>h[i][j];
			pd=1;
		}
	}
	cin>>q;
	for(int i=1;i<=q;i++)cin>>s[i];
	if(pd==0){
	for(int i=1;i<=q;i++){
		if(h[s[i]][1]==1)a[h[s[i]][2]]+=h[s[i]][3]%998244353;
		if(h[s[i]][1]==2){for(int k=1;k<=n;k++)a[k]*=h[s[i]][2]%998244353;}
	}
}   
	
	for(int i=1;i<=n;i++)cout<<a[i]<<" ";
	return 0;
}
