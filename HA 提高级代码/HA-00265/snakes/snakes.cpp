#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
struct sn{
	int id,v;
	bool operator <(sn b)const{
		if(v==b.v)return id<b.id;
		return v<b.v;
	}
}a[101];
int main(){
	freopen("snakes.in","r",stdin);
	freopen("snakes.out","w",stdout);
	int t,n,x,y;
	cin>>t; 
	cin>>n;
	for(int i=1;i<=n;++i)
		cin>>a[i].v;
	sort(a+1,a+n+1);
	int fl=1;
	while(a[fl]<a[n]){
		fl++;
		a[n].v-=a[fl].v;
	}
	cout<<n-fl+1<<endl;
	while(--t){
		cin>>n;
		for(int i=1;i<=n;++i)
			cin>>x>>y,a[x].v=y;
		sort(a+1,a+n+1);
		int fl=1;
		while(a[fl]<a[n]){
			fl++;
			a[n].v-=a[fl].v;
		}
		cout<<n-fl+1<<endl;
	}
}
