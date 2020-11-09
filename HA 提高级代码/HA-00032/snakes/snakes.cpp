#include<bits/stdc++.h>
using namespace std;
struct snakes{
	long long hp;
	bool dead;
}snake[1000005];
int n,t,k,x;
int alive;
int die=0;
long long y;
//bool cmp(snakes a,snakes b){
//	if()
//}
int findweak(){
	int t=1;
	while(snake[t].dead==true){
		t++;
	}
	return t;
}
void Process(int k){
	while(findweak()<k){
		if((snake[k].hp>=snake[findweak()].hp+snake[k-1].hp)){
			snake[k].hp-=snake[findweak()].hp+snake[k-1].hp;
			snake[findweak()].dead=true;
			//cout<<findweak()<<"died   ";
			die++;
		}
		else{
			break;
		}
	}
}
int main(){
	freopen("snakes.in","r",stdin);
	freopen("snakes.out","w",stdout);
	cin>>t;
	cin>>n;
	alive=n;
	die=0;
	for(int i=1;i<=n;i++){
		cin>>snake[i].hp;
		snake[i].dead=false;
	}
	for(int kk=n;kk>2;kk--)
	Process(kk);
	cout<<alive-die<<" ";
	for(int i=1;i<t;i++){
		cin>>k;
		for(int j=0;j<k;j++){
			cin>>x>>y;
			snake[x].hp=y;
		}
		for(int ii=1;ii<=n;ii++){
		snake[ii].dead=false;
		}
		die=0;
		for(int kk=n;kk>2;kk--)
		Process(kk);
		cout<<alive-die<<" ";
	}
	return 0;
}
