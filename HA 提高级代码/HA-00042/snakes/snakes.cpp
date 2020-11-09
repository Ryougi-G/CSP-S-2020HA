#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main(){
	freopen("snakes.in","r",stdin);
	freopen("snakes.out","w",stdout);
	int t,n,a[2000],max=0,b=0;
	cin>>t>>n;
	n=3;
	for(int j=1;j<=n;j++){
		cin>>a[2000];
	}
	for(int i=1;i<=n;i++){
		if(a[i]>max){
			max=a[i];
			b=i;
		}
	}
	for(int i=1;i<=n;i++){
		max-=a[i];
	}
	if(max>=0){
		cout<<a[b]<<endl<<1;;
	}
	fclose(stdin);
	fclose(stdout);
}
