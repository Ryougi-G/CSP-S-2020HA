#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c<='9'&&c>='0'){
		x=(x<<1)+(x<<3)+(c^48);
		c=getchar();
	}return x*f;
}
long long qpow(int a,int n){
	long long ans=1;
	while(n){
		if(n&1)ans*=a;
		a*=a;
		n>>=1;
	}return ans;
}
int n,m,c,k,a[1000005],p[1000005],q[1000005];
int maxn(int x){
	int ans=1,t=0;
	while(ans*2<=x){
		ans*=2,t++;
	}return t+1;
}
string tt(int x){
	string ans="";
	int t=maxn(x);
	while(t--){
		if(x!=x/2*2){
			ans+="1";
		}else{
			ans+="0";
		}x/=2;
	}
	while(ans.length()<k){
		ans+="0";
	}
	return ans;
}
int main(){
	freopen("zoo.in","r",stdin);
	freopen("zoo.out","w",stdout);
	n=read(),m=read(),c=read(),k=read();
	for(int i=1;i<=n;++i)a[i]=read();
	for(int i=1;i<=m;++i)p[i]=read(),q[i]=read();
	long long fans=qpow(2,k);
	int ans=0,num=0;
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			string t=tt(a[i]);
			if(t[p[j]]=='1'){
				num++;
				break;
			}
		}
	}
	if(num==m){
		cout<<fans-num<<endl;
	}else{
		cout<<fans/2-n<<endl;
	}return 0;
}
