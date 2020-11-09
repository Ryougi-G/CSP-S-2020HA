#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,k,T;
struct snake{
	ll w;
	ll num;
	bool live;
};
snake a[1000001];
bool cmp(snake x,snake y){
	if(x.w>y.w) return true;
	if(x.w==y.w&&x.num>y.num) return true;
	return false;
}
bool Max(snake x,snake y){
	if(x.w>y.w) return true;
	if(x.w==y.w&&x.num>y.num) return true;
	return false;
}
snake eat(snake x,snake y){
	x.w-=y.w;
	y.live=false;
	return x;
}
bool d(snake x,snake y){
	if(x.w==y.w)
	return true;
	return false;
}
int main(){
	freopen("snakes.in","r",stdin);
	freopen("snakes.out","w",stdout);
	std::ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>T;
	ll x,y; 
	T--;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i].w;
			a[i].num=i;
			a[i].live=true;
		}
		sort(a+1,a+n+1,cmp);
		bool flag=true;
		while(flag==true){
			if(Max(eat(a[1],a[n]),a[n-1])){
				cout<<"1"<<endl;
				break;
			}
			if(Max(a[n-1],eat(a[1],a[n]))){
				cout<<n<<endl;
				break;
			}
			if(d(a[n-1],eat(a[1],a[n]))){
				cout<<"2"<<endl;
				break;
			}
		}
		
	while(T--){
		cin>>k;
		for(int i=1;i<=k;i++){
			cin>>x>>y;
			a[x].w=y;
		}
		sort(a+1,a+n+1,cmp);
//		for(int i=1;i<=n;i++){
//			
//			for(int j=n;j>=1;j--){
//				if()
//			}
////			for(int j=1;j<=)
//		}

		if(Max(eat(a[1],a[n]),a[n-1])){
				cout<<"1"<<endl;
				continue;
		}
		if(Max(a[n-1],eat(a[1],a[n]))){
			cout<<n<<endl;
			continue;
		}
		if(d(a[n-1],eat(a[1],a[n]))){
			cout<<"2"<<endl;
			continue;
		}
		
	
	}
	
	return 0;
}
/*
2
3
11 14 14
3
1 5 2 6 3 25
*/
