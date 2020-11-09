#include <bits/stdc++.h>
using namespace std;

bool as[1000][1000];
int a[1000]; 
int n,m,c,k;
bool flag[1000];
int shengxia,cnt1,cnt2;

void er(int i){
	for(int j=1;j<=k;j++){
		if(a[i]&1){
			as[i][j]=1;
		}else{
			as[i][j]=0;
		}
	}
}

long long erd(int c){
	if(c==0){
		return 1;
	}
	int anss=2*erd(c-1); 
	return anss;
}

int main(){
	freopen("zoo.in","r",stdin);
	freopen("zoo.out","w",stdout);
	cin>>n>>m>>c>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		er(i);
	}
	for(int i=1;i<=m;i++){
		int p,q;
		cin>>p>>q;
		for(int j=1;j<=n;j++){
			if(as[j][p]){
				flag[q]=1;
				cnt1++;
			}
		}
	}
	for(int i=1;i<=c;i++){
		if(flag[i]){
			shengxia++;
		}
	}
	if(c>k){
		c=k;
	}
	long long ans=erd(c-shengxia)+erd(shengxia)+1;
	cout<<ans;
}

