#include<iostream>
#include<cstdio>
using namespace std;
int main(){
	freopen("snakes.in","r",stdin);
	freopen("snakes.out","w",stdout);
	int t,n;cin>>t>>n;
	int a[11];
	int b[3][11];
	for(int i=1;i<=t;i++){
		for(int j=1;j<=n;j++){
			if(i=1){
				cin>>b[1][j];
			}else{
				cin>>b[i][j];
			}
		}
	}
	for(int i=1;i<=t;i++){
		for(int j=1;j<=n;j++){
			if(b[3][j]>=b[1][j]+b[2][j]){
				cout<<3<<endl;			
			}else{
				cout<<1<<endl;
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
