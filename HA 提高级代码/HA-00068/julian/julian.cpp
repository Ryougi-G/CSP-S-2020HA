#include<bits/stdc++.h>
#define int unsigned long long
using namespace std;
namespace IO
{
	char ss[1<<17|1],*A,*B;
	char Getchar()
	{
		if(A==B)
		{
			B=(A=ss)+fread(ss,1,1<<17,stdin);
			if(A==B) return EOF;
		}
		return *A++;
	}
	template<class T> void read(T& x)
	{
		x=0; bool flag=false; char ch=Getchar();
		while(ch<'0'||ch>'9') {flag|=(ch=='-'); ch=Getchar();}
		while(ch>='0'&&ch<='9') {x=(x<<1)+(x<<3)+(ch^48); ch=Getchar();}
		if(flag) x=-x;
	}
}
int read();
int Q;
int DAY;
int month1[]={0,31,28,31,30,31,30,31,31,30,31,30,31,0,0};
int month2[]={0,31,29,31,30,31,30,31,31,30,31,30,31,0,0};
signed main()
{
	freopen("julian.in","r",stdin);
	freopen("julian.out","w",stdout);
	Q=read();
	for(int i=1;i<=Q;i++)
	{
		DAY=read();
		if(DAY<1721423)
		{
			int FOUR_YEAR=DAY/1461;
			DAY=DAY-1461*FOUR_YEAR;
			int YEAR=DAY/365;
			DAY=DAY-YEAR*365;
			int ANS_YEAR=4713-FOUR_YEAR*4-YEAR;
			if(YEAR!=0)
			{
				bool flag=true; int ANS_MONTH=1;
				while(flag)
				{
					if(DAY>month1[ANS_MONTH])
					{
						DAY-=month1[ANS_MONTH]; ANS_MONTH++; continue;
					}
					else if(DAY==month1[ANS_MONTH])
					{
						DAY=month1[ANS_MONTH]; flag=false; continue;
					}
					else 
					{
						flag=false; continue;
					}
				}
				cout<<DAY<<" "<<ANS_MONTH<<" "<<ANS_YEAR<<" BC"<<endl; continue;
			}
			else 
			{
				bool flag=true; int ANS_MONTH=1;
				while(flag)
				{
					if(DAY>month2[ANS_MONTH])
					{
						DAY-=month2[ANS_MONTH]; ANS_MONTH++; continue;
					}
					else if(DAY==month2[ANS_MONTH])
					{
						DAY=month2[ANS_MONTH]; flag=false; continue;
					}
					else 
					{
						flag=false; continue;
					}
				}
				if(ANS_YEAR==4713)
				cout<<DAY+1<<" "<<ANS_MONTH<<" "<<ANS_YEAR<<" BC"<<endl;
				else cout<<DAY<<" "<<ANS_MONTH<<" "<<ANS_YEAR<<" BC"<<endl;continue;
			}
		}
		else
		{
			DAY-=1721423;
			if(DAY==0) {cout<<"1 1 1"<<endl; continue;}
			int FOUR_YEAR=DAY/1461;
			DAY=DAY-1461*FOUR_YEAR;
			int YEAR=DAY/365;
			DAY=DAY-YEAR*365;
			int ANS_YEAR=FOUR_YEAR*4+YEAR;
			if(YEAR!=0)
			{
				bool flag=true; int ANS_MONTH=1;
				while(flag)
				{
					if(DAY>month1[ANS_MONTH])
					{
						DAY-=month1[ANS_MONTH]; ANS_MONTH++; continue;
					}
					else if(DAY==month1[ANS_MONTH])
					{
						DAY=month1[ANS_MONTH];
						flag=false; continue;
					}
					else {
						flag=false; continue;
					}
				}
				cout<<DAY<<" "<<ANS_MONTH<<" "<<ANS_YEAR+1<<endl; continue;
			}
			else 
			{
				bool flag=true; int ANS_MONTH=1;
				while(flag)
				{
					if(DAY>month2[ANS_MONTH])
					{
						DAY-=month2[ANS_MONTH]; ANS_MONTH++; continue;
					}
					else if(DAY==month2[ANS_MONTH])
					{
						DAY=month2[ANS_MONTH];
						flag=false; continue;
					}
					else
					{
						flag=false; continue;
					}
				}
				if(ANS_YEAR==0) cout<<DAY+1<<" "<<ANS_MONTH<<" "<<ANS_YEAR+1<<endl;
				else cout<<DAY<<" "<<ANS_MONTH<<" "<<ANS_YEAR+1<<endl; continue;
			}
		}
	}	
}
int read() {static int tmp; tmp=read(); return tmp;}



