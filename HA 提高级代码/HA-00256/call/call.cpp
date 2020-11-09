#include<cstdio>
#include<iostream>
#define rt register int
using namespace std;
int a[1001];
int n;
struct f
{
	int name;
	int x;
	int aa;
	int line[101];
}q[101];
void work(int x)
{
	switch(q[x].name)
		{
			case 1:a[q[x].aa]+=x;break;
			case 2:for(rt i=1;i<=n;i++) a[i]*=q[x].x;break;
			case 3:for(rt i=1;i<=q[x].aa;i++) switch(q[x].line[i]);break;
		}
}
int main()
{
	freopen("call.in","r",stdin);
	freopen("call.out","w",stdout);
	scanf("%ld",&n);
	for(rt i=1;i<=n;i++) scanf("%ld",&a[i]);
	int m;
	scanf("%ld",&m);
	for(rt i=1;i<=m;i++)
	{
		scanf("%ld",&q[i].name);
		switch(q[i].name)
		{
			case 1:scanf("%ld%ld",&q[i].aa,&q[i].x);break;
			case 2:scanf("%ld",&q[i].x);break;
			case 3:scanf("%ld",&q[i].aa);for(rt j=1;j<=q[i].aa;j++) scanf("%ld",&q[i].line[j]);break;
		}
	}
	int q;
	scanf("%ld",&q);
	for(rt i=1;i<=q;i++)
	{
		int x;
		scanf("%ld",&x);
		work(x);
	}
	for(rt i=1;i<=n;i++)
		printf("%ld ",a[i]);
	printf("%ld\n");
	fclose(stdin);
	fclose(stdout);
	return 0;
}
