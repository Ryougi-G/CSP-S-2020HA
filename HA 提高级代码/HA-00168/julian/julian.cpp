#include<bits/stdc++.h>
using namespace std;
const int a[15]={0,31,28,31,30,31,30,31,31,30,31,30,31};
int t,y,r,k;

bool rn()
{
	if(y<1582)
	{
		if(y%4) return 0;
		else return 1;
	}
	if(y%4==0&&(y%100||y%400==0))
		return 1;
	else return 0;
}

int main()
{
	freopen("julian.in","r",stdin);
	freopen("julian.out","w",stdout);
	scanf("%d",&t);
	while(t--)
	{
		y=-4712;
		scanf("%d",&r);
		if(r>=1461)//4年1闰
		{
			k=min(r/1461,1573);
			y+=k*4;
			r-=k*1461;
		}
		if(y==1580&&r>1007)
			r+=10;//跳过10天
		if(r>=146097)//每400年
		{
			y+=(r/146097)*400;
			r%=146097;
		}
		for(;r>=365;y++)
		{
			if(rn())//闰年
			{
				if(r==365)
				{
					if(y<=0) printf("31 12 %d BC\n",1-y);
					else printf("31 12 %d\n",y);
					break;
				}
				else r-=366;
			}
			else r-=365;
		}
		if(r!=365)
			for(int i=1;i<=12;i++)
				if(i==2&&rn())//闰年2月
				{
					if(r>=29) r-=29;
					else
					{
						if(y<=0) printf("%d 2 %d BC\n",r+1,1-y);
						else printf("%d 2 %d\n",r+1,y);
						break;
					}
				}
				else
				{
					if(r>=a[i]) r-=a[i];
					else
					{
						if(y<=0) printf("%d %d %d BC\n",r+1,i,1-y);
						else printf("%d %d %d\n",r+1,i,y);
						break;
					}
				}
	}
	return 0;
}

