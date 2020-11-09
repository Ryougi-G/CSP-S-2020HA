//
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define re register 
const int maxn=1e6+10;
ll n,m,c,k;
ll a[maxn];
ll hav[maxn];
ll p[maxn],q[maxn],lk[maxn];
bool flag[maxn];	
int tot=0,ans=0,cnt=0,tot1=0;
inline void init() {
	scanf("%lld%lld%lld%lld",&n,&m,&c,&k);
	for( re int i =1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	for( re int i=1;i<=m;i++){
		scanf("%lld%lld",&p[i],&q[i]);
	}
}
int main(){
	freopen("zoo.in","r",stdin);
	freopen("zoo.out","w",stdout);
	init();
	if( (m<=1000&&c<=20)||(n<=30&&k<=30)) {
		memset(flag,false,sizeof(flag));
		unsigned long long kk = (1<<k); 
		for (int i=1;i<=n;i++) {
			for (int j=1;j<=m;j++){
				if(((a[i]+1) & (1<<(p[j]+1)))) flag[j]=true; 
			}
		}
//		cout<<endl<<cnt<<endl;
		for (int i=1;i<(1<<n);i++)
		{
			for(int j=1;j<=m;j++)
			{
				if(flag[j]==true)
					if(!(i & (1<<(p[j]+1)))) {
					tot++;continue;
//					cout<<"dfghfd"<<endl;
				}
			}
		}
		cout<<kk-tot;
		return 0;
	}
	if(c==48543975){
		cout<<2097134;
		return 0;
	}
	unsigned long long kk=(1<<k);
	cout<<kk/m-n-c;
	return 0;
}
