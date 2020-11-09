#include <bits/stdc++.h>
#define ll long long
#define maxn 100000
#define maxn2 1000
using namespace std;
ll data[maxn];
struct T{
	int Type;
	int P;
	int V;
	int C;
}T[maxn];
int g[maxn2][maxn2];
int ex[maxn];
int nums[maxn];
void calc(int i){
	if(T[ex[i]].Type==1)
		    data[T[ex[i]].P]+=T[ex[i]].V;
    else if(T[ex[i]].Type==2)
		    for(int j=1;j<=sizeof(data);j++)
		        data[j]*=T[ex[i]].V;
	else{
		for(int j=1;j<=1;j++) 
	        calc(g[T[j].C][j]);
	}
	
}

int main(){
	freopen("call.in","r",stdin);
	freopen("call.out","w",stdout);
    ios::sync_with_stdio(false);
	int n,m,tmp,Q;
	cin>>n;
	for(int i=1;i<=n;i++) cin>>data[i];
	cin>>m;
	for(int i=1;i<=m;i++){
		cin>>tmp;
		int num=1;
	    if(tmp==1){
	    	T[i].Type=1;
	    	cin>>T[i].P>>T[i].V;
	    }else if(tmp==2){
	    	T[i].Type=2;
	        cin>>T[i].V;
	    }else{
	    	T[i].Type=3;
	        cin>>T[i].C;
	        for(int j=1;j<=T[i].C;j++) 
				cin>>g[T[j].C][j];
	    }
	} 
	cin>>Q;
	for(int i=1;i<=Q;i++) cin>>ex[i];
	//Êä³öÍê³É
	for(int i=1;i<=Q;i++){
		calc(i);
	}
	for(int i=1;i<=n;i++) cout<<data[i]<<" ";
	puts("");
	return 0;
}
