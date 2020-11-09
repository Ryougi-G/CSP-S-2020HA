#include<bits/stdc++.h>
#define maxn 1005
using namespace std;
int T;int n,c1,c2,c3;
long long a[maxn];
void work(){
	int k;
	scanf("%d",&k);
	if(n==3){
		long long y;
		int x;
		for(int i=1;i<=k;i++){
			scanf("%d%lld",&x,&y);
			a[x]=y;
		}
		sort(a+1,a+n+1);
		long long B=a[3],M=a[2],L=a[1];
		if(B-L>M){
			B=B-L;L=0;
			cout<<"1"<<'\n';
			return ;
		}
		if(B-L==M){
			cout<<"2"<<'\n';return ;
		}
		cout<<"3"<<'\n';
		return ;
	}
}
int main()
{
	freopen("snakes.in","r",stdin);
	freopen("snakes.out","w",stdout);
	scanf("%d",&T);
	scanf("%d",&n);
	if(n==3){
		scanf("%lld%lld%lld",&a[1],&a[2],&a[3]);
		sort(a+1,a+n+1);
		long long B=a[3],M=a[2],L=a[1];
		if(B-L>M){
			B=B-L;L=0;
			cout<<"1"<<'\n';
		}
		if(B-L==M){
			cout<<"2"<<'\n';
		}
		if(B-L<M )cout<<"3"<<'\n';
	}
	T--;
	while(T--) work();
	return 0;
}
/*
2
3
11 14 14
3
1 5 2 6 3 25
*/
