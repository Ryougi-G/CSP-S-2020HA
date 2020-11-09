#include<bits/stdc++.h>
using namespace std;
struct node1{
	int shu,addd;
	node1(int x,int y){
		shu=x;
		addd=y;
	}
};
vector<node1>add;
int cx=1;
vector<int>tiao;
int shu[200001],a,b,c,d,m,n;
int main(){
	freopen("call.in","r",stdin);
	freopen("call.out","w",stdout);
cin>>a;
for(int i=1;i<=a;i++) cin>>shu[i];
cin>>b;
for(int i=1;i<=b;i++){
	int my;
	cin>>my;
	if(my==1){
		int o,k;
		cin>>o>>k;
		add.push_back(node1(o,k));
	}
	if(my==2){
		int o;
		cin>>o;
		cx*=o;
	}
	if(my==3){
		int o;
		cin>>o;
		for(int j=1;j<=o;j++){
			int k;
			cin>>k;
			tiao.push_back(k);
		}
	}
}
cin>>c;
for(int i=1;i<=c;i++){
	int o;
	cin>>o;
	if(o==1){
		for(int j=0;j<add.size();j++){
			shu[add[j].shu]+=add[j].addd;
		}
	}
	if(o==2){
		for(int j=1;j<=a;j++){
			shu[j]*=cx;
		}
	}
	if(o==3){
		for(int k=0;k<tiao.size();k++){
			int pp=tiao[k];
			if(pp==1){
		for(int j=0;j<add.size();j++){
			shu[add[j].shu]+=add[j].addd;
		}
	}
	if(pp==2){
		for(int j=1;j<=a;j++){
			shu[j]*=cx;
		}
	}
		}
	}
}
for(int i=1;i<=a;i++){
	cout<<shu[i]<<" ";
}
return 0;
}
