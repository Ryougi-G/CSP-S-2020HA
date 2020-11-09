#include<bits/stdc++.h>
#define ll long long int
using namespace std;

ll y[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
ll q,r,jyear=-4713,jmonth=1,jday=1,ayear,amonth,aday;
void PRINT();
void BC();
void B1582();
void A1582();
ll PR(ll);

void PRINT()
{
	bool bc=true;
	(ayear<0)?ayear=(-ayear):bc=false;
	printf("%lld %lld %lld",aday,amonth,ayear);
	if(bc)
		printf(" BC");
	putchar('\n');
}

void BC()
{
	ll ds;
	for(ll i=-4713;i<0;i++)
	{
		ds=(((-i)-1)%4==0)?366:365;
		if(r<ds)
		{
			ayear=i;
			break;
		}
		r-=ds;
	}
	if(ayear==0)
	{
		r-=365;
		return ;
	}
	y[2]=(ds==365)?28:29;
	for(ll i=1;i<=12;i++)
	{
		if(r<y[i])
		{
			amonth=i;
			break;
		}
		r-=y[i];
	}
	aday=r+1;
	r=0;
}

void B1582()
{
	ll ds;
	for(ll i=1;i<1582;i++)
	{
		ds=(i%4==0)?366:365;
		if(r<ds)
		{
			ayear=i+1;
			break;
		}
		r-=ds;
	}
	if(ayear==0)
	{
		r-=277;
		return ;
	}
	y[2]=(ds==365)?28:29;
	for(ll i=1;i<=12;i++)
	{
		if(r<y[i])
		{
			amonth=i;
			break;
		}
		r-=y[i];
	}
	aday=r+1;
	r=0;
}

void A1582()
{
	bool sign=true;
	r==78?ayear=1583,amonth=1,aday=1:sign=false;
	if(sign)
		return ;
	if(r<78)
	{
		if(r<17)
			ayear=1582,amonth=10,aday=15+r;
		else if(r==17)
			ayear=1582,amonth=11,aday=1;
		else
		{
			if(r<y[11])
				ayear=1582,amonth=11,aday=r;
			r-=y[11];
			ayear=1582,amonth=12,aday=r+1;
		}
		r=0;
		return ;
	}
	ll ds;
	r-=77;
	for(ll i=1583;r!=0;i++)
	{
		ds=PR(i);
		if(r>ds)
		{
			r-=ds;
			continue;
		}
		if(r==ds)
		{
			ayear=i+1,amonth=1,aday=1;
			r=0;
			return ;
		}
		ayear=i+1;
		for(ll j=1;j<=12;j++)
		{
			if(r<y[j])
			{
				amonth=j;
				break;
			}
			r-=y[j];
		}
		aday=r+1;
		r=0;
	}
}

ll PR(ll x)
{
	if((x%4==0)&&((x%100!=0)||(x%400==0)))
	{
		y[2]=29;
		return 366;
	}
	else
		return 365;
}

int main()
{
	freopen("julian.in","r",stdin);
	freopen("julian.out","w",stdout);
	scanf("%lld",&q);
	for(ll i=1;i<=q;i++)
	{
		scanf("%lld",&r);
		ayear=amonth=aday=0;
		BC();
		if(r==0)
		{
			PRINT();
			continue;
		}
		B1582();
		if(r==0)
		{
			PRINT();
			continue;
		}
		A1582();
		PRINT();
	}
	return 0;
}
