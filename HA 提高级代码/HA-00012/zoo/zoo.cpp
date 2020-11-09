#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<iomanip>
#include<string>
#include<cstring>
#include<queue>
#include<vector>
#define ull unsigned long long
#define re register
#define il inline
#define int ull
const int maxn = 1e6+10;
using namespace std;
il int read(){
	int x=0,f=1;
	char ch = getchar();
	while(!isdigit(ch)){
		if(ch=='-')f=-1;
		ch = getchar();
	}
	while(isdigit(ch)){
		x=x*10+ch-'0';
		ch = getchar();
	}
	return x;
}

const int maxc = 1e8+5;

int n,m,c,k;
int p[maxn],q[maxn];
ull a[maxn];
bool kh[maxc],rh[maxc];
int h[65];

il ull qpow(int a,int b){
	int base = a,ans = 1;
	for(;b;b>>=1,base*=base)
		if(b&1)ans*=base;
	return ans;
}

signed main(){
	freopen("zoo.in","r",stdin);
	freopen("zoo.out","w",stdout);
	n=read(),m=read(),c=read(),k=read();
	for(re int i = 1;i<=n;i++){
		a[i]=read();
		for(re int j = 0;j<=k;j++){
			if(a[i]>>j&1)h[j]=1;
		}
	}
	for(re int i = 1;i<=m;i++){
		p[i]=read(),q[i]=read();
		if(h[p[i]])kh[q[i]]=1;
		else h[p[i]]=-1;
	}
//	for(int i=1;i<=10;i++){
//		cout<<h[i];
//	}
//	cout<<endl;
//	for(int i=1;i<=10;i++){
//		cout<<kh[i];
//	}
	int cnt=0;
	for(re int i =1;i<=k;i++){
		if(h[i]!=-1)cnt++;
	}
	ull ans = qpow(2,cnt) - n;
	printf("%lld",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

