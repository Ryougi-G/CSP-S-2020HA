#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("snakes.in","r",stdin);
	freopen("snakes.out","w",stdout);
	int T,k,a[5],c1,c2,n;
	cin>>T;
	cin>>n;
	cin>>a[1]>>a[2]>>a[3];
	if(max(a[1],max(a[2],a[3]))*2>=a[1]+a[2]+a[3]){
		cout<<1<<endl;
	}
	else{
		cout<<3<<endl;
	}
	for(int i=2;i<=T;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>c1>>c2;
			a[c1]=c2;
		}
		int maxn=max(a[1],max(a[2],a[3]));
		int sum=a[1]+a[2]+a[3];
		if(maxn*2>sum||(maxn*2==sum&&maxn==a[3])){
			cout<<1<<endl;
		}
		else{
			cout<<3<<endl;
		}
	}
	return 0;
}
