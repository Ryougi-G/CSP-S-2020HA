#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXM=11,MAXN=1000001;
struct stu{
	int zhi,hao;
}a[MAXN];
int main()
{
	freopen("snakes.in","r",stdin);
	freopen("snakes.out","w",stdout);
	int N,T,k,re[5],result=0,x;
	scanf("%d",&T);
	for(int i=2;i<=T;i++)
	{
		if(i==2)
		{
			scanf("%d",&N);
			for(int j=1;j<=3;j++)
			{
				scanf("%d",&a[j].zhi);
				a[j].hao=j;
			}
			if(a[3].zhi<a[2].zhi)	swap(a[3],a[2]);
			if(a[2].zhi<a[1].zhi)	swap(a[2],a[1]);
			if(a[3].zhi<a[2].zhi)	swap(a[2],a[3]);
			if(a[3].zhi-a[1].zhi>=a[2].zhi&&a[3].hao>a[2].hao)
			{
				printf("1\n");
			}
			else
			{
				printf("3\n");
			}			
		}			
		scanf("%d",&k);
		for(int t=1;t<=k;t++)
		{	
			scanf("%d",&x);
			for(int j=1;j<=3;j++)
			{
				if(a[j].hao==x)
				scanf("%d",&a[j].zhi);	
			}				
		}
		if(a[3].zhi<a[2].zhi)	swap(a[3],a[2]);
		if(a[2].zhi<a[1].zhi)	swap(a[2],a[1]);
		if(a[3].zhi<a[2].zhi)	swap(a[2],a[3]);
		if(a[3].zhi-a[1].zhi>=a[2].zhi&&a[3].hao>a[2].hao)
		{
			printf("1\n");
		}
		else
		{
			printf("3\n");
		}
	}
	return 0;
}
