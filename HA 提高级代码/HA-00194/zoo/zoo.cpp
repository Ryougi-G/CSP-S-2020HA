#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int qr(){
	int x=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
	return x*f;
}
int N[1000005],p[1000005];
int M[1000005],b[1000005];
int vis[1100003];
int main(){
	freopen("zoo.in","r",stdin);
	freopen("zoo.out","w",stdout);
	memset(vis,0,sizeof(vis));
	int n=qr(),m=qr(),c=qr(),k=qr(),x=1,sum=0;
	for(int i=1;i<=n;++i)	N[i]=qr();
	for(int i=1;i<=m;++i){
		int xa=qr(),xb=qr();
		p[xa]=xb;
	}
	for(int i=1;i<=k;++i)	x*=2;x-=1;
	for(int i=1;i<=n;++i){
		int cnt =0;
		vis[N[i]]=1;
		while(N[i]>0){
			M[cnt]=N[i]%2;
			N[i]/=2;
			++cnt;
		}
		for(int j=0;j<cnt;++j){
			if(M[j]){
				b[p[j]]=1;
			}
		}
	}
	for(int i=0;i<=x;++i){
		int pd=0;
		if(!vis[i]){
			int cnt = 0,z=i;
			if(z==0) sum+=1;
			while(z>0){
				M[cnt]=z%2;
				z/=2;
				++cnt;
			}
			for(int j=0;j<cnt;++j){
				if(!b[p[j]]&&M[j]!=0){
					pd=0;
					break;
				}
				pd=1;
			}
		}
		if(pd) sum+=1;
	}
	printf("%d",sum);
	fclose(stdin);fclose(stdout);
	return 0;
}
