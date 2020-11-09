#include<bits/stdc++.h>
using namespace std;
const int N=100009;
const long long mod=998244353;
struct node1{
	int p,v,id;
	node1(){
	}
	node1(int pp,int vv,int idd){
		p=pp;
		v=vv;
		id=idd;
	}
};
struct node2{
	int v,id;
	node2(){
	}
	node2(int vv,int idd){
		v=vv;
		id=idd;
	}
};
struct node3{
	vector<int> ids;
	int id;
	node3(){
	}
	node3(vector<int> idss,int idd){
		ids=idss;
		id=idd;
	}
};
vector<node1> v1;
vector<node2> v2;
vector<node3> v3;

long long n,m,oid;
long long a[N];
int main(){
	freopen("call.in","r",stdin);
	freopen("call.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	cin>>m;
	oid=1;
	for(int j=1;j<=m;j++){
		int op;
		cin>>op;
		if(op==1){
			int p,v;
			cin>>p>>v;
			v1.push_back(node1(p,v,oid));
			oid++;
		}else if(op==2){
			int v;
			cin>>v;
			v2.push_back(node2(v,oid));
			oid++;
		}
		else if(op==3){
			int c;
			cin>>c;
			vector<int> ls;
			for(int i=0;i<c;i++){
				int j;
				cin>>j;
				ls.push_back(j);
			}
			v3.push_back(node3(ls,oid++));
		}
	}
	int q;
	cin>>q;
	int f;
	for(int j=1;j<=q;j++){
		cin>>f;
		int r=0;
		for(int i=0;i<v1.size()&&r==0;i++){
			if(v1[i].id==f){
				r=1;
				a[v1[i].p]+=v1[i].v%mod;
			}
		}
		for(int i=0;i<v2.size()&&r==0;i++){
			if(v2[i].id==f){
				r=1;
				for(int i=1;i<=n;i++)a[i]=a[i]*v2[i].v%mod;
			}
		}
	
	}
	for(int i=1;i<=n;i++)cout<<a[i]<<" ";
}
