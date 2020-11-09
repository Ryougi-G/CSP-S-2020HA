#include<bits/stdc++.h>
#define LL long long 
#define lowbit (i&(-i))
using namespace std;
const int maxn=1e6+10;
struct node
{
 	int pos;
 	LL need;
}one[maxn];
unsigned ans;
int P,U;
int n,m,c,k;
int bin1[80];
int bin2[80];
int pos[80];
LL dataA[maxn];
void solve(LL);
unsigned long long qpow(int,int);
int main()
{
	freopen("zoo.in","r",stdin);
	freopen("zoo.out","w",stdout);
	memset(bin1,0,sizeof(bin1));
	memset(bin2,0,sizeof(bin2));
	memset(pos,-1,sizeof(pos));
	cin>>n>>m>>c>>k;
	for(int i=1;i<=n;i++) cin>>dataA[i];
	for(int i=1;i<=m;i++) cin>>one[i].pos>>one[i].need;
	for(int i=1;i<=m;i++) pos[one[i].pos]=1;
	for(int i=1;i<=n;i++) solve(dataA[i]);
	for(int i=1;i<=m;i++) bin1[one[i].pos]=1;
	for(int i=0;i<=70;i++) if(bin1[i]) P++;
	P=k-P;
	for(int i=0;i<=k;i++) if(bin2[i]) U++; 
	ans=qpow(2,P+U)-n;
	cout<<ans<<endl;
	
}
void solve(LL n)
{
	for(int i=0;i<65;i++) 
	{
		if(pos[i]==-1) continue;
		if(n&(1LL*1<<i)) bin2[i]=1;
	}
}
unsigned long long qpow(int base,int n)
{
	unsigned long long ans=1;
	while(n)
	{
		if(n&1) ans=(ans*base);
		base=base*base;
		n>>=1;
	}
	return ans;
}


