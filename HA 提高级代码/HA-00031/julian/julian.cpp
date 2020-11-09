
#include<bits/stdc++.h>
using namespace std;
long long a,b,c,x,y[1001],z;
int main()
{
	freopen("julian.in","r",stdin);
	freopen("julian.out","w",stdout);
	scanf("%d",&x);
	for(int i=0;i<=x-1;i++)
	{
		scanf("%d",&y[i]);
	}
	for(int i=0;i<=x-1;i++)
	{
		z=y[i]/1461;
		a=y[i]-(z*1461);
		b=a/365;
		a=a-(b*365);
		c=a/31;
		if(b==3)
		{
			if(c==1)a-=31;
			if(c==2)a-=60;
			if(c==3)a-=91;
			if(c==4)a-=121;
			if(c==5)a-=152;
			if(c==6)a-=182;
			if(c==7)a-=213;
			if(c==8)a-=244;
			if(c==9)a-=274;
			if(c==10)a-=305;
			if(c==11)a-=335;
		}
		else
		{
			if(c==1)a-=31;
			if(c==2)a-=59;
			if(c==3)a-=90;
			if(c==4)a-=120;
			if(c==5)a-=151;
			if(c==6)a-=181;
			if(c==7)a-=212;
			if(c==8)a-=243;
			if(c==9)a-=273;
			if(c==10)a-=304;
			if(c==11)a-=334;
		}
		if(b+(z*4)-4713<1){printf("%d ",a);printf("%d ",c+1);printf("%d BC\n",(b+(z*4)-4713)*-1);}
		else {printf("%d ",a+1);printf("%d ",c+1);printf("%d\n",b+(z*4)-4713+1);}
	}
	return 0;
}
