#include<bits/stdc++.h>
using namespace std;
int t,n;
struct my{
    long long ti;
    int bian;	
}b[231231];
bool diyi(my x,my y){
	if(x.ti==y.ti)return x.bian>y.bian;
	else return x.ti>y.ti;
}
long long a[213123];
int p,q;
int main(){
	freopen("snakes.in","r",stdin);
    freopen("snakes.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>n;
		if(i==1)for(int j=1;j<=n;j++)cin>>a[j];
		else{
			for(int j=1;j<=n;j++){
				cin>>p>>q;
				a[p]=q;
			}
		}
		for(int j=1;j<=n;j++){
			b[j].ti=a[j];
			b[j].bian=j;
		}
		sort(b+1,b+1+n,diyi);
		if(b[1].ti-b[3].ti<b[2].ti)cout<<3<<endl;
		else cout<<1<<endl;
	}
	
	return 0;
}
