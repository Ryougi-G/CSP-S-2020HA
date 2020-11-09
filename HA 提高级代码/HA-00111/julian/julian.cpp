#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int read()
{
	int x=0,f=1; char ch=getchar();
	while(!isdigit(ch)) {if(ch=='-') f=-1; ch=getchar();}
	while(isdigit(ch)) {x=x*10+ch-'0'; ch=getchar();}
	return x*f;
}
int vis[15]={0,1,3,1,2,1,2,1,1,2,1,2,1};
int zq=365*3+366,be=4713;
int T,n,day,mon,yea;
void work2(int res,int flag,int i)
{
	if(yea>=1583&&flag==1) res+=10;
	if(res==0)
	{
		if(flag==-1) yea-=1;
		else yea+=1;
		return;
	}
	for(int j=1;j<=12;j++)
	{
		int y;
		if(vis[j]==1) y=31;
		else if(vis[j]==2) y=30;
		else if(vis[j]==3)
		{
			if(flag==-1&&(yea-1)%4==0) y=29;
			else if(flag==1&&(yea%400==0||(yea%4==0&&yea%100!=0))) y=29;
			else y=28;
		}
//		printf("%d\n",y);
		if(res-y>=0)
		{
			mon++; res-=y;
//			printf("%d\n",res);
			continue;
		}
		else if(res-y<0)
		{
			
			if(yea==1582) 
			{
				if(mon==10)
				{
					if(day+res>=5&&day+res<=14)
						day=day+res-5+15;
					else if(day+res<5)
						day+=res;
					else if(day+res+10>y)
					{
						res+=10;
						mon++;
						day=day+res-y;
					}
				}
				else if(mon>10)
				{
					res+=10;
					if(day+res>y)
					{
						mon++;
						if(mon==13) mon=1,yea++;
						day=day+res-y;
					}
				}
				else if(mon<10)
					day+=res;
			}
			else day+=res;
//			printf("%d\n",res);
			break;
		}
	}
}
void work1(int x,int flag)
{
//	printf("%d\n",yea);
	day=1;mon=1;
	int cha;
	for(int i=1;i<=4;i++)
	{
		if(flag==-1&&(yea-1)%4==0) cha=366;
		else if(flag==1&&(yea%400==0||(yea%4==0&&yea%100!=0))) cha=366;
		else cha=365;
//		printf("%d\n",cha);
		if(x-cha>0) 
		{
			x-=cha;
			if(flag==-1) yea--;
			else yea++;
			if(yea==0) yea=1,flag=1;
			continue;
		}
		int res=x;
		work2(res,flag,i);
		break;
	}
}
void work(int n)
{
	int flag,res=0;
	int z=n/zq;
	if(be-z*4>0)
	{
		int res=n-zq*z;
		yea=be-z*4; flag=-1;
//		printf("%d\n",yea);
		work1(res,flag);
		printf("%d %d %d BC\n",day,mon,yea);
	}
	else if(be-z*4<=0)
	{
		int res=n-zq*z;
		yea=abs(be-z*4-1); flag=1;
//		printf("%d\n",res);
		work1(res,flag);
		printf("%d %d %d\n",day,mon,yea);
	}
}
int main()
{
	freopen("julian.in","r",stdin);
	freopen("julian.out","w",stdout);
	T=read();
	while(T--)
	{
		n=read();
		work(n);
	}
	return 0;
}
