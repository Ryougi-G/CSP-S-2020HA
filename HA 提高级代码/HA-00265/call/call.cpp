#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
const int N=1001,mod=998244353;
long long v[N],n;

struct fun{
	int type,val,pos;
	vector<int> funl;
}func[N];

void dfs(fun f){
	if(f.type==1){
		v[f.pos]+=f.val;
		v[f.pos]%=mod;
		return;
	}
	if(f.type==2){
		for(int i=1;i<=n;++i)
			v[i]=v[i]*f.val%mod;
		return;
	}
	for(int i=0;i<f.funl.size();++i)
		dfs(func[f.funl[i]]);
}

int main(){
//	freopen("call.in","r",stdin);
//	freopen("call.out","w",stdout);
	int m;
	cin>>n;
	for(int i=1;i<=n;++i)
		cin>>v[i];
	cin>>m;
	int t,cnt;
	for(int i=1;i<=m;++i){
		cin>>t;
		func[i].type=t;
		if(t==1)
			cin>>func[i].pos>>func[i].val;
		else if(t==2)
			cin>>func[i].val;
		else {
			cin>>cnt;
			for(int i=1;i<=cnt;++i)
				cin>>t,func[i].funl.push_back(t);
		}
	}
	cin>>cnt;
	for(int i=1;i<=cnt;++i){
		cin>>t;
		dfs(func[t]);
	}	
	for(int i=1;i<n;++i)
		cout<<v[i]<<" ";
	cout<<v[n]<<endl;
}
