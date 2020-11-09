#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;
//typedef pair<int,int> P;
const int MAX_N=1.1e5,mod=998244353;
int readint()
{
	bool neg=false;
	int x=0;
	char c=getchar();
	while(c<'-')c=getchar();
	if(c=='-'){neg=true;c=getchar();}
	for(;c>='0'&&c<='9';c=getchar())
		x=x*10+c-'0';
	return neg?-x:x;
}
int A[MAX_N],N;

int inv[1010],lastnum,lastinv;
int opt[MAX_N],P[MAX_N],V[MAX_N];
int mul=1;
vector<int> G[MAX_N];
int getinv(ll x)
{
	if(x<1010)return inv[x];
	if(lastnum==x)return lastinv;
	int res=1;
	int p=mod-2;
	while(p)
	{
		if(p&1)res=res*x%mod;
		x=x*x%mod;
		p>>=1;
	}
	lastnum=x;
	lastinv=res;
	return res;
}
void dfs(int u)
{
	switch(opt[u])
	{
		case 1:
			A[P[u]]+=V[u]*(ll)getinv(mul)%mod;
			if(A[P[u]]>=mod)A[P[u]]-=mod;
			break;
		case 2:mul=mul*ll(V[u])%mod;break;
		case 3:
			for(int i=0;i<G[u].size();i++)
				dfs(G[u][i]);
			break;
	}
}
int main()
{
	freopen("call.in","r",stdin);
	freopen("call.out","w",stdout);
	inv[1]=1;
	for(int i=2;i<1010;i++)
		inv[i]=(mod-mod/i)*(ll)inv[mod%i]%mod;
	
	N=readint();
	for(int i=1;i<=N;i++)A[i]=readint();
	int m=readint();
	for(int i=1;i<=m;i++)
	switch(opt[i]=readint())
	{
		case 1:P[i]=readint();V[i]=readint();break;
		case 2:V[i]=readint();break;
		case 3:
			int c=readint();
			G[i].resize(c);
			for(int j=0;j<c;j++)
				G[i][j]=readint();
			break;
	}
	opt[0]=3;
	int c=readint();
	G[0].resize(c);
	for(int i=0;i<c;i++)
		G[0][i]=readint();
	dfs(0);
	
	for(int i=1;i<=N;i++)
		printf("%lld ",A[i]*(ll)mul%mod);
		
	fclose(stdin);
	fclose(stdout);
	return 0;
}
