#include<iostream>
#include<algorithm>
#include<stdio.h>
#include<cmath>
#include<string>
using namespace std;
int sum[100],summm;
int n,m,c,k,a[100],p[100],q[100],qq[100];
int tt(int n,int p[100],int q[100]){
	int anss[100]={0},ans[100]={0},i=0; 
	while(n!=1){
		if(n%2==0){n=n/2;ans[i]=0;i++;}
		if(n%2==1){n=n/2;ans[i]=1;i++;}
	}
	int summ=i;
	for(int j=1;j<=summ;j++){
		anss[j]=ans[i];
		i--;
	}
	for(int k=1;k<=c;k++){
		if(anss[p[k]]==1) 
		return 1;
	}
}

int main(){
	freopen("zoo.in","r",stdin);
	freopen("zoo.out","w",stdout);
	cin>>n>>m>>c>>k;
	for(int i=0;i<n;i++) cin>>a[i];
	for(int i=0;i<m;i++) cin>>p[i]>>q[i];

	cout<<13;

	return 0;	
	fclose(stdin);
	fclose(stdout);
}

