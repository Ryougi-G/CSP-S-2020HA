#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int maxn=2010;
const int mod=998244353;
struct haha
{
 	int to; int nxt;
}e[maxn];
struct point
{
 	int opt; int val; int pos;
}one[maxn];
int cnt;
int n,m;
int seq[maxn][maxn];
int data[maxn];
void dfs(int);
inline void solve1(int);
inline void solve2(int );
signed main()
{
	freopen("call.in","r",stdin);
	freopen("call.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>data[i];
	cin>>m;
	for(int i=1;i<=m;i++)
	{
		int opt;
		cin>>opt;
		if(opt==1) 
			cin>>one[i].pos>>one[i].val,one[i].opt=opt;
		if(opt==2)
			cin>>one[i].val,one[i].opt=opt;
		if(opt==3)
		{
			static int tmp,temp;
			cin>>tmp; one[i].opt=opt;
			for(int j=1;j<=tmp;j++)
			{
				cin>>temp; int top=0;
				seq[i][++seq[i][0]]=temp;
			}
		}
	}
	static int Q; static int fi;
	cin>>Q;
	for(int i=1;i<=Q;i++)
	{
		cin>>fi;
		dfs(fi);
	}
	for(int i=1;i<=n;i++) cout<<(data[i]%mod+mod)%mod<<" ";
}
void dfs(int u)
{
	if(one[u].opt==1) solve1(u);
	if(one[u].opt==2) solve2(u);
	if(one[u].opt==3)
	{
		for(int i=1;i<=seq[u][0];i++)
			dfs(seq[u][i]);
	}
	return;
}
inline void solve1(int pos)
{
	data[one[pos].pos]+=one[pos].val;
	data[one[pos].pos]%=mod;
}
inline void solve2(int pos)
{
	for(int i=1;i<=n;i++)
		data[i]=(data[i]*one[pos].val)%mod;
}
