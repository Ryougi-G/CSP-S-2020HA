#include<bits/stdc++.h>
using namespace std;
const int N=100009;
struct node{
	int p,q;
}e[1009];
vector<int> ese;
int p[25];
int a[N],fa[N];
int n,m,c,k;
vector<int> gp[55];
void init(){
	for(int i=0;i<N;i++){
		fa[i]=i;
	}
}
int get(int x){
	if(fa[x]==x){
		return x;
	}
	return fa[x]=get(fa[x]);
}
void merge(int x,int y){
	x=get(x);
	y=get(y);
	if(x!=y){
		fa[x]=y;
	}
}
int main(){
	freopen("zoo.in","r",stdin);
	freopen("zoo.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>n>>m>>c>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=m;i++){
		cin>>e[i].p>>e[i].q;
	}
	for(int i=1;i<=m;i++){
		int wei=e[i].p;
		int id=e[i].q;
		for(int i=0;i<(1<<k);i++){
			if((i>>wei)&1==1){
				gp[id].push_back(i);
				if(binary_search(a,a+n,i))ese.push_back(id);
			}
		}
	}
	for(int i=1;i<=50;i++){
		for(int j=1;j<gp[i].size();j++){
			merge(gp[i][j],gp[i][j-1]);
		}
	}
	/*
	for(int i=1;i<=50;i++){
		cout<<i<<"---";
		for(int j=0;j<gp[i].size();j++){
			cout<<gp[i][j]<<" ";
		}
		cout<<endl;
	}
	*/
	for(int i=2;i<=n;i++){
		merge(a[i],a[i-1]);
	}
	int cnt=0;
	for(int i=0;i<(1<<k);i++){
		if(get(i)==get(a[1]))cnt++;
	}
	cnt-=n;
	cout<<cnt<<endl;
	return 0;
}
