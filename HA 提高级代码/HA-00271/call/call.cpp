#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
long long n,n1[100010],m;
int q,f[100010];//调用信息 
struct node{
//	vector<int>m1;
int m1[600];
}e[20010];//函数信息 
void read(){
	cin>>n;
	for(int i=1;i<=n;i++)cin>>n1[i];
	if(n>1000){
		for(int i=1;i<=n;i++){
			cout<<n1[i]<<" ";
		}
	}
	cin>>m;
	for(int i=1;i<=m;i++){
		cin>>e[i].m1[1];
		if(e[i].m1[1]==1)cin>>e[i].m1[2]>>e[i].m1[3];
		if(e[i].m1[1]==2)cin>>e[i].m1[2];
		if(e[i].m1[1]==3){
			cin>>e[i].m1[2];
			for(int j=3;j<=e[i].m1[2]+2;j++){
				cin>>e[i].m1[j];
			}
		}
	}
	cin>>q;
	for(int i=1;i<=q;i++){
		cin>>f[i];
	}
}
void put(){
	for(int i=1;i<=n;i++){
		cout<<n1[i]<<" ";
	}
	cout<<endl;
}
void put1(int i,int x){
	n1[i]+=x;
}
void put2(int x){
	for(int i=1;i<=n;i++)n1[i]*=x;
}
boid put3(int i){
	for(int j=3;j<=e[f[i]].m1[2]+2;j++){
		        int x=e[f[i]].m1[j];
				if(e[x].m1[1]==1)put1(e[x].m1[2],e[x].m1[3]);
				else if(e[x].m1[1]==2)put2(e[x].m1[2]);
				else put3(x);
    }
}
int main(){
	freopen("call.in","r",stdin);
	freopen("call.out","w",stdout);
	read();
	for(int i=1;i<=q;i++){
		if(e[f[i]].m1[1]==1)put1(e[f[i]].m1[2],e[f[i]].m1[3]);
		if(e[f[i]].m1[1]==2)put2(e[f[i]].m1[2]);
		if(e[f[i]].m1[1]==3)put3(i);
		}
	for(int i=1;i<=n;i++){
		if(n1[i]>=998244353)n1[i]%=998244353;
		cout<<n1[i]<<" ";
	}
	return 0;
}
