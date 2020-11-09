#include<bits/stdc++.h>
using namespace std;

struct NODE
{
	int t,p,v;
};
NODE ain[100010];
int n,a[100010],ad,c,m;

int main()
{
	memset(a,0,sizeof(0));
	memset(ain,0,sizeof(ain));
	freopen("call.in","r",stdin);
	freopen("call.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		printf("%d ",a[i]);
	}
	return 0;
}
