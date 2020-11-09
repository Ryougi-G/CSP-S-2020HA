#include<bits/stdc++.h>
using namespace std;
unsigned long long x;
int q,m[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
int day,mon,yea,flag,v,vvv;
bool check()
{
	if(vvv) return 1;
	else return yea%400==0||yea%100!=0;
}
void deay1()
{
	if(!x) return;
	while(x>=365250)
	{
		yea=yea+flag*1000;
		x-=365250;
	}
	while(x>=36525)
	{
		x-=36525;
		yea=yea+flag*100;
	}
	while(x>=7305)
	{
		x-=7305;
		yea=yea+flag*20;
	}
	while(x>=2922)
	{
		x-=2922;
		yea=yea+flag*8;
	}
	while(x>=366)
	{
		if((yea-1)%4==0)
		{
			x-=366;
			yea+=flag;
		}
		else
		{
			x-=365;
			yea+=flag;
		}
	}
	if(x==365&&(yea-1)%4!=0) yea+=flag,x=0;
}
void deay2()
{
	if(x==0) return;
	while(x>=36524250)
	{
		x-=36524250;
		yea+=100000;
	}
	while(x>=3652425)
	//while(x>=3652400)
	{
		x-=3652425;
		yea+=10000;
	}
	while(x>=365243)
	//while(x>=365240)
	{
		x-=365243;
		yea+=1000;
	}
	while(x>=36525)
	{
		x-=36525;
		yea+=100;
	}
	while(x>=7305)
	{
		x-=7305;
		yea+=20;
	}
	while(x>=2922)
	{
		x-=2922;
		yea+=8;
	}
	while(x>=366)
	{
		if(yea%4==0&&check())
		{
			x-=366;
			yea++;
		}
		else{
			x-=365;
			yea++;
		}
	}
	if(!(yea%4==0&&check())&&x==365) yea++,x-=365;
}
void deal1()
{
	if(mon==2&&(yea+v)%4==0&&check())
	{
		if(x>29)
		{
			x-=29;
			mon++;
			deal1();
		}
	}
	else {
		if(x>m[mon])
		{
			x-=m[mon];
			mon++;
			deal1();
		} 
	}
}
void deam1()
{
	if(!x) return;
	x+=1,day=0;
	deal1();
	day=x;
}
int main()
{
	freopen("julian.in","r",stdin);
	freopen("julian.out","w",stdout);
	scanf("%d",&q);
	while(q--)
	{
		scanf("%ulld",&x);
		day=1,mon=1,yea=4713;
		flag=-1,v=-1,vvv=1;
		if(x<1721423)
		{
			deay1();
			deam1();
			printf("%d %d %d BC",day,mon,yea);
		}
		else
		{
			x-=1721423;
			yea=1,flag=1,v=0;
			if(x<=578132)
			{
				deay1();
				deam1();
				printf("%d %d %d",day,mon,yea);
			}
			else
			{
				x+=10;
				vvv=0;
				deay2();
				deam1();
				printf("%d %d %d",day,mon,yea);
			}
		}
	}
	return 0;
}
