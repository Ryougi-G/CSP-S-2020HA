#include<bits/stdc++.h>
using namespace std;
struct node
{
	int bianhao,tili,yuantili;
}a[1000010];
int main()
{
	freopen("snakes.in","r",stdin);
	freopen("snakes.out","w",stdout);
    int t,n;
    scanf("%d",&t);
	scanf("%d",&n);
	int ans=n;
    for(int j=1;j<=n;++j)
    {
    	scanf("%d",&a[j].yuantili);
    	a[j].tili=a[j].yuantili;
    	a[j].bianhao=j;
   } 	
   int p=1;
   for(int c=n;c-1>p;--c)
    	{
    		if(a[c].tili-a[p].tili>=a[c-1].tili)
    		for(int i=p;i<=c;++i)
   	        {
   	    	  if(a[c].tili-a[i].tili>=a[c-1].tili)
    	    	{
    	    	--ans;
    	      	a[c].tili-=a[i].tili;
		        p=i;
		    	}
           }
    	}
    printf("%d\n",ans);
    for(int i=1;i<=n;++i)
    {
    	a[i].tili=a[i].yuantili;
    }
    int nn;
    for(int i=2;i<=t;++i)
    {
    	scanf("%d",&nn);
    	for(int j=1;j<=nn;++j)
    	{
    	int x,y;
    	scanf("%d%d",&x,&y);
    	a[x].tili=y;
    	}
    	p=1;
    	ans=n;
    	for(int c=n;c-1>p;--c)
    	{
    		if(a[c].tili-a[p].tili>=a[c-1].tili)
    		for(int i=p;i<=c;++i)
   	        {
   	    	  if(a[c].tili-a[i].tili>=a[c-1].tili)
    	    	{
    	    	--ans;
    	      	a[c].tili-=a[i].tili;
		        p=i;
		    	}
           }
    	}
        printf("%d",ans);
    }
	return 0;
	fclose(stdin);
	fclose(stdout);
}
