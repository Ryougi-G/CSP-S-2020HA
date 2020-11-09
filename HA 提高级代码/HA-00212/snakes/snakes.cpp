#include <cstdio>
#include <map>

using std::map;
using std::make_pair;

map<int,int> mp;

const int N=1e6+200;

int a[N];

inline int work(int n)
{
	if (n==2) return 1;
	if (n==3)
	{
		if (a[3]-a[1]>=a[2]) return 1;
		else return 3;
	}
}

int main()
{
	freopen("snakes.in","r",stdin);
	freopen("snakes.out","w",stdout);
	int T;
	scanf("%d",&T);
	int n;scanf("%d",&n);
	for (int i=1;i<=n;++i) scanf("%d",a+i);
	printf("%d\n",work(n));
	while (--T)
	{
		int k;
		scanf("%d",&k);
		for(int i=1,x,y;i<=k;++i)
			scanf("%d%d",&x,&y),a[x]=y;
		printf("%d\n",work(n));
	}
}
