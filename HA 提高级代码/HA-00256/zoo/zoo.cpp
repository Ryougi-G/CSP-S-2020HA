#include<cstdio>
#include<iostream>
#define rt register int

using namespace std;

int main()
{
	freopen("zoo.in","r",stdin);
	freopen("zoo.out","w",stdout);
	int n,m,c,k;
	scanf("%d%d%d%d",&n,&m,&c,&k);
	int ans=1;
	unsigned long long int num=1<<k,animal=0,feed=0;
	for(rt i=1;i<=n;i++) {unsigned long long int x;scanf("%ulld",&x);animal|=x;}
	for(rt i=1;i<=m;i++) {unsigned long long int x;scanf("%ulld",&x);int y=1<<x;feed|=y;scanf("%ld x",&x);}
	unsigned long long int modal=animal&feed;
	for(rt i=1;i<num;i++){int x=animal;x|=i;if((x&feed)<=modal) ans++;}
	printf("%ld\n",ans-n);
	fclose(stdin);
	fclose(stdout);
}
