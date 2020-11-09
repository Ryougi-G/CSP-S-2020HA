#include <bits/stdc++.h>
#define ll long long
#define S 300
using namespace std;
int n,k,m,c;
ll a[S];
int q[S],p[S];
int cc[9000000000];
vector<int> dd[S];
ll ans;
int main(){
//	freopen("rp.out","w",stdout);
	freopen("zoo.in","r",stdin);
	freopen("zoo.out","w",stdout);
	scanf("%d%d%d%d",&n,&m,&c,&k);
	for(int i=1;i<=n;++i)scanf("%lld",&a[i]);
	for(int i=1;i<=m;++i){
		scanf("%d%d",&q[i],&p[i]);
		dd[q[i]].push_back(p[i]);
	}
	for(int i=1;i<=n;++i){
		for(ll j=0;j<=k;++j){
//			cout<<((a[i]>>j)&1);
			if((a[i]>>j)&1){
				for(int k=0;k<dd[j].size();++k){
					cc[dd[j][k]]=1;
//					cout<<"  dd[j][k]="<<dd[j][k]<<"  ";
				}
			}
		}
//		cout<<endl;
	}
//	int cnt=0;
	for(int i=0;i<(1<<(k));++i){
		int now=1;
//		cnt++;
//		cout<<cnt<<endl;;
		for(ll j=0;j<=k;++j){
			if(!now)break;
			if((i>>j)&1){
				for(int k=0;k<dd[j].size();++k){
					now&=cc[dd[j][k]];
//					cout<<j<<endl;
//					cout<<k<<endl;

					if(!now)break;
				}
			}
		}
		if(now)ans++;
	}
//	printf("%lld       %d\n",ans,n);
	printf("%lld\n",ans-n);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
