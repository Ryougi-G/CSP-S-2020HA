#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;

struct man{
	int x,y;
}e[3000000];

long long mi2[30]={1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,65536,131072,262144,524288,1048576,2097152,4194304,8388608};
int n,m,c,k;
int have[300000]={};
int f[3000000]={};
int gong[3000000]={};
int cnt=0;
int t1,t2;
int main(){
	freopen("zoo.in","r",stdin);
	freopen("zoo.out","w",stdout);
	scanf("%d%d%d%d",&n,&m,&c,&k);
	for(int i = 1;i<=n;i++){
		scanf("%d",&t1);
		for(int j = 23;t1!=0;j--){
			if(mi2[j]<=t1){
				t1-=mi2[j];
				have[j]=1;
			}
		}
	}
	for(int i  =1;i<=m;i++){
		scanf("%d%d",&e[i].x,&e[i].y);
		if(have[e[i].x])  f[e[i].y]=1;
	}
	for(int i=1;i<=m;i++){
		if(!f[e[i].y])  gong[e[i].x]=1;
	}
	for(int i = 1;i<=n;i++){
		if(gong[i])  cnt++;
	}
	printf("%lld",mi2[k-cnt]-n);
	return 0;
}
