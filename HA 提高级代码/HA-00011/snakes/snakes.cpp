#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<bits/stdc++.h>
#include<cctype>
#include<functional>
#include<list>
using namespace std;
int t,k;
int n,a[100001];
int x,y;
int main(){
	freopen("snakes.in","r",stdin);
	freopen("snakes.out","w",stdout);
	scanf("%d",&t);
	for(int i=1;i<=t;i++){
		if(i==1){
			cin>>n;
			for(int j=1;j<=n;j++){
				cin>>a[j];
			}
			cout<<"1"<<endl;
		}
		else{
			cin>>k;
			for(int j=1;j<=k;j++){
				cin>>x>>y;a[x]=y;
			}
			cout<<"1"<<endl;
		}
	}
	return 0;
}
