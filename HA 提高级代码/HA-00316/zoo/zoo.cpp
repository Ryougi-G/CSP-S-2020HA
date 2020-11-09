#include<bits/stdc++.h>
using namespace std;
int n,m,c,k,a[1000],p[1000],q[1000];
bool ifp[1000]={false};
int ifhave(int x[],int y,int cnt){
	for(int i=0;i<=cnt;i++){
		if(x[i]==y){
			return i;
		}
	}
	return -1;
}
bool ifhavep(int x){
	int cnt=0;
	while(x>0){
		if(!((x%2&&!ifp[cnt])||!(x%2))){
			return false;
		}
		cnt++;
		x/=2;
	}
	return true;
}
void p2n(int x){
	int cnt=0;
	while(x>0){ 
		if(x%2&&ifhave(p,cnt,m)){
			ifp[cnt]=true;
		}
		x/=2;
		cnt++;
	}
}
int main(){
	freopen("zoo.in","r",stdin);
	freopen("zoo.out","w",stdout);
	int cnt=0;
	cin>>n>>m>>c>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=m;i++){
		cin>>p[i]>>q[i];
	}
	for(int i=1;i<=n;i++){
		p2n(a[i]);
	}
	for(int i=0;i<pow(2,k);i++){
		if(ifhavep(i)&&!ifhave(a,i,n)){
			cnt++;
			cout<<i<<" ";
		}
	}
	cout<<endl;
	for(int i=1;i<=m;i++){
		cout<<ifp[i]<<" ";
	}
	cout<<endl<<cnt;
	return 0;
}
