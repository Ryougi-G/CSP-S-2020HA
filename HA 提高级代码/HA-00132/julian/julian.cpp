#include<bits/stdc++.h>
using namespace std;
int n=0,Q=0;
inline int run(int x)
{
	if(x<0)
	{
		x=-1*x-1;
		if(x%4==0) return 366;
		else return 365;
	}
	if(x<1582)
	{
		if(x%4==0) return 366;
		else return 365;
	}
	if(x>1582)
	{
		if(x%400==0||(x%4==0&&x%100!=0)) return 366;
		else return 365;
	}
	if(x==1582) return 355;
}
int main()
{
	freopen("julian.in","r",stdin);
	freopen("julian.out","w",stdout);
	cin>>Q;
	while(Q--)
	{
		scanf("%d",&n);
		int day[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
		int d=1,m=1,y=-4713;
		while(n>=run(y))
		{
			n-=run(y);
			y++;
			if(y==0) y++;
		}
		if(run(y)==366) day[2]++;
		if(y==1582) day[10]-=10;
		if(n>=31)
		{
			while(n>=day[m])
			{
				n-=day[m];
				m++;
				if(n==0) n=1;
			}
		}
		if(n<31)
			n+=1;
		if(y==1582)
		{
			if(m==10)
			{
				if(n>=5)
					n+=10;
				if(n>=31) m++,n-=31;
				if(n==0) n=1;
			}
		}
		if(y>0)
			cout<<n<<" "<<m<<" "<<y<<endl;
		if(y<0)
			cout<<n<<" "<<m<<" "<<-1*y<<" BC"<<endl;
	}
	return 0;
}
