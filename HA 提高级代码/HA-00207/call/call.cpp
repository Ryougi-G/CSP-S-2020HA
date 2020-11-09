#include<iostream>
#include<cstdio>
using namespace std;
int n,m,q;
int a[1000001];
struct func{
	int t;
	int p,v,c,k[1001];
}b[100001];

void function_1(int t){
	if(b[t].t==1){
		a[b[t].p]+=b[t].v;
		a[b[t].p]%=998244353;
	}else if(b[t].t==2){
		for(int j=1;j<=n;j++){
			a[j]*=b[t].v;
			a[j]%=998244353;
		}
	}else{
		for(int j=1;j<=b[t].c;j++){
			function_1(b[t].k[j]);
		}
	}
	return;
}
int main(){
	freopen("call.in","r",stdin);
	freopen("call.out","w",stdout);
	cin >> n ;
	for(int i=1;i<=n;i++){
		cin >> a[i] ;
		a[i]%=998244353;
	}
	cin >> m ;
	for(int i=1;i<=m;i++){
		cin >> b[i].t ;
		if(b[i].t==1){
			cin >> b[i].p >> b[i].v ;
		}else if(b[i].t==2){
			cin >> b[i].v ;
		}else{
			cin >> b[i].c ;
			for(int j=1;j<=b[i].c;j++){
				cin >> b[i].k[j] ;
			}
		}
	}
	int t;
	cin >> q ;
	for(int i=1;i<=q;i++){
		cin >> t ;
		function_1(t);
	}
	for(int i=1;i<=n;i++){
		cout << a[i]%998244353 << " " ;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

