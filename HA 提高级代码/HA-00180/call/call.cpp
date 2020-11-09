#include<bits/stdc++.h>
using namespace std;
long long h[100005][1005],s[1005],tag=1,n;
void dy(long long g){
	if(h[0][g]==1){
		s[h[1][g]]=(s[h[1][g]]+h[2][g])%998244353;
	}
	else if(h[0][g]==2){
		for(int y=1;y<=n;y++){
			s[y]=(s[y]*h[1][g])%998244353;
		}
	}
	else if(h[0][g]==3){
		for(int y=2;y<=1+h[1][g];y++){
			dy(h[y][g]);
		}
	}
}
int main(){
	freopen("call.in","r",stdin);
	freopen("call.out","w",stdout);
	long long i,k,p,l;
	scanf("%lld",&n);
	for(i=1;i<=n;i++){
		scanf("%lld",&s[i]);
	}
	scanf("%lld",&l);
	for(i=1;i<=l;i++){
		scanf("%lld",&h[0][i]);
		if(h[0][i]==1){
			scanf("%lld %lld",&h[1][i],&h[2][i]);
		}
		else if(h[0][i]==2){
			scanf("%lld",&h[1][i]);
		}
		else if(h[0][i]==3){
			scanf("%lld",&h[1][i]);
			for(k=2;k<=h[1][i]+1;k++){
				scanf("%lld",&h[k][i]);
			}
		}
	}
	scanf("%lld",&l);
	for(i=0;i<l;i++){
		scanf("%lld",&p);
		dy(p);
	}
	for(i=1;i<=n;i++){
		cout<<s[i]<<" ";
	}
	return 0;
}
