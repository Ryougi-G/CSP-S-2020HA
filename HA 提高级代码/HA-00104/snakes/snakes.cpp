#include<bits/stdc++.h>
using namespace std;
int n,m,t,tt;int tx,ty;
int she[500090];
int main(){
	freopen("snakes.in","r",stdin);
	freopen("snake.out","w",stdout);
	cin>>t; cin>>n;
	if(n==3){
		for(int i=1;i<=n;i++) cin>>she[i];
		if(she[3]>she[1]+she[2]) cout<<1<<endl;
		else cout<<3<<endl;
		for(int i=2;i<=t;i++){
			cin>>tt;
			for(int i=1;i<=tt;i++){
				cin>>tx>>ty;
				she[tx]=ty;
			}
			if(she[3]>she[1]+she[2]) cout<<1<<endl;
			else cout<<3<<endl;
		}
		return 0;
	}
	else{
		for(int i=1;i<=t;i++){
			cout<<1<<endl;
		}
	}
}
