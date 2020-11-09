#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <map>
#define ll unsigned long long
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
	freopen("zoo.in","r",stdin);
	freopen("zoo.out","w",stdout);
}
int main()
{
	file();
	ll n,m,k,c;
	ll sh=0,qe=0;
	IO::read(n); IO::read(m); IO::read(c); IO::read(k);
	for(register int i=1;i<=n;i++)
	{
		ll a; IO::read(a);
		sh|=a;
	}
	for(register int i=1;i<=m;i++)
	{
		int x,y; IO::read(x); IO::read(y);
		qe|=(ll)1<<x;
	}
	qe=qe^(sh&qe);
	int acount=0;
	while(qe) {
		if(qe&1) acount++;
		qe>>=1;
	}
	cout<<((ll)1<<(k-acount))-n;
	return 0;
}
