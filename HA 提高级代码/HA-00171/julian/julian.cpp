#include<bits/stdc++.h>
using namespace std;
int r,q;
//         0 1  2  3  4   5   6   7   8   9   10  11 12
int m[13]={0,31,59,90,120,151,181,212,243,273,304,334,365},n;//月份，前缀和，无闰月 
int main()
{
	freopen("julian.in","r",stdin);
	freopen("julian.out","w",stdout);
	long i,j,x,y,z,leap=0;//day,month,year
	cin>>q;
	for(i=1;i<=q;i++)
	{
		cin>>r;
		r++;
		leap=0;
		if(r*4/(365*4+1.0)-4713<0)//B.C.
		{
			z=4713-r*4/(365*4+1);
			x=r%(365*4+1);
			if(z%4==1)
			{
				leap=1;
			}
			x=(x-1)%365+1;
			for(j=1;j<=12;j++)
			{
				if(x<(m[j]+(j>2)*leap))
				{
					y=j;
					break;
				}
			}
			if(y>2&&leap||!leap)
				x=x-(m[y-1]+1);
				else
			x=x-m[y-1];
			printf("%d %d %d BC\n",x,y,z);
		}
		else
		{
			r=r-4712*(365*4+1)/4;
			z=r*4/(365*4+1);
			if(z<=1582||z==1582&&r%(365*4+1)%356<=m[10]+4)
			{
				if(z%4==0)
				{
					leap=1;
				}
				x=r%(365*4+1)%365;
				for(j=1;j<=12;j++)
				{
					if(x<(m[j]+(j>2)*leap))
					{
						y=j;
						break;
					}
				}
				if(y>2&&leap||!leap)
					x=x-(m[y-1]+1);
				else
					x=x-m[y-1];
				printf("%d %d %d\n",x,y,z);
			}
			else
			{
				r+=10;
				r-=1582*(365*4+1)/4;
				x=r;
				x=x%(365*400+97)%(365*100+24)%(365*4+1)%365;
				z=r*400/(365*400+97)+1582;
				if(z%4==0&&z%100!=0||z%400==0)
				{
					leap=1;
				}	
//				x=x*400%(365*400+24)
				for(j=1;j<=12;j++)
				{
					if(x<(m[j]+(j>2)*leap))
					{
						y=j;
						break;
					}
				}
				if(y>2&&leap||!leap)
					x=x-(m[y-1]+1);
				else
				{
					x=x-m[y-1];
				}
				printf("%d %d %d\n",x,y,z); 
//				cout<<leap<<endl;
			}
		}
	}
	return 0;
}
