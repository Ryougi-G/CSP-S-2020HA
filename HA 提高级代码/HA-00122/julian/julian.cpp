#include<bits/stdc++.h>
using namespace std;
int n;
const int N=10001;
int r[N];
bool pd2(int x)
{
	if((x%400==0)||(x%4==0&&(x%100!=0)))	return 1;
	else return 0;
}
bool pd1(int x)
{
	if(x>=1)	
	{
		if(x%4==0)	return 1;
		else return 0;
	}
	if(x<=-1)
	{
		if(abs(x+1)%4==0)	return 1;
		else return 0;
	}
}
int a[13];
int y=0;int m=0;int d=0;
int dfs(int t,int pp)
{
	for(register int i=-4713;i<=300000;i++)
	{
		if(i!=0)
		{
			for(register int j=1;j<=12;j++)
			{
				a[1]=31;a[3]=31;a[4]=30;a[5]=31;a[6]=30;a[7]=31;a[8]=31;a[9]=30;a[10]=31;a[11]=30;a[12]=31;
				if(i<=1582)	
				{
					if(pd1(i))	a[2]=29;
					else a[2]=28;
				}
				if(i>1582)
				{
					if(pd2(i))	a[2]=29;
					else a[2]=28;
				}
				for(register int k=1;k<=a[j];k++)
				{
					if(i==1582&&j==10&&k>=5&&k<=14)
					{
						t+=0;
					}
					else
					{
						t+=1;
						if(t==pp)
						{
							if(i<=-1)
							{
								cout<<k<<" "<<j<<" "<<abs(i)<<" "<<"BC"<<endl;
							}
							if(i>=1)
							{
								cout<<k<<" "<<j<<" "<<abs(i)<<" "<<endl;						
							}
							break;
						}
					}
				}
			}
		}
	}
}	
int main()
{
	freopen("julian.in","r",stdin);
	freopen("julian.out","w",stdout);
	scanf("%d",&n);
	for(register int i=1;i<=n;++i)
	{
		scanf("%d",&r[i]);
	}
	for(register int i=1;i<=n;++i)
	{
		dfs(-1,r[i]);
	}
}
