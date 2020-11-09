#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
ll n,m,c,k,animal,nobuy,nowei[65];
map<ll,ll>nengmai,bumai;
ll _pow2[65];
int main(){
	freopen("zoo.in","r",stdin);
	freopen("zoo.out","w",stdout);
	ios::sync_with_stdio(false);
	_pow2[0]=1;
	for(int i=1;i<=64;i++) _pow2[i]=_pow2[i-1]*2;
	cin>>n>>m>>c>>k;
	for(int i=0;i<n;i++){
		ll mid;
		cin>>mid;
		animal=animal|mid;
	}
	for(ll i=1;i<=m;i++){
		ll p,q;
		cin>>p>>q;
		if(animal&_pow2[p]){
			nengmai[q]=1;
			if(bumai[q]){
				bumai[q]=0;nowei[p]=0;
				k++;
			}
		}else{
			if((!nengmai[q])&&!(nowei[p])){
				bumai[q]=1;nowei[p]=1;
				k--;
			}
		}
	}
	cout<<_pow2[k]-n<<endl;
	return 0;
}

