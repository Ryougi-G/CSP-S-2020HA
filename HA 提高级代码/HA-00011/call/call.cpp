#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<list>
#include<functional>
#include<cctype>
using namespace std;
int n,m;
int a[1000001],t[100001];
int p[100001],v[100001],c[1000001];
int g[1000001];
int q,f[10000001];
int sum;
int main(){
	freopen("call.in","r",stdin);
	freopen("call.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	cin>>m;
	for(int i=1;i<=m;i++){
		cin>>t[i];//int mmm=0,nnn==0;
		if(t[i]==1){
			cin>>p[i]>>v[i];
		}
		if(t[i]==2){
			cin>>v[i];
//			for(int j=1;j<=n;j++){
//				a[i]*=v;
//			}
		}
		if(t[i]==3){
			cin>>c[i];sum+=c[i];
			for(int j=1;j<=c[i];j++){
				cin>>g[j];
			}
		}
	}
	cin>>q;
	for(int i=1;i<=q;i++){
		cin>>f[i];
		for(int j=1;j<=m;j++){
			if(f[i]==j){
				if(t[j]==1){
					a[p[j]]+=v[p[j]];
				}	
				if(t[j]==2){
					for(int k=1;k<=n;k++){
						a[k]*=v[p[j]];
					}		
				}
			}
		}
	}
	for(int i=1;i<=n;i++){
		cout<<a[i]<<" ";
	}
	return 0;
}
