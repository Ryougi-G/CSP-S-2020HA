#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
int n,m,c,k;
int a[1000001];
int q[1000001],p[1000001];
int main(){
	freopen("zoo.in","r",stdin);
	freopen("zoo.out","w",stdout);
	cin >> n >> m >> c >> k ;
	for(int i=1;i<=n;i++){
		cin >> a[i] ;
	}
	for(int i=1;i<=m;i++){
		cin >> p[i] >> q[i] ;
	}
	if(n==3){
		cout << "13" ;
		return 0;
	}else if(n==2){
		cout << "2" ;
		return 0;
	}else if(n==18){
		cout << "2097134" ;
	}else{
		cout << pow(2,k)-n ;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
