#include <bits/stdc++.h>
using namespace std;
int snake[1000010];
int T;
int n;
bool dead[1000010]={0};
bool vis[1000010]={0};
int findm(){
	int pos=0;
	int maxn=-1;
	for(int i=1;i<=n;i++){
		if(snake[i]>maxn&&!dead[i]){
			pos=i;
			maxn=snake[i];
		}
	}
	return pos;
}int findn(){
	int pos=0;
	int minn=9999999999;
	for(int i=1;i<=n;i++){
		if(snake[i]<minn&&!dead[i]){
			pos=i;
			minn=snake[i];
		}
	}
	return pos;
}
int dfs(int pos,int live){
	vis[pos]=1;
	int eatp=findn();
	if(vis[eatp]&&eatp!=pos){
		return -1;
	}
	int t=snake[pos];
	dead[eatp]=true;
	snake[pos]=snake[pos]-snake[eatp];
	int res=dfs(findm(),live-1);
	dead[eatp]=false;
	snake[pos]=t;
	vis[pos]=0;
	if(res==-1){
		return live;
	}else{
		return res;
	}
}
int main(){
	freopen("snakes.in","r",stdin);
	freopen("snakes.out","w",stdout);
	cin>>T;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>snake[i];
	}
	int p=findm();
	int res=dfs(p,n);
	cout<<res<<endl;
	T--;
	while(T--){
		memset(dead,0,sizeof(dead));
		memset(vis,0,sizeof(vis));
		int k;
		cin>>k;
		for(int i=1;i<=k;i++){
			int x,y;
			cin>>x>>y;
			snake[x]=y;
		}
		int tp=findm();
		int res=dfs(tp,n);
		cout<<res<<endl;
	}
	return 0;
}
