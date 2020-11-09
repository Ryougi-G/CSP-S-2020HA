#include<iostream>
#include<cstdio>
#include<iomanip>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;
int a[101000];	int n;
vector<int>c[101000];
void suan(int s){
	for(int i=1;i<=n;i++){
			a[i]=a[i]%998244353;
		}
	if(c[s][0]==1){
		a[c[s][1]]=a[c[s][1]]+c[s][2];
	}
	if(c[s][0]==2){
		for(int i=1;i<=n;i++){
			a[i]=a[i]*c[s][1];
		}
	}
	if(c[s][0]==3){
		int xy=c[s][1];
		for(int i=1;i<=xy;i++){
			suan(c[s][i+1]);
		}
	}
}
int main(){
	freopen("call.in","r",stdin);
	freopen("call.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int m;
	cin>>m;
	for(int i=1;i<=m;i++){
		int shu;
		cin>>shu;
		if(shu==1){
			c[i].push_back(shu);
			int xxx,yyy;
			cin>>xxx>>yyy;
			c[i].push_back(xxx);
			c[i].push_back(yyy);
		}
		if(shu==2){
			c[i].push_back(shu);
			int xxx;
			cin>>xxx;
			c[i].push_back(xxx);
		}
		if(shu==3){
			c[i].push_back(shu);
			int xxx;
			cin>>xxx;
			c[i].push_back(xxx);
			for(int j=1;j<=xxx;j++){
				int aaa;
				cin>>aaa;
				c[i].push_back(aaa);
			}
		}
	}
	int q;
	cin>>q;
	for(int i=1;i<=q;i++){
		int bu;
		cin>>bu;
		suan(bu);
	}
	for(int i=1;i<=n;i++){
		cout<<a[i]<<" ";
	}
}
