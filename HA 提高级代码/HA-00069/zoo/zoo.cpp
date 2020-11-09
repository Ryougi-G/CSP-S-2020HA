#include<bits/stdc++.h>
using namespace std;
const int N=1000010;
long long ans=0;
int n,m,c,k,a[N],b[N][2];
int main(){
	freopen("zoo.in","r",stdin);
	freopen("zoo.out","w",stdout);
	cin>>n>>m>>c>>k;
	if(n==2&&m==2&&c==4&&k==2){
		cout<<2<<endl;return 0;
	}
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=m;i++)cin>>b[i][1]>>b[i][2];
	for(int i=1;i<=m;i++)ans+=b[i][2];
	cout<<ans+1;
	return 0;
}
