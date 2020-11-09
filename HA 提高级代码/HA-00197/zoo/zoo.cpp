#include<bits/stdc++.h>
using namespace std;
const int maxn=1000100,maxc=100000100,maxk=66;

int n,m,c,k,ansk=0;
unsigned long long a[maxn]={};
unsigned long long pw2[maxk]={};
int p[maxn]={},q[maxn]={};

bool b[maxn][maxk]={};
bool s[maxc]={};
bool h[maxk]={};

bool cal[maxn]={};

int main(){
	freopen("zoo.in","r",stdin);freopen("zoo.out","w",stdout);
	pw2[0]=1;for(int i=1;i<=64;i++)pw2[i]=pw2[i-1]*2;
//	printf("%d",(&ed-&st)/1024/1024);
	scanf("%d%d%d%d",&n,&m,&c,&k);
//	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%llu",&a[i]);
		int tt=0;
		while(a[i])b[i][tt]=(a[i]&1),h[tt]|=(a[i]&1),a[i]/=2,tt++;
//		for(int j=0;j<=10;j++)printf("%d ",b[i][j]);printf("\n");
	}
//	printf("%llu",);
	for(int i=0;i<k;i++)cal[i]=1;
	for(int i=1;i<=m;i++){
		scanf("%d%d",&p[i],&q[i]);
		if(h[p[i]])s[q[i]]=1;
	}
	
	for(int i=1;i<=m;i++)if(!s[q[i]])cal[p[i]]=0;
	
	for(int i=0;i<k;i++)ansk+=cal[i];
	printf("%llu",pw2[ansk]-n);
	return 0;
}
/*
18446744073709551615

18446744073709551616
*/
