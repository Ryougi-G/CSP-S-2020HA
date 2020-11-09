#include <bits/stdc++.h>
#define deb if(debug)
#define int long long
const int debug =0;
#define fo(i,x) for(int i=1;i<=(x);++i)
#define fo_(i,b,x) for(int i = b;i<=x;++i)
#define re(i,b,x) for(int i = b;i>=x;--i)
#define N 100010
#define mod 998244353
#define ull unsigned long long
using namespace std;
int n;
struct snake{
	int id,val;
};
bool comp(snake x,snake y){
	if(x.val!= y.val) return x.val>y.val;
	else return x.id>y.id;
}
int a[N];
void sub20(int x,int y,int z){
	snake s[3];
	s[0].id = 1,s[0].val = x;
	s[1].id = 2,s[1].val = y;
	s[2].id = 3,s[2].val = z;
	sort(s,s+3,comp);
//	fo_(i,0,2) cout<<s[i].val<<" ";
//	printf("\n");
//	fo_(i,0,2) cout<<s[i].id<<" ";
	if(s[0].val - s[2].val<s[1].val) cout<<"3\n";
	if(s[0].val - s[2].val>=s[1].val) cout<<"1\n";
}
signed main(){
	freopen("snakes.in","r",stdin);
	freopen("snakes.out","w",stdout);
	int a,b,c;
	int T;cin>>T;int TT=T;
	while(T--){
		cin>>n;
//		cout<<n<<"\n";
//		cout<<T<<" "<<TT<<"\n";
		if(n==3 && (T==TT-1)){
//			printf("Here!");
			cin>>a>>b>>c;
			sub20(a,b,c);
		}else if(n==3){
			fo(i,6){
				int op;cin>>op;
				if(op==1){
					int mof;cin>>mof;
					a = mof;
				}else if (op==2){
					int mof;cin>>mof;
					b = mof;
				}else if (op==3){
					int mof;cin>>mof;
					c = mof;
				}else{
//					printf("Error\n");
				}
			}
//			printf("%lld %lld %lld\n",a,b,c);
			sub20(a,b,c);
		}
	}
	return 0;
}
