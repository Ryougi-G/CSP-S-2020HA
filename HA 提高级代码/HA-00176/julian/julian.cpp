#include <bits/stdc++.h>
using namespace std;
int q,mon[15],n,yue,ri,yi,r;

void rll()
{
	mon[1]=31,mon[3]=31,mon[4]=30;mon[5]=31,mon[6]=30,mon[7]=31,mon[8]=31,mon[9]=30,mon[10]=31,mon[11]=30,mon[12]=31;
	if(n==0) n++;
	if(((n<0)&&((n-3)%4==0))||((n>0)&&(n<=1582)&&(n%4==0))||((n>1582)&&((n%4==0&&n%100!=0)||(n%400==0))))
	{
		mon[2]=29;
		yi=366;
	}
	else
	{
		mon[2]=28;
		yi=365;
	}
	if(n==1582)
	{
		yi-=10;
		mon[10]-=10;
	}
	if(r>yi)
	{
		r-=yi;
		n++;
		rll();
	}
	else  return;
}

int main()
{
	freopen("julian.in","r",stdin);
	freopen("julian.out","w",stdout);
	scanf("%d",&q);
	for(int i=1;i<=q;i++)
	{
		n=-4713,yue=1,ri=1;
		scanf("%d",&r);
		rll();
	    for(int j=1;j<=12;j++)
    	{
		    yue=j;
	    	if(r>mon[j])  r-=mon[j];
		    else break;
	    }
		ri=r+1;
		if((yue==10)&&(n==1582))
		{
			if(ri>4) ri+=10;
			if(ri>31)
			{
				yue++;
				ri-=31;
			}
		}
		if(n<0) printf("%d %d %d BC\n",ri,yue,n*-1);
		else printf("%d %d %d\n",ri,yue,n);
	}
	return 0;
}
