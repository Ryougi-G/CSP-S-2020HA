#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int bc=1721423,ru=577737;
int a[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
int b[13]={0,31,29,31,30,31,30,31,31,30,31,30,31};
int main()
{
    freopen("julian.in","r",stdin);
	freopen("julian.out","w",stdout);
	long long int nn,n,ans,ye,mo,da,ji;
	bool BC=true,ge=true;
	scanf("%lld",&nn);
	for(int i=1;i<=nn;i++)
	{
		ye=0;
		mo=0;
		da=0;
		ji=0;
		scanf("%lld",&n);
		if(n<=bc)
		{
			BC=true;
		}
		else
		{
			BC=false;
		}
		if(n>bc+ru)
		{
			ge=true;
		}
		else
		{
			ge=false;
		}
		if(1)
		{
			n=n+1;
			if(ge)
			{
				n=n+10;
			}
			ye=n/(365*3+366);
			n=n-ye*(365*3+366);
			ye=ye*4;
			bool rrr=false;
			
			if(n>366)
			{
				n=n-366;
				ye++;
				ye=ye+n/365;
				n=n%365;
				rrr=true;
				if(n==0)
				{
					mo=12;
					da=31;
					ye--;
				}
			}
			
			if(ge)
			{
				long long int gg=ye-6313;
				if(gg>0)
				{
					n=n+gg/100-gg/400;
				}
			}
			if(n==366)
			{
				mo=12;
				da=31;
				if(n%100==0&&n%400!=0)
				{
					ye++;
					mo=1;
					da=1;
				}
			}
			else if(n!=0)
			{
			if(rrr)
			{
				ji=0;
				for(int i=1;i<=12;i++)
				{
					ji+=a[i];
					if(ji>n)
					{
						ji=ji-a[i];
						mo=i;
						n=n-ji;
						da=n;
						break;
					}
				}
				if(ye>4713)
				{
					ye=ye-4713;
				}
				else
				{
					ye=4713-ye;
					if(ye==0)
					{
						ye=0;
					}
				}
			}
			else
			{
				ji=0;
				for(int i=1;i<=12;i++)
				{
					ji+=b[i];
					if(ji>n)
					{
						ji=ji-b[i];
						mo=i;
						n=n-ji;
						da=n;
						break;
					}
				}
				if(ye>4713)
				{
					ye=ye-4713;
				}
				else
				{
					ye=4713-ye;
					if(ye==0)
					{
						ye=0;
					}
				}
			}
			}
		}
			if(!BC)
		{
			ye++;
		}
		cout<<da<<" "<<mo<<" "<<ye;
		if(BC)
		{
			cout<<" "<<"BC"<<endl;
		}
		else
		{
			cout<<endl;
		}
	}
}
