#include<cmath>
#include<cstdio>
#include<vector>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
const int N=2e6+7;
#define ull unsigned long long
int T,n,m,k,c,p,q,l;
ull a[N];
int b[66],f[66];

inline ull read(){
	ull x=0;char ch=getchar();
	while(ch<'0'||ch>'9'){ch=getchar();}
	while(ch<='9'&&ch>='0'){ x=x*10+ch-'0'; ch=getchar();}
	return x;
}

inline void s(ull x){
	int i=0;
	while(x){
		if(x&1) b[i]=1;
		x>>=1; i++;
	}
}

int main(){
	freopen("zoo.in","r",stdin);
	freopen("zoo.out","w",stdout);
    n=read(),m=read(),c=read(),k=read();
    for(int i=1;i<=n;i++) a[i]=read(),s(a[i]);
    for(int i=1;i<=m;i++) p=read(),q=read(),f[p]=1;
    for(int i=0;i<k;i++) if(!f[i]) b[i]=1;
    for(int i=0;i<k;i++) if(b[i]) l++;
    cout<<(ull) pow(2,l)-n;
	return 0;
}
