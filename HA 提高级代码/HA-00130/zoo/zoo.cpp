#include<bits/stdc++.h>
using namespace std;
long long n,m,c,k;
long long ans=1,anm[1000010];
bool dt[65],wz[65];//true表示这个位置可以有饲料 
long long rep[1000010],req[1000010];
bool mem[65];
void solve(long long n){
	int temp=1,l=0;
	while(temp<=n && l<k){
		if(n%temp==0){
			dt[l]=true;
		}
		temp*=2;l++;
	}
}
bool end(long long n){
	int temp=1,l=0;
	while(l<k){
		if(temp>n) return true;
		if(wz[l]!=true && n%temp==0){
			return false;
		}
		temp*=2;l++;
	}
	return true;
}
int main(){
	freopen("zoo.in","r",stdin);
	freopen("zoo.out","w",stdout);
	cin>>n>>m>>c>>k;
	for(int i=1; i<=n; i++){
		cin>>anm[i];
		solve(anm[i]);
	}
	for(int i=1; i<=m; i++){
		cin>>rep[i]>>req[i];
	}
	
	for(int i=0; i<k; i++){
		wz[i]=true;
	}
	for(int j=1; j<=m; j++){
		wz[rep[j]]=false;
	}
	
	for(int i=0; i<k; i++){
		if(dt[rep[i]]==true){
			mem[req[i]]=true;
		}
	}
	for(int i=1; i<=m; i++){
		if(mem[req[i]]==true)
			wz[rep[i]]=true;
	}
	
	for(int i=0; i<k; i++){
		if(wz[i]==true){
			ans*=2;
		}
	}
	for(int i=1; i<=n; i++){
		if(end(anm[i])==true){
			ans--;
		}
	}
	cout<<ans<<endl;
}
