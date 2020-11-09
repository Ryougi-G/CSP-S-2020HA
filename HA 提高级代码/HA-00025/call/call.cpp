#include<iostream>
#include<cstdio>
#define N 10010
long long s[N];
long long t[N],p[N],v[N];
long long q[N],g[N];
int n;
using namespace std;
void jia(long long a,long long b){
	s[a]+=b;
}
void pow_(long long a){
	for(int i=1;i<=n;i++){
		s[i]*=a;
	}
}
void dy(long long a,long long b[N]){
	int k=1;
	for(int i=1;i<=a;i++){
		g[k]=b[i];
		
		if(b[i]==1){
			jia(p[i],v[i]);
		}else{
			pow_(v[i]);
		}
		
	}
}
int main(){
	freopen("call.in","r",stdin);
	freopen("call.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>s[i];
	}
	int m;
	cin>>m;
	for(int i=1;i<=m;i++){
		cin>>t[i];
		if(t[i]==1){
			cin>>p[i]>>v[i];
		}else if(t[i]==2){
			cin>>v[i];
		}else{
			cin>>q[i];
			for(int j=1;j<=q[i];j++){
				cin>>g[j];
			}
		}
	}
	int o,f;
	cin>>o;
	for(int i=1;i<=o;i++){
		cin>>f;
		if(t[f]==1){
			jia(p[f],v[f]);
		}else if(t[f]==2){
			pow_(v[f]);
		}else{
			dy(q[f],g);
		}
	}
	for(int i=1;i<=n;i++){
		cout<<s[i]%998244353<<" ";
	}
	fclose(stdin);
	fclose(stdout);
}

