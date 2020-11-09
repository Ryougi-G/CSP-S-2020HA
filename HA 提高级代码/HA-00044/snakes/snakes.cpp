#include<bits/stdc++.h>
using namespace std;
int t;
long long ll[5],n,lll[5];
int main(){
	freopen("snakes.in","r",stdin);
	freopen("snakes.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>n;
	if(i==1){
		for(int j=1;j<=n;j++){
			cin>>ll[j];
		}
	}else{
		int k;
		for(int j=1;j<=2*n;j++){
		if(j%2==1)	cin>>k;
		else cin>>ll[k];
		}
	}
	for(int j=1;j<=3;j++) lll[j]=ll[j];
		sort(lll+1,lll+n+1);
		if(lll[3]-lll[1]<lll[2]) cout<<3<<endl;
		else cout<<1<<endl;
	}
	return 0;
}
