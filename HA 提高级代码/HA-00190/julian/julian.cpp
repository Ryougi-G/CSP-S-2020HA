#include<bits/stdc++.h>
using namespace std;
int wyh()
{
	int x=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
	return f*x;
}
int pm[13]={0,31,28,31,30,31,30,31,31,30,31,30,31},
    rm[13]={0,31,29,31,30,31,30,31,31,30,31,30,31},
	ppm[13]={0,31,28,31,30,31,30,31,31,30,21,30,31};
int m,r,y=-4713,d;
int main()
{
	freopen("julian.in","r",stdin);
	freopen("julian.ans","w",stdout);
	int n;	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
	    r=wyh();
	    while(r)
	    {
	    	if(y%4!=-1&&y<=-1)
	    	{
	    		if(r>=365)
	    		{
	    			r=r-365;
	    			y++;		
	    		}
				else if(r<365)
	    		{
	    			for(int j=1;j<=12;j++)
	    			{
	    				r=r-pm[j];
	    				if(r<=0)
						{
							m=j;d=r+pm[j]+1;r=0;break;
						} 
	    			}
	    		}
	    	}
	    	if(y==-1)
	    	{
	    		if(r>=366)
	    		{
	    			r=r-366;
	    			y=y+2;
	    		}
	    		else if(r<366)
	    		{
	    			for(int j=1;j<=12;j++)
	    			{
	    				r=r-rm[j];
	    				if(r<=0)
						{
							m=j;d=r+rm[j]+1;r=0;break;
						} 
	    			}
	    		}
	    	}
	    	if(y%4==-1&&y<=-1)
	    	{
	    		if(r>=366)
	    		{
	    			r=r-366;
	    			y++;
	    		}
	    		else if(r<366)
	    		{
	    			for(int j=1;j<=12;j++)
	    			{
	    				r=r-rm[j];
	    				if(r<=0)
						{
							m=j;d=r+rm[j]+1;r=0;break;
						} 
	    			}
	    		}
	    	}
	    	if(y%4!=0&&y<1582&&y>=1)
	    	{
	    		if(r>=365)
	    		{
	    			r=r-365;
	    			y++;		
	    		}
				else if(r<365)
	    		{
	    			for(int j=1;j<=12;j++)
	    			{
	    				r=r-pm[j];
	    				if(r<=0)
						{
							m=j;d=r+pm[j]+1;r=0;break;
						} 
	    			}
	    		}
	    	}
	    	if(y%4==0&&y<1582&&y>=1)
	    	{
	    		if(r>=366)
	    		{
	    			r=r-366;
	    			y++;
	    		}
	    		else if(r<366)
	    		{
	    			for(int j=1;j<=12;j++)
	    			{
	    				r=r-rm[j];
	    				if(r<=0)
						{
							m=j;d=r+rm[j]+1;r=0;break;
						} 
	    			}
	    		}
	    	}
	    	if(y==1582)
	    	{
	    		if(r>=365)
	    		{
	    			r=r-365;
	    			y++;		
	    		}
				else if(r<365)
	    		{
	    			for(int j=1;j<=12;j++)
	    			{
	    				r=r-ppm[j];
	    				if(r<=0)
						{
							m=j;d=r+ppm[j]+1;r=0;break;
						} 
	    			}
	    		}
	    	}
	    	if((y%4!=0||y%100==0)&&y>1582)
	    	{
	    		if(r>=365)
	    		{
	    			r=r-365;
	    			y++;		
	    		}
				else if(r<365)
	    		{
	    			for(int j=1;j<=12;j++)
	    			{
	    				r=r-pm[j];
	    				if(r<=0)
						{
							m=j;d=r+pm[j]+1;r=0;break;
						} 
	    			}
	    		}
	    	}	
	    	if(y>1582&&((y%4==0&&y%100!=0)||r%400==0))
	    	{
	    		if(r>=366)
	    		{
	    			r=r-366;
	    			y++;
	    		}
	    		else if(r<366)
	    		{
	    			for(int j=1;j<=12;j++)
	    			{
	    				r=r-rm[j];
	    				if(r<=0)
						{
							m=j;d=r+rm[j]+1;r=0;break;
						} 
	    			}
	    		}
	    	}
	    }   	    
	    if(y<0)
	    printf("%d %d %d BC\n",d,m,-y);
	    else printf("%d %d %d\n",d,m,y);
	    y=-4713;
	}
	fclose(stdin);fclose(stdout);
}
