#include<bits/stdc++.h>
using namespace std;
int call[100001][3][1001],sj[100001],f;
int n,m,t,q;
void f1(int a){
	sj[call[a][0][0]]+=call[a][0][1];
	return;
}
void f2(int a){
	for(int k=1;k<=n;k++)sj[k]*=call[a][1][0];
	return;
}
void f3(int a){
	for(int j=1;call[a][2][j]!=0;j++){
		if(call[call[a][2][j]][0][0]!=0)f1(call[a][2][j]);
		if(call[call[a][2][j]][1][0]!=0)f2(call[a][2][j]);
		if(call[call[a][2][j]][2][1]!=0)f3(call[a][2][j]);
	}	
}
int main(){
	freopen("call.in","r",stdin);
	freopen("call.out","w",stdout);	
	cin>>n;
	for(int i=1;i<=n;i++)cin>>sj[i];
	cin>>m;
	for(int i=1;i<=m;i++){
		cin>>t;
		if(t==1)cin>>call[i][0][0]>>call[i][0][1];
		if(t==2)cin>>call[i][1][0];
		if(t==3){
			int sl;
			cin>>sl;
			for(int j=1;j<=sl;j++)cin>>call[i][2][j];
		}
	}
	cin>>q;
	for(int i=1;i<=q;i++){
		cin>>f;
		if(call[f][0][0]!=0)f1(f);
		if(call[f][1][0]!=0)f2(f);
		if(call[f][2][1]!=0)f3(f);
	}
	for(int i=1;i<=n;i++)cout<<sj[i]%998244353<<' ';
	return 0;
}
