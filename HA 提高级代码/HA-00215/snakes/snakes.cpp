#include<bits/stdc++.h>
using namespace std;
int t,n,a[100001];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("snakes.in","r",stdin);
	freopen("snakes.out","w",stdout);	
	cin>>t;
	cin>>n;
	int j;
	for(j=1;j<=n;j++){
			cin>>a[j];
		}
	j--;
	bool flag=1;
	while(flag){
		int b=2,c=0;
		while(a[b]<a[j]-a[1]){
			c+=a[b];
			b++;
		}
		if(a[j]-a[1]>a[j-1]-c){
			a[1]=a[j]-a[1];
			j--;
			sort(a+1,a+j,cmp);
		}
		else flag=0;
	}
	cout<<j<<endl;
	for(int i=1;i<t;i++){
		int c;
		cin>>c;
		for(int k=1;k<=c;k++){
			int d1,d2;
			cin>>d1>>d2;
			a[d1]=d2;
		}
		j=n;
		bool flag=1;
	while(flag){
		int b=2,c=0;
		while(a[b]<a[j]-a[1]){
			c+=a[b];
			b++;
		}
		if(a[j]-a[1]>a[j-1]-c){
			a[1]=a[j]-a[1];
			j--;
			sort(a,a+j,cmp);
		}
		else flag=0;
	}
	cout<<j<<endl;
	}
	return 0;
}
