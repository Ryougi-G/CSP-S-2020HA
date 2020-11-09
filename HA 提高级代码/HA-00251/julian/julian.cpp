#include<bits/stdc++.h>
using namespace std;
int q[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
int n,y=-4713,mn=1,d=1;
inline int readint()
{
	int x=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-') f=-1;c=getchar();}
	while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
	return f*x;
}
int szabs(int x)
{
	return x>0?x:(-x-1);
}
bool chk(int x)
{
	if((x%4==0&&x%100!=0)||x%400==0) return 1;
	else return 0;
}
void sm(int m);
void smn(int m);
void sy(int m)
{
	while(1)
	{
	    if(y==0) y++;
		int qq=y;
		if(y==1582&&m>=355) {y++;m-=355;}
		else if((y>0&&!chk(y)&&m>=365)||(y<0&&(-y-1)%4!=0&&m>=365)) {y++,m-=365;}
	    else if((y>0&&chk(y)&&m>=366)||(y<0&&(-y-1)%4==0&&m>=366)) {y++,m-=366;}
		if(qq==y) break;
	}
	sm(m);
}
void sm(int m)
{
	for(int i=1;i<=12;++i)
	{
		int qq=mn;
		if(i==2)
		{
			if((y>0&&chk(y)&&m>=29)||(y<0&&(-y-1)%4==0&&m>=29)){m-=29;mn++;}
			else if((y>0&&!chk(y)&&m>=28)||(y<0&&(-y-1)%4!=0&&m>=28)){m-=28;mn++;}
		}
		else if(i==10&&y==1582&&m>=21){m-=21;mn++;}
		else if(m>=q[i]){m-=q[i];mn++;}
		if(mn==qq) break;
	}
	smn(m);
}
void smn(int m)
{
	if(y==1582&&mn==10&&m>=4) d=d+m+10;
	else d+=m;
}
int main()
{
	freopen("julian.in","r",stdin);
	freopen("julian.out","w",stdout);
	n=readint();
	for(int i=1;i<=n;++i)
	{
		int a;
		a=readint();
		sy(a);
		if(y<0) printf("%d %d %d BC\n",d,mn,-y);
		else printf("%d %d %d\n",d,mn,y);
		y=-4713,mn=1,d=1;
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
