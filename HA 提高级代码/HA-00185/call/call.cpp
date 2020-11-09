#include<bits/stdc++.h>
using namespace std;
int a[100010];
void szone(int x,int y)
{
	a[x]+=y;
}
void sztwo(int x)
{
	for(int i=1;i<=n;++i)
	{
		a[i]*=x;
	}
}
int dd[100010][100];
int dis[100010][4];
int main()
{
	freopen("call.in","r",stdin);
	freopen("call.out","w",stdout);
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;++i)
    {
    	scanf("%d",a[i]);
    }
    int m;
    scanf("%d",&m);
    for(int i=1;i<=m;++i)
    {
    	scanf("%d",&dis[i][1]);
    	if(dis[i][1]==1)
    	{
    		int k;
    		scanf("%d%d",&dis[i][2],&dis[i][3]);
    	}else if(dis[i][1]==2)
    	{
    		int k;
    		scanf("%d",&dis[i][2]);
    	}else
    	{
    		int k;
    		scanf("%d",&dis[i][2]);
    		for(int j=1;j<=dis[i][2];++j)
    		{
    			scanf("%d",&dd[i][j]);
    		}
    	}
    	int q,p;
    	scanf("%d",&q);
    	for(int i=1;i<=n;++i)
    	{
    		scanf("%d",&p);
    		if(p==1)
    		{
    			for(int j=1;j<=m;++j)
    			{
    				if(dis[j][1]==1)
    				{
    					szone(dis[j][2],dis[j][3]);
    				}
    			
    			}
    		}else if(p==2)
    		{
    			for(int j=1;j<=m;++j)
    			{
    				if(dis[j][1]==2)
    				{
    					sztwo(dis[j][2]);
    				}
    			
    			}
    		}else
    		{
    			for(int j=1;j<=m;++j)
    			{
    				if(dis[j][1]==3)
    				{
    				    for(int k=1;k<=dis[j][2];++k)
    				    {
    				    
    				    }
    				}
    			
    			}
    		}
    		
    	}
    	
    }
    for(int i=1;i<=n;++i)
    {
    	printf("%d ",a[i]);
    }
	return 0;
	fclose(stdin);
	fclose(stdout);
}
