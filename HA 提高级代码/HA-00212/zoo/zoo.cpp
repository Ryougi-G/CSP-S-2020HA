#include<cstdio>
#include<bitset>

typedef unsigned long long int64;

using std::bitset;

const int N=1e6+100;
const int M=1e8+100;

int64 a[N];
int p[N],q[N];
bool use[100],can[100],ref[100];
bitset<M> buy;

int main()
{
	freopen("zoo.in","r",stdin);
	freopen("zoo.out","w",stdout);
	int n,m,c,k;
	scanf("%d%d%d%d",&n,&m,&c,&k);
	for (int i=1;i<=n;++i) scanf("%llu",a+i);
	for (int i=1;i<=m;++i) scanf("%d%d",p+i,q+i),ref[p[i]]=true;
	for (int i=1;i<=n;++i)
	{
		int64 t=a[i];
		for (int w=0;w<k;++w)
			if ((t&(1ull<<w))) use[w]=true;
	}
	for (int i=1;i<=m;++i)
		if (use[p[i]]) buy[q[i]]=true;
	for (int i=1;i<=m;++i)
		if (buy[q[i]]) can[p[i]]=true;
	int tot=0;
	for (int i=0;i<k;++i)
		if (can[i] || !ref[i]) ++tot;
	printf("%llu",(1ull<<tot)-n);
}
