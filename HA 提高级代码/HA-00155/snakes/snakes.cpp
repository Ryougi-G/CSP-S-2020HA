#include <bits/stdc++.h>
using namespace std;

int sn[1145];
int t,n,m;

int main(){

	freopen("snakes.in","r",stdin);
	freopen("snakes.out","w",stdout);
	
	cin>>t;
	
	bool diyici=1;
	
	while(t--){
		cin>>n;
		if(diyici){
			for(int i=1;i<=n;i++){
			cin>>sn[i];
			}
			diyici=0;
		}else{
			for(int i=1;i<=n;i++){
				int wei;
				cin>>wei;
				cin>>sn[wei];
			}
		}
		int ans=3;
		if(sn[3]-sn[1]>=sn[2]){
			ans--;
			sn[3]=sn[3]-sn[1];
			if(sn[3]>=sn[2]){
				ans--;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}

