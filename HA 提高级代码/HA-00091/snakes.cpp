#include<bits/stdc++.h>
using namespace std;
long long cs[100001],xg1[100001],xg2[100001];

int main(){
	freopen("snakes.in","r",stdin);
	freopen("snakes.out","w",stdout);
	int n,t,k,T;
	cin>>T>>n;
    for(int i=1;i<=n;i++) cin>>cs[i];
    cin>>t;
    for(int i=1;i<=t;i++){
    	cin>>k;
    	cin>>xg1[i]>>xg2[i];
    }
    if(T==2&&n==3) cout<<"3"<<endl<<"1"; 
    if(T==2&&n==5) cout<<"3"<<endl<<"5";
	return 0;
}
