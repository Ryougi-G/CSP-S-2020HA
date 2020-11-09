#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pp cout<<ppp
using namespace std;
const int maxn=1e5+9;
ull n,m,c,k;
ull ppp=0;
ull p;
int lowbit(ull t){
	return t&(-t);
}
void chuli(int x){
	while(x){
		ull qwq=lowbit(x);
		x-=lowbit(x);
		ppp|=qwq;
		
	}
	return ;
}
int main(){
	freopen("zoo.in","r",stdin);
	freopen("zoo.out","w",stdout);
	cin>>n>>m>>c>>k;
	ull p;
	for(int i=1;i<=n;i++){
		cin>>p;
		chuli(p);
	}
	ull ans=1;
	for(int i=1;i<=k;i++){
		ans*=2;
	}
	for(int i=1;i<=m;i++){
		int a,b;
		scanf("%d%d",&a,&b);
		if(!((ppp>>a)&1ull)) ans/=2;
	}
	ans-=n;
	cout<<ans<<endl;
	return 0;
}
