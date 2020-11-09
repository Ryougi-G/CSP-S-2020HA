#include<bits/stdc++.h>
using namespace std;
int n,t,k,a[5],x[5],y[5],b[5];
int main(){
	freopen("snake.in","r",stdin);
	freopen("snake.out","w",stdout);
	cin>>t;
	cin>>n;
	fpr(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=a[i];
	}
	for(int i=2;i<=t;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>x[j]>>y[j];
		}
	}
	for(int i=1;i<=t;i++){
		sort(b+1,b+1+3);
		if(b[3]-b[1]>b[2]){
			cout<<"1";
		}
		else if(b[3]-b[1]<=b[2]){
			cout<<"3";
		}
	    for(int j=1;j<=n;j++){
	    	b[j]=a[j];
	    }
		for(int i=1;i<=k;i++){
			b[x[i]]=y[i];
		}
	}
	return 0;
}
