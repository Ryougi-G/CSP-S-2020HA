#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int qr(){
	int x=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
	return x*f;
}
int a[1000005],P[1000005],V[1000005];
int C,g[1000005],t[1000005],f[100005],n;
void ad();
void xx(int x);
int main(){
	freopen("call.in","r",stdin);
	freopen("call.out","w",stdout);
	n=qr();
	for(int i=1;i<=n;++i)	a[i]=qr();	
	int m=qr(),x;
	for(int i=1;i<=m;++i){
		t[i]=qr();
		if(t[i]==1){
			P[i]=qr();V[i]=qr();
		}
		else if(t[i]==2){
			P[i]=-1;x=qr();
		}
		else if(t[i]==3){
			C=qr();
			for(int j=1;j<=C;++j){
				g[j]=qr();
			}
		}
	}
	int Q=qr();
	for(int i=1;i<=Q;++i){
		f[i]=qr();
		if(f[i]==1){
			ad();
		}
		if(f[i]==2){
			xx(x);
		}
		if(f[i]==3){
			for(int j=1;j<=C;++j){
				if(g[j]==1){
					ad();
				}
				if(g[j]==2){
					xx(x);
				}
			}
		}
	}
	for(int i=1;i<=n;++i){
		a[i]%=998244353;
		printf("%d ",a[i]);
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
void ad(){
	for(int i=1;i<=n;++i){
		if(P[i]>=0) a[P[i]]+=V[i];
	}
}
void xx(int x){
	for(int i=1;i<=n;++i){
		a[i]*=x;
		a[i]%=998244353;
	}
}
