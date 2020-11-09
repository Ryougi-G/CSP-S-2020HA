#include<bits/stdc++.h>
using namespace std;
long long p,l,y,r,m;
void month()
{
	for(;;)
		{
			m++;
			if(m<=7)
			{
				if(m%2==1)
				{
					if(l>=31)
					{
						l=l-31;
					}else break;					
				}else
				{
					if(m!=2)
					{
						if(l>=30)
					{
						l=l-30;
					}else break;					
					}else
					{
						if(r==4)
						{
							if(l>=29)
					{
						l=l-29;
					}else break;
						}else
						{
							if(l>=28)
					{
						l=l-28;
					}else break;
						}						
					}
				}
			}else
			{
				if(m%2==1)
				{
					if(l>=30)
					{
						l=l-30;
					}else break;	
				}else
				{
					if(l>=31)
					{
						l=l-31;
					}else break;	
				}
			}
		}
}
int main(){
freopen("julian.in","r",stdin);
freopen("julian.out","w",stdout);
cin>>p;
for(int q=1;q<=p;q++)
{
	scanf("%lld",&l);
	y=0;r=4;m=0;
	if(l<=365*4713+1178)
	{
		for(;;)
		{
			if(r==4)
			{
				if(l>=366)
				{
					y++;l=l-366;r=0;
				}
				else
				break;
			}else
			{
				if(l>=365)
				{
					y++;l=l-365;r++;
				}else
				break;
			}
		}
		month();
		printf("%lld %lld %lld BC\n",l+1,m,4713-y);
	}
}
return 0;
}
