#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#define ull unsigned long long
#define DUBUG(N,S) cerr<<"N:"<<S<<endl;
#define TEST cerr<<"test"<<endl;
using namespace std;
ull n,k,m,c;
int ciliao[21];
int kkk[20];
int pet[6];
ull has;
int main(){
	freopen("zoo.in","r",stdin);
	freopen("zoo.out","w",stdout);
	cin>>n>>m>>c>>k;
	for(int i=1;i<=n;++i){
		cin>>pet[i];
		has |= pet[i];
	}
	for(int i=1;i<=m;++i){
		int p,q;
		cin>>p>>q;
		if(((1<<(p))&1)==true){
			kkk[p]=2;
		}else{
			kkk[p]=1;
		}
	}
	ull ans=1;
	for(int i=0;i<=k;++i){
		if(kkk[i]==0)kkk[i]=2;
		ans*=kkk[i];
	}
	cout<<ans-n<<endl;
	return 0;
}
