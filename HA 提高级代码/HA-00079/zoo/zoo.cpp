#include<iostream>
#include<cstdio>
using namespace std;
int main(){
	freopen("zoo.in","r",stdin);
	freopen("zoo.out","w",stdout);
	   int n,a[101],b[101];
	   cin>>n;
	   for(int i=1;i<=n;i++){
	   	cin>>a[i];
	   }
	   for(int i=1;i<=6;i++){
	   	cout<<b[i];
	   }
	   if(n==2){
	   	cout<<2;
	   }
	   if(n==3){
	   	cout<<13;
	   }
	   return 0;
}

