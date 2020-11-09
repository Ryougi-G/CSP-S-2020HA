/*
#include <bits/stdc++.h>
#define ll long long
using namespace std;
int n,m,c,k;
bool b[65]={0};
map<ll,bool> has;
bool hn[65][2]={0};//哪一位上是否需要饲料且是否该位已有已知的动物存在 
ll lpow(ll x,ll y){
	ll res=1;
	for(int i=1;i<=y;i++){
		res*=x;
	}
	return res;
}
int main(){
	freopen("zoo.in","r",stdin);
	freopen("zoo.out","w",stdout);
	cin>>n>>m>>c>>k;
	for(int i=1;i<=n;i++){
		ll t;
		cin>>t;
		has[t]=true;
		int pos=0;
		while(t>0){
			if(t&1==1){
				b[pos]=1;
				hn[pos][1]=1;
			}else{
				pos++;
			}
			t>>=1;
		}
	}
	for(int i=1;i<=m;i++){
		int p;
		ll q;
		cin>>p>>q;
		hn[p][0]=1;
	}
	ll tar=lpow(2,k);
	int ans=0;
	for(ll i=0;i<=tar-1;i++){
		if(has[i]){
			continue;
		}
		ll t=i;
		int pos=0;
		bool flag=true;
		while(t>0){
			if(t&1==1&&hn[pos][0]==true&&hn[pos][1]==false){
				flag=false;
				break;
			}else{
				pos++;
			}
			t>>=1;
		}
		if(flag){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;
int n,m,c,k;
bool b[65]={0};
map<ll,bool> has;
bool hn[65][2]={0};//哪一位上是否需要饲料且是否该位已有已知的动物存在 
ll lpow(ll x,ll y){
	ll res=1;
	for(int i=1;i<=y;i++){
		res*=x;
	}
	return res;
}
int main(){
	freopen("zoo.in","r",stdin);
	freopen("zoo.out","w",stdout);
	cin>>n>>m>>c>>k;
	for(int i=1;i<=n;i++){
		ll t;
		cin>>t;
		has[t]=true;
		int pos=0;
		while(t>0){
			if(t&1==1){
				b[pos]=1;
				hn[pos][1]=1;
			}else{
				pos++;
			}
			t>>=1;
		}
	}
	for(int i=1;i<=m;i++){
		int p;
		ll q;
		cin>>p>>q;
		hn[p][0]=1;
	}
	int ans=0;
	for(int i=0;i<k;i++){
		if(hn[i][0]==0||(hn[i][0]==1&&hn[i][1]==1)){
			ans+=1;
		}
	}
	ll res=lpow(2,ans);
	ll nex=lpow(2,k);
	int pos=0;
	bool flag=true;
	while(nex>0){
		if(nex&1==1&&hn[pos][0]==1&&hn[pos][0]==0){
			flag=false;
			break;
		}
		pos++;
		nex>>=1;
	}
	if(!flag){
		res--;
	}else{
	}
	res-=n;
	cout<<res;
	return 0;
}
