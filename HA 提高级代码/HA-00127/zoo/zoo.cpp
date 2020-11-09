#include <bits/stdc++.h>
using namespace std;
long long a[1000005];
int p[1000005];
bool ok[70]={0},vis[70]={0};
int main(){
	freopen ("zoo.in","r",stdin);
	freopen ("zoo.out","w",stdout);
	int n,m,c,k;
	cin>>n>>m>>c>>k;
	for (int i=1;i<=n;i++){
		cin>>a[i];
	}
	for (int i=1;i<=m;i++){
		int q;
		cin>>p[i]>>q;
		vis[p[i]]=1;
	}
	for (int i=1;i<=m;i++){
		for (int j=1;j<=n;j++){
			if ((a[j]>>p[i])%2==1)vis[p[i]]=0;
		}
	}
//	for (int i=0;i<k;i++){
//		cout<<vis[i]<<" ";
//	}
//	return 0;
	unsigned long long ans=1;
	for (int i=0;i<k;i++){
		if (vis[i]==0){
			ans+=pow(2,i);
		}
		for (int j=1;j<=n;j++){
			if ((a[j]>>i)%2==1&&ok[j]==0){
				ans--;ok[j]=1;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}
