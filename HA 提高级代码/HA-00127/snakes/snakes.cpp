#include <bits/stdc++.h>
using namespace std;
int a[1000005];
int main(){
	freopen ("snakes.in","r",stdin);
	freopen ("snakes.out","w",stdout);
	int t;
	cin>>t;
	int n;
	cin>>n;
	for (int i=1;i<=n;i++){
		cin>>a[i];
	}
	int l=1,r=n;
	while(l<r){
		if (a[r]-a[l]>=a[r-1]||(a[r]-a[l]<a[r-1]&&a[l+1]<=a[r]-a[l])){
			a[r]-=a[l];
			l++;
			int x=l,y=r;
			while(x<y){
				int md=a[(x+y)/2];
				if (md<a[r]){
					x=(x+y)/2+1;
				}
				else{
					y=(x+y)/2;
				}
			}
			int p=a[r];
			for (int i=y;i<r;i++){
				a[i+1]=a[i];
			}
			a[y]=p;
		}
		else{
			break;
		}
	}
	cout<<r-l+1<<endl;
	int k=0;
	while(cin>>k){
		for (int i=1;i<=k;i++){
			int x,y;cin>>x>>y;
			a[x]=y;
		}
		int l=1,r=n;
		while(l<r){
			if (a[r]-a[l]>=a[r-1]||(a[r]-a[l]<a[r-1]&&a[l+1]<=a[r]-a[l])){
				a[r]-=a[l];
				l++;
				int x=l,y=r;
				while(x<y){
					int md=a[(x+y)/2];
					if (md<a[r]){
						x=(x+y)/2+1;
					}
					else{
						y=(x+y)/2;
					}
				}
				int p=a[r];
				for (int i=y;i<r;i++){
					a[i+1]=a[i];
				}
				a[y]=p;
			}
			else{
				break;
			}
		}
		cout<<r-l+1<<endl;
	}
	return 0;
}
