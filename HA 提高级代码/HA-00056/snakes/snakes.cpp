#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <map>
#include <ctime>
#include <cstdlib>
#define maxn 1001000
using namespace std;
namespace IO
{
	char ss[1<<17|1],*A,*B;
	inline char gc()
	{
		if(A==B)
		{
			B=(A=ss)+fread(ss,1,1<<17,stdin);
			if(A==B) return EOF;
		}
		return *A++;
	}
	template<class T>inline void read(T &x)
	{
		x=0; char ch=gc();
		while(ch<'0' || ch>'9') ch=gc();
		while(ch>='0'&&ch<='9') x=(x<<1)+(x<<3)+(ch^48),ch=gc();
	}
}
inline void file()
{
	freopen("snakes.in","r",stdin);
	freopen("snakes.out","w",stdout);
}
int n; 
struct SN 
{ 
	int num,bh;
	bool operator < (SN rhs) const { return num<rhs.num || (num==rhs.num && bh<rhs.bh); }
	SN operator - (SN rhs) const { return (SN) { num-rhs.num,bh }; }
};
struct T { int ls,rs,rd,size;SN val; }ry[maxn],re[maxn];
int root,reroot;
inline void pushup(int x,T *t) { t[x].size=t[t[x].ls].size+t[t[x].rs].size+1; }
inline int newnode(SN val,T *t)
{
	int tot=val.bh;
	t[tot].ls=t[tot].rs=0;
	t[tot].val=val;
	t[tot].size=1; t[tot].rd=rand();
	return tot;
}
inline void split_num(int now,int &x,int &y,SN num,T *t)
{
	if(!now) x=y=0;
	else 
	{
		if(t[now].val<num) 
		{
			x=now;
			split_num(t[now].rs,t[x].rs,y,num,t);
		}
		else 
		{
			y=now;
			split_num(t[now].ls,x,t[y].ls,num,t);
		}
		pushup(now,t);
	}
}
inline void split_k(int now,int &x,int &y,int k,T *t)
{
	if(!now) x=y=0;
	else 
	{
		if(t[t[now].ls].size+1<=k)
		{
			x=now;
			split_k(t[now].rs,t[x].rs,y,k-t[t[now].ls].size-1,t);
		}
		else 
		{
			y=now;
			split_k(t[now].ls,x,t[y].ls,k,t);
		}
		pushup(now,t);
	}
}
inline int merge(int x,int y,T *t)
{
	if(!x || !y) return x|y;
	if(t[x].rd<=t[y].rd)
	{
		t[y].ls=merge(x,t[y].ls,t);
		pushup(y,t);
		return y;
	}
	else 
	{
		t[x].rs=merge(t[x].rs,y,t);
		pushup(x,t);
		return x;
	}
}
inline SN findmin(int x,T *t)
{
	while(t[x].ls) x=t[x].ls;
	return t[x].val;
}
int whoe[maxn],ewho[maxn],lastt[maxn],lastc[maxn];
inline int solve()
{
	int ans=0;
	while(ans<=n-3)
	{
		int a,b,c,d;
		split_k(root,a,d,ry[root].size-1,ry);
		split_k(a,a,c,1,ry);
		ry[d].val=ry[d].val-ry[a].val;
		ans++;
		whoe[ans]=ry[d].val.bh;
		ewho[ans]=ry[a].val.bh;
		split_num(c,b,c,ry[d].val,ry);
		root=merge(merge(b,d,ry),c,ry);
	}
	int a,b; split_k(root,a,b,1,ry);
	whoe[n-1]=ry[b].val.bh,ewho[n-1]=ry[a].val.bh;
	for(register int i=1;i<=n-1;i++) lastc[i]=lastt[ewho[i]],lastt[whoe[i]]=i;

	int nowt=n-1;
	for(register int i=nowt;i>0;i--)
		if(i<=nowt && lastc[i]) nowt=lastc[i]-1;
	return n-nowt;
}

inline void init()
{
	memcpy(ry,re,sizeof re);
	root=reroot;
	memset(lastc,0,sizeof lastc); memset(lastt,0,sizeof lastt);
}
int main()
{
	file();
	int m; IO::read(m);
	IO::read(n);
	for(register int i=1;i<=n;i++)
	{
		int ai; IO::read(ai);
		reroot=merge(reroot,newnode((SN){ai,i},re),re);
	}
	for(register int i=1;i<=m;i++)
	{
		init(); 
		printf("%d\n",solve());
		if(i==m) break;
		int q; IO::read(q);
		while(q--)
		{
			int x,y;IO::read(x); IO::read(y);
			re[x].val.num=y;
		}
	}
	return 0;
}
