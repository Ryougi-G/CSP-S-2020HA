#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int mod=998244353;
int n,m,q,no1=1,no2=1,a[100010];
int opt[100010],mul[100010],P[100010],V[100010],C[100010];
vector<int>add[100010],pos[100010],g[100010];
inline int read()
{
	int x=0,w=0;char ch=0;
	while(!isdigit(ch)){w|=ch=='-';ch=getchar();}
	while(isdigit(ch)){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
	return w?-x:x;
}
void _RuN(int x)
{
	if(opt[x]==3){
		for(int i=0;i<g[x].size();i++)
			_RuN(g[x][i]);
	}
	if(opt[x]==2){
		for(int i=1;i<=n;i++)
		a[i]=(LL)a[i]*mul[x]%mod;
	}
	if(opt[x]==1){
		a[pos[x][0]]+=add[x][0];
		a[pos[x][0]]%=mod;
	}
}
int main()
{
	freopen("call.in","r",stdin);
	freopen("call.out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++)
	a[i]=read();
	m=read();
	for(int i=1;i<=m;i++){
		opt[i]=read();mul[i]=1;
		if(opt[i]==1){
			pos[i].push_back(P[i]=read());
			add[i].push_back(V[i]=read());
			no1=0;
		}
		if(opt[i]==2){
			mul[i]=read();
			no2=0;
		}
		if(opt[i]==3){
			C[i]=read();
			for(int j=1;j<=C[i];j++)
				g[i].push_back(read());
		}
	}
	//if(no1)solveno1();
    //if(no2)solveno2();
	q=read();
	while(q--){
		_RuN(read());
	
	}
	for(int i=1;i<=n;i++)
	printf("%d ",a[i]);
	cout<<'\n';
	
}
