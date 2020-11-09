#include<bits/stdc++.h>
using namespace std;
long long q;
long long x;
inline long long read()
{
	long long re=1,ans=0;
	char x;
	while((x=getchar())<'0'||x>'9')
		if(x=='-')
			re=-1;
	ans=x-'0';
	while((x=getchar())>='0'&&x<='9')
		ans=(ans<<3)+(ans<<1)+x-'0';
	return re*ans;
}
long long cha1()
{
	if(x<=31)
		return 1;
	x-=31;
	if(x<=29)
	{
		return 2;
	}
	x-=29;
	if(x<=31)
	{
		return 3;
	}
	x-=31;
	if(x<=30)
	{
		return 4;
	}
	x-=30;
	if(x<=31)
	{
		return 5;
	}
	x-=31;
	if(x<=30)
	{
		return 6;
	}
	x-=30;
	if(x<=31)
	{
		return 7;
	}
	x-=31;
	if(x<=31)
	{
		return 8;
	}
	x-=31;
	if(x<=30)
	{
		return 9;
	}
	x-=30;
	if(x<=31)
	{
		return 10;
	}
	x-=31;
	if(x<=30)
	{
		return 11;
	}
	x-=30;
	if(x<=31)
	{
		return 12;
	}
}
long long cha2()
{
	if(x<=31)
		return 1;
	x-=31;
	if(x<=28)
	{
		return 2;
	}
	x-=28;
	if(x<=31)
	{
		return 3;
	}
	x-=31;
	if(x<=30)
	{
		return 4;
	}
	x-=30;
	if(x<=31)
	{
		return 5;
	}
	x-=31;
	if(x<=30)
	{
		return 6;
	}
	x-=30;
	if(x<=31)
	{
		return 7;
	}
	x-=31;
	if(x<=31)
	{
		return 8;
	}
	x-=31;
	if(x<=30)
	{
		return 9;
	}
	x-=30;
	if(x<=31)
	{
		return 10;
	}
	x-=31;
	if(x<=30)
	{
		return 11;
	}
	x-=30;
	if(x<=31)
	{
		return 12;
	}
}
int main()
{
	freopen("julian.in","r",stdin);
	freopen("julian.out","w",stdout);
	q=read();
	for(int i=1;i<=q;i++)
	{
		x=read();
		long long yu=0,ni=0;
		if(x<=1721423)
		{
			ni=x/1461;
			ni*=4;
			x%=1461;
			x++;
			if(x<=0)
				x=x;
			else if(x<=366)
			{
				ni+=1;
				x%=366;
			}
			else
			{
				x-=366;
				if(x%365==0)
					ni+=x/365+1;
				else
				 	ni+=x/365+2;
				x%=365;
			}
			ni=4713-ni+1;
			if((ni-1)%4==0)
				yu=cha1();
			else 
				yu=cha2();
			cout<<x<<" "<<yu<<" "<<ni<<" BC"<<endl; 
		}
		else
		{
			x-=1721423;
			if(x==1)
				cout<<"1 1 1"<<endl;
			if(x<=577460)
			{
				cout<<x<<endl;
				ni=x/1461;
				ni*=4;
				x%=1461;
				if(x==0)
					x++;
				else if(x<=1095)
				{
					if(x%365==0)
						ni+=x/365;
					else
					 	ni+=x/365+1;
					x%=365;
				}
				else
				{
					x-=1095;
					ni+=4;
				}
				if(ni%4==0)
					yu=cha1();
				else 
					yu=cha2();
				cout<<x<<" "<<yu<<" "<<ni<<endl;
			}
			else
			{
				int q=1582;
				x-=577460;
				if(x>=278)
				x+=10;
				ni=x/146097;
				ni*=400;
				x%=146097;
				q+=ni;
				if(x==0)
					x++;
				while(x>365)
				{
					if(((q)%400==0)||((q)%4==0&&(q)%100!=0))
					{
						if(x<=366)
						{
							break;
						}
					}
					q++;
					if((q%400==0)||(q%4==0&&q%100!=0))
						x-=366;
					else
					{
						x-=365;
					}
				}
				if((q%400==0)||(q%4==0&&q%100!=0))
					x++,yu=cha1();
				else 
					yu=cha2();
				cout<<x<<" "<<yu<<" "<<q<<endl;
			}
		}
	}
	return 0;
}
