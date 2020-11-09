#include<bits/stdc++.h>
using namespace std;
int q,n,m;
int a[100000];
int ans=0;
int qq;
int top;
void kp(int l,int r){
	int i=l,j=r;
	int mid=a[(l+r)/2];
	while(i<=j){
		while(a[i]<mid)i++;
		while(a[j]>mid)j--;
		if(i<=j){
			swap(a[i],a[j]);
			i++,j--;
		}
	}
	if(i<r)kp(i,r);
	if(l<j)kp(l,j);
}
int main(){
	freopen("snakes.in","r",stdin);
	freopen("snakes.out","w",stdout);
cin>>q;
for(int i=1;i<=q;i++){
	scanf("%d",&n);
	for(int j=1;j<=n;j++){
		scanf("%d",&a[j]);
	}
	kp(1,n);
	qq=1;
	top=a[n];
	while(top-a[qq]>a[n-1]){ans++;top-=a[qq];qq++;}
	cout<<ans<<endl;
	ans=0;
}
}
