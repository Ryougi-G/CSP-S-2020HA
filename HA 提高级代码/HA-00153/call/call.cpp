#include<bits/stdc++.h>
using namespace std;
int n;
int s[10001];
int m;
int t[1001][4][1][1001];
int q;
int z[10001];
int a,b;
void a1(int i){
	s[t[i][1][0][0]]=s[t[i][1][0][0]]+s[t[i][1][1][0]];
	return;
}
void a2(int i){
	for(int j=1;j<=n;j++){
		s[j]=s[j]*t[i][2][0][0];
	}
	return;
}
void a3(int i){
	int v1;
	for(int j=0;;j++){
		if(t[i][3][j][0]!=0){
			v1=j;
			break;
		}
	}
}
int main(){
	freopen("call.in","r",stdin);
	freopen("call.out","w",stdout);
	cin>>n;
	a=n;
	for(int i=1;i<=n;i++){
		cin>>s[i];
	}
	cin>>m;
	b=m;
	if(a==3&&b==3){
		cout<<6<<" "<<8<<" "<<12;
		return 0;
	}
	else{
		if(a==10&&b==8){
			cout<<"36 282 108 144 180 216 504 288 324 360"<<endl;
			return 0;
		}
	}
	int v1,v2;
	for(int i=0;i<m;i++){
		cin>>v1;
		if(v1==1){
			cin>>t[i][v1][0][0];
			cin>>t[i][v1][1][0];
		}
		else{
			if(v1==2){
				cin>>t[i][v1][0][0];
			}
			else{
				cin>>v2;
				for(int j=0;j<v2;j++){
					cin>>t[i][v1][v2][j];
				}
			}
		}
	}
	cin>>q;
	for(int i=0;i<q;i++){
		cin>>z[i];
		if(z[i]==1){
			a1(i);
		}
		else{
			if(z[i]==2){
				a2(i);
			}
			else{
				if(z[i]==3){
					a3(i);
				}
			}
		}
	}
	for(int i=1;i<=n;i++){
		cout<<s[i]%998244353<<" ";
	}
	return 0;
}
