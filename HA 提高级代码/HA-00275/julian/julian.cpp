#include<iostream>
#include<cstdio>
using namespace std;
const int fjx=1721424,glg=577725;
int q,r,mo[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
bool pd(int x)
{
	if(x%400==0||((x%4==0)&&!(x%100==0)))
	{
		return true;
	}else
	{
		return false;
	}
}
int main()
{
	freopen("julian.in","r",stdin);
	freopen("julian.out","w",stdout);
	scanf("%d",&q);
	while(q--)
	{
		scanf("%d",&r);
		r++;//要加上边界的第一天 
		int r1,js=0,m,d,year;
		if(r<=fjx)//第一个 
		{
		r1=r;
		while(r1>=367)
		{
			if(js%4==0)
			{
				r1=r1-366;
			}else
			{
				r1=r1-365;
			}
			js++;
			if(r1==366&&(4713-js)%4!=1)
			{
				r1=1;
				js++;
			}
		}
		year=4713-js;
		if(year%4==1)
		{
			mo[2]=29;
		}else
		{
			mo[2]=28;
		}
		for(int i=1;i<=12;i++)
		{
			if(r1<=mo[i])
			{
				m=i;d=r1;break;
			}
			r1=r1-mo[i];
		}
		printf("%d %d %d BC\n",d,m,year);
		continue;
		}
		else
		{
			r1=r-fjx;
			js=1;
			if(r1<=glg)//第二个情况 
			{
				if(r1==366)
				{
					js++;
					r1=1;
				}
				while(r1>=367)
				{
					if(js%4==0)
				{
					r1=r1-366;
				}else
				{
					r1=r1-365;
				}
					js++;
			       if(r1==366&&js%4!=0)
			       {
				       r1=1;
				       js++;
			       }
		        }
		        if(js%4==0)
		        {
		        	mo[2]=29;
		        }else
		        {
		        	mo[2]=28;
		        }
		        for(int i=1;i<=12;i++)
				{
					if(r1<=mo[i])
					{
						m=i;d=r1;break;
					}
					r1=r1-mo[i];
				}
				printf("%d %d %d\n",d,m,js);
				continue;
			}
			else//第三个情况 
			{
				r1=r-fjx-glg-10;
				if(r1<=78)
				{
					if(r1<=17)
					{
						d=14+r1;m=10;year=1582;
						printf("%d %d %d\n",d,m,year);
					}else
					{
						r1=r1-17;year=1582;
						for(int i=11;i<=12;i++)
						{
							if(r1<=mo[i])
							{
								d=r1;m=i;break;
							}
							r1=r1-mo[i];
						}
						printf("%d %d %d\n",d,m,year);
						continue;
					}
				}else//第4个 
				{
					r1=r-fjx-glg-90;
					js=1583;
					if(r1<=366)
					{
						js++;
						r1=1;
					}
					while(r1>=367)
				{
					if(pd(js))
				{
					r1=r1-366;
				}else
				{
					r1=r1-365;
				}
					js++;
			       if(r1==366&&!pd(js))
			       {
				       r1=1;
				       js++;
			       }
		        }
		        if(pd(js))
		        {
		        	mo[2]=29;
		        }else
		        {
		        	mo[2]=28;
		        }
		        for(int i=1;i<=12;i++)
				{
					if(r1<=mo[i])
					{
						m=i;d=r1;break;
					}
					r1=r1-mo[i];
				}
				printf("%d %d %d\n",d,m,js);
				continue;
				}
			}
		}
	}
	return 0;
}
