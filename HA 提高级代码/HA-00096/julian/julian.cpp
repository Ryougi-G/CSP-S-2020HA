#include<bits/stdc++.h>
using namespace std;
int ay,am,ad;
int ag;
int n, r;
int rgy,tt;
int yy[13]={0,31,29,31,30,31,30,31,31,30,31,30,31};
inline int lread()
{
	int x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9')
	{
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		x=x*10+c-'0';
		c=getchar();
	}
	return f*x;
}
int main()
{
	freopen("julian.in","r",stdin);
	freopen("julian.out","w",stdout);
	n=lread();
	for(int i=1;i<=n;i++)
	{
		r=lread();
		int rg;rgy=r;
		if(r<=365)
		{
			rg=r;ad=r+1;
			ay=4713;
			if(r==31||r==91||r==121||r==151||r==152||r==181||r==182||r==211||r==212||r==213||r==241||r==242||r==243||r==244||r==271||r==272||r==273||r==274||r==301||r==302||r==303||r==304||r==305||r==331||r==332||r==333||r==334||r==335)
			{
				am=-1;ag=-2;
			}
			else 
			{
				am=0;
				ag=-1;
			}
			while(rg>0)
			{
				am++;
				ag++;
				rg-=30;
			}
			if(am==13) am=12;
			if(am==0) am=1;
			for(int j=1;j<=am-1;j++)
			{
				ad-=yy[j];
			}
		}
		else
		{
			while(rgy>0)
			{
				tt++;
				rgy-=364;
			}	
			ay=4713-tt+1;
			rg=r-(tt-1)*364-(tt-1)/4-1;
			ad=rg;
			int rgg=rg;
			if(rg==31||rg==91||rg==121||rg==151||rg==152||rg==181||rg==182||rg==211||r==212||rg==213||rg==241||rg==242||rg==243||rg==244||rg==271||rg==272||rg==273||rg==274||rg==301||rg==302||rg==303||rg==304||rg==305||rg==331||rg==332||rg==333||rg==334||rg==335)
			{
				am=-1;ag=-2;
			}
			else 
			{
				am=0;
				ag=-1;
			}
			while(rgg>0)
			{
				am++;
				ag++;
				rgg-=30;
			}
			if(am==13) am=12;
			if(am==0) am=1;
			for(int j=1;j<=am-1;j++)
			{
				ad-=yy[j];
			}

		}
		printf("%d %d %d BC\n",ad,am,ay);
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
