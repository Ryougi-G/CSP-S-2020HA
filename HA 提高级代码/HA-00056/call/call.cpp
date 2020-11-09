#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <map>
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
	freopen("call.in","r",stdin);
	freopen("call.out","w",stdout);
}
int main()
{
	freopen("in.txt","r",stdin);
	return 0;
}

