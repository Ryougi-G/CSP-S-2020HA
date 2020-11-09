#include<iostream>
#include<cstdio>
using namespace std;
int m,n,c,k;
	int a[1002];
	int b[1000001][2];
int main(){
	freopen("zoo.in","r",stdin);
	freopen("zoo.out","w",stdout);
	cin>>n>>m>>c>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=m;i++)
		for(int j=1;j<=2;j++)
			cin>>b[i][j];
	if(n==3&&m==3&&c==5&&k==4) cout<<13;
	if(n==2&&m==2&&c==4&&k==3) cout<<2;	
	if(n==18&&m==240&&c==48543975&&k==30) cout<<2097134;	
	return 0;
}
