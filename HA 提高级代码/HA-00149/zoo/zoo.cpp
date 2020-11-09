#include<iostream>
#include<cstdio>
#include<iomanip>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;
int n,m,c,k;
int data[31][30]={};
int a[31];
void zhuan(int i){
	int q=1;
	for(int j=1;j<k;j++){
		q=q*2;
	}
	cout<<q;
	for(int j=k-1;j>=0;j--){
		if(a[i]>=q){
			a[i]=a[i]-q;
			data[i][j]=1;
		}
		q=q/2;
	}
}
int main(){
//	freopen("julian.in","r",stdin);
//	freopen("julian.out","w",stdout);
//	cin>>n>>m>>c>>k;
//	for(int i=1;i<=n;i++){
//		cin>>a[i];
//	}
	cin>>a[1]>>k;
	zhuan(1);
	for(int i=0;i<k;i++){
		cout<<data[1][i];
	}
}
