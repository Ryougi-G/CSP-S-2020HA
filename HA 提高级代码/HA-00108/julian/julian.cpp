#include<bits/stdc++.h>
using namespace std;
template<typename T>
inline void read(T &x)
{
	int f=1;x=0;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-') f=-1;ch=getchar();}
	while(isdigit(ch)){x=x*10+ch-'0';ch=getchar();}x*=f;
}
const int rmonth[13]={0,31,29,31,30,31,30,31,31,30,31,30,31};
const int brmonth[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
int Q,ansyear,ansmonth,ansday;

bool check(int year)
{
	if(year<1583)
	{
		if(year<0)
		{
			if((year+1)%4==0) return 1;
			else return 0;
		}
		else if(year>0)
		{
			if(year%4==0) return 1;
			else return 0;
		} 
		else return 0;		
	}
	else
	{
		if((year%400)==0) return 1;
		else if(((year%4)==0)&&((year%100)!=0)) return 1;
		else return 0;		
	}
}

int cal(int now)
{
	if(check(now)) return 366;
	else return 365;
}

int calc()
{
	ansyear=-4713;ansday++;ansmonth=1;
	while(ansday>cal(ansyear))
	{
		ansday-=cal(ansyear);
		ansyear++;
		if(!ansyear) ansyear++;		
	}
	if(ansyear>1582) ansday+=10;
	if(check(ansyear))
	{
		while(ansday>rmonth[ansmonth])
		{
			ansday-=rmonth[ansmonth];
			ansmonth++;
		}
	}
	else
	{
		while(ansday>brmonth[ansmonth])
		{
			ansday-=brmonth[ansmonth];
			ansmonth++;
		}
	}
}

int main()
{
	freopen("julian.in","r",stdin);
	freopen("julian.out","w",stdout);
	read(Q);
	while(Q--)
	{
		read(ansday);calc();
		printf("%d %d %d",ansday,ansmonth,abs(ansyear));
		if(ansyear<0) printf(" BC");puts("");
	}
	return 0;
}
