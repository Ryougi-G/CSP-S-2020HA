#include<bits/stdc++.h>
#define fint register int
#define N 500005//
#define H 13
using namespace std;
int Days,Months,Years;
int dat[14]={0,31,28,31,30,31,30,31,31,30,31,30,31};
inline int read();
inline void pd_BC(int x);
inline void pd_DCA(int x);
inline void pd_DCB(int x);
int main()
{
	freopen("julian.in","r",stdin);
	freopen("julian.out","w",stdout);
	int q;
	q=read();
	while(q--)
	{
		int n;
		cin>>n;
		if(n<=1721423)
		{
			pd_BC(n);
			cout<<Days<<" "<<Months<<" "<<Years<<" BC"<<endl;
		}
		else
		{
			n-=1721423;
			if(n<=577737)
			{
				pd_DCA(n);
				cout<<Days<<" "<<Months<<" "<<Years<<endl;
			}
			else
			{
				n-=577737;
				pd_DCB(n);
				cout<<Days<<" "<<Months<<" "<<Years<<endl;
			}
		}
	}
	return 0;
}

inline int read()
{
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')
		f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
	}
	return x*f;
}

inline void pd_BC(int x)
{
	int every_four=x/1461;
	x-=every_four*1461;
	int first_year=0,nxt_year=0;
	if(x>366)
	{
		x-=366,first_year=1;
		nxt_year=x/365;
		x-=nxt_year*365;
	}
	Years=4713-every_four*4-nxt_year-first_year;
	Months=1,Days=1;//
	int i=1;
	for(i=1;i<=12;i++)
	{
		if(i==2&&(Years-1)%4==0)
		{
			if(x<dat[i]+1)
			break;
			else
			x=x-dat[i]-1,Months++;
		}
		else
		{
			if(x<dat[i])
			break;
			else
			x-=dat[i],Months++;
		}
	}
	Days+=x;
	return ;
}

inline void pd_DCA(int x)
{
	x--;
	Years=1,Months=1,Days=1;
	int every_four=x/1461;
	x-=every_four*1461;
	int nxt_year=x/365;
	x-=nxt_year*365;
	Years+=every_four*4+nxt_year;//now year
	int i=1;
	for(i=1;i<=12;i++)
	{
		if(i==2&&(Years%4==0))
		{
			if(x<dat[i]+1)
			break;
			else
			x=x-dat[i]-1,Months++;
		}
		else
		{
			if(x<dat[i])
			break;
			else
			x-=dat[i],Months++;
		}
	}
	Days+=x;
	return ;
}

inline void pd_DCB(int x)
{
	x--;
	Years=1582,Months=10,Days=15;
	int every_fhzy=x/146097;
	x-=every_fhzy*146097;
	int every_four=x/1461;
	x-=every_four*1461;
	if(x>365)
	{
		x-=365,Years++;
		if(x>366)
		{
			x-=366,Years++;
			if(x>365)
			x-=365,Years++;
		}
	}
	Years+=every_fhzy*400+every_four*4;//ÕûÄê 
	if(x>=77)
	Years++,Months=1,x-=77,Days=1;
	else
	if(x>=46)
	Months=12,x-=46,Days=1;
	else
	if(x>=16)
	Months=11,x-=16,Days=1;
	int i=1;
	if(Months==1)
	for(i=1;i<=12;i++)
	{
		if(i==2&&((Years%4==0&&Years%100!=0)||(Years%400==0)))
		{
			if(x<dat[i]+1)
			break;
			else
			x=x-dat[i]-1,Months++;
		}
		else
		{
			if(x<dat[i])
			break;
			else
			x-=dat[i],Months++;
		}
	}
	Days+=x;
	return ;
}
