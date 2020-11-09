#include<bits/stdc++.h>
using namespace std;
int fmoth[14]={0,31,28,31,30,31,30,31,31,30,31,30,31};
int smoth[14]={0,31,29,31,30,31,30,31,31,30,31,30,31};
long long a[1003];
long long  ye[1003];
int  da[1003];
int  mo[1003];
int q;
int main()
{
	freopen("julian.in","r",stdin);
	freopen("julian.out","w",stdout);
	cin>>q;
	for(int i=1;i<=q;i++)
	{
		cin>>a[i];
		a[i]=a[i]+1;
		ye[i]=-4712;
		da[i]=1;
		mo[i]=1;
	}
	for(int i=1;i<=q;i++)
	{
		int e=0,r=4;
		while(a[i]>366)
		{
			e++;
			if((e%4==0&&e<5594)||((((e-4712)%400==0)||((e-4712)%4==0&&(e-4712)%100!=0))&&e>=5595))
			{
				if(a[i]-366>=0)
				{
			    	a[i]=a[i]-366;
			    	ye[i]++;
			    }
			    else
			    {
			    	r=4;
			    	break;
			    }
			}
			else
			{
				if(a[i]-365>=0)
				{
			    	a[i]=a[i]-365;
			    	ye[i]++;
			    }
			    else
			    {
			    	r=3;
			    	break;
			    }
			}
		}
		if(e>=5595)
		{
			a[i]=a[i]+4;
		}
		for(int l=1;l<=12;l++)
		{
			if(r==4)
			{
				if(a[i]>smoth[l])
				{
					a[i]=a[i]-smoth[l];
					mo[i]++;
				}
				else
				{
					break;
				}
			}
			else
			{
				if(a[i]>fmoth[l])
				{
					a[i]=a[i]-fmoth[l];
					mo[i]++;
				}
				else
				{
					break;
				}
			}
		}
		if(a[i]>0)
		{
			da[i]=a[i];
		}
	}
	for(int i=1;i<=q;i++)
	{
		cout<<da[i]<<" "<<mo[i]<<" ";
		if(ye[i]<=0) 
		{
			cout<<-ye[i]+1<<" "<<"BC"<<endl;
		}
		else
		{
			cout<<ye[i]<<endl;
		}
	}
	return 0;
}
