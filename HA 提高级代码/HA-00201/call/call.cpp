#include<bits/stdc++.h>
using namespace std;
int n;
int a[100001],f[100001];
int mapp[10001][10001];
void dy(int o1){
	if(mapp[o1][1]==1){
		a[mapp[o1][2]]=(a[mapp[o1][2]]+mapp[o1][3]);
		return;
	}
	else if(mapp[o1][1]==2){
		for(int t=1;t<=n;t++){
			a[t]=(a[t]*mapp[o1][2]);
		}
		return;
	}
	else{
		for(int q=1;q<=mapp[o1][2];q++){
			dy(mapp[o1][q+2]);
		}
	}
}
int main(){
	freopen("call.in","r",stdin);
	freopen("call.out","w",stdout);
	std::ios::sync_with_stdio(false);
	int n,m;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	cin>>m;
	for(int i=1;i<=m;i++){
		cin>>mapp[i][1];
		if(mapp[i][1]==1){
			cin>>mapp[i][2];
			cin>>mapp[i][3];
		}
		if(mapp[i][1]==2){
			cin>>mapp[i][2];
		}
		else{
			cin>>mapp[i][2];
			for(int j=1;j<=mapp[i][2];j++){
				cin>>mapp[i][j+2];
			}
		}
	}
	int q;
	cin>>q;
	for(int i=1;i<=q;i++){
		cin>>f[i];
		if(mapp[f[i]][1]==1){
			a[mapp[f[i]][2]]+=mapp[f[i]][3];
			a[mapp[f[i]][2]]=a[mapp[f[i]][2]];
		}
		else if(mapp[f[i]][1]==2){
			for(int j=1;j<=n;i++){
				a[j]=a[j]*mapp[f[i]][2];
			}
		}
		else{
			for(int j=1;j<=mapp[f[i]][2];j++){
				dy(mapp[f[i]][j+2]);
			}
		}
	}
	for(int i=1;i<=n;i++){
		cout<<a[i]<<' '	;
		}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

