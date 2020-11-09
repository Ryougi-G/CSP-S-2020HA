#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll hj,w,l,ch=2,op,kl,zong;
int main(){
	freopen("zoo.in","r",stdin);
	freopen("zoo.out","w",stdout);
	ll n,m,c,k,i,num,ans=0;
	scanf("%lld %lld %lld %lld",&n,&m,&c,&k);
	for(i=0;i<n;i++){scanf("%lld",&num);hj=hj|num;}
	num=0;
	for(i=0;i<m;i++){
		scanf("%lld %lld",&w,&l);
		if(l<1||l>c||w<0||w>=k){continue;}
		op=pow(ch,w);
		zong|=op;
		kl=hj|op;
		if(kl==hj){num|=op;}}
		cout<<num<<endl;
	for(i=0;i<pow(ch,k);i++){
		int k=(i&zong)|num;
		if(k==num){ans++;}}
	cout<<ans-n;
	return 0;
}
