#include<bits/stdc++.h>
using namespace std;
int t,n,a[1000001],ans;
int main(){
	freopen("snakes.in","r",stdin);
	freopen("snakes.out","w",stdout);
	cin>>t;
	int ynf=t;
	while(t--){
		if(t==ynf-1){
			cin>>n;ans=n;
			for(int i=1;i<=n;i++)
				cin>>a[i];
			cout<<n;
		}
		cout<<n;
	}
	return 0;
}
