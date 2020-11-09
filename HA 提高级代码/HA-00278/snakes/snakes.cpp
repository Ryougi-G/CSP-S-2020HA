#include<bits/stdc++.h>
using namespace std;
int a[1001];
int main()
{
	int i,n,T,k,x,y,b,c,ans,d;
	cin>>T;
	freopen("snakes.in","r",stdin);
	freopen("snakes.out","w",stdout);
	cin>>n;
	for(i=0;i<=n;i++){
		cin>>a[i];
		if(a[i]>a[i-1]){
			a[b]=a[i];
			a[c]=a[i-1];
		}
		else {
		a[b]=a[i-1];
		a[c]=a[i];	
		}
		if(a[b]-a[c]>a[d]);
	}
	for(i=0;i<=T-1;i++){
		cin>>k;	
}
	for(i=0;i<=k;i++){
		cin>>x>>y;
		cout<<ans;
	}
		
	return 0;
}
