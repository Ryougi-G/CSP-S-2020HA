#include<iostream>
#include<cstdio>
#include<vector>
#include<set>
using namespace std;
const int N=1e6+10;
long long sum,siz;
vector<int> mp[N];
set<int> used;

int main(){
	freopen("zoo.in","r",stdin);
	freopen("zoo.out","w",stdout);
	ios::sync_with_stdio(false);
	int m,n,c,k,u,v;
	long long tmp;
	cin>>n>>m>>c>>k;
	for(int i=1;i<=n;++i){
		cin>>tmp;
		sum|=tmp;
	}
	for(int i=1;i<=m;++i){
		cin>>u>>v;
		mp[u].push_back(v);
	}
	for(int i=0;i<k;++i){
		if(sum&1){
			for(int j=0;j<mp[i].size();++j)
				used.insert(mp[i][j]);
		}
		sum>>=1;
	}
	for(int i=0;i<k;++i){
		siz++;
		int flag=1;
		for(int j=0;j<mp[i].size();++j)
	      if(used.find(mp[i][j])==used.end()){
	      	siz--;
	      	flag=0;
	      	break;
	      }
	}
	siz=1<<siz;
	cout<<siz-n<<endl;
}

