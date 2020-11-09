#include <iostream>
#include <cstdio>
#include <cstring>
#define il inline
#define res register int
using namespace std;

il int read()
{
	int x=0,f=0,c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=1;c=getchar();}
	while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
	return f?-x:x;
}

const int month[14]={0,31,28,31,30,31,30,31,31,30,31,30,31,29};

int ansmonth,ansyear,ansday;
void inayear(int x,bool v)
{
	int mth=1;
	while(x-month[mth]>=0) 
	{
		if(v==1&&mth==2)  x=x-month[13];
		else x=x-month[mth];
		mth++;
	}
	ansday=1+x;
	ansmonth=mth;
}

bool checkbc(int x)
{
	if( (x-1)%4==0 ) return 1;
	return 0;
}

bool check(int x)
{
	if(x%400==0) return 1;
	if( (x%4==0)&&(x%100!=0) ) return 1;
	return 0;
}


void init(){ansmonth=ansday=ansyear=0;}

int getday(int x)
{
	if(checkbc(x)) return 366;
	else return 365;
}

int getdayaf(int x)
{
	if(check(x)) return 366;
	else return 365;
}


int main()
{
	freopen("julian.in","r",stdin);
	freopen("julian.out","w",stdout);
	
	int q=read();
	while(q--)
	{
		init();
		int ask=read(); 
		if(ask<=365)
		{
			inayear(ask,1);
			printf("%d %d 4713 BC\n",ansday,ansmonth);
		}
		
		else
		{
			int yea=0; bool flag=0;
			while(ask>getday(4713-yea))
			{
				 ask-=getday(4713-yea);	yea++; 
				 if(yea==4713) { flag=1; break;}
			} 
			if(!flag)
			{
				yea=4713-yea;
				inayear(ask, checkbc(yea) );
				printf("%d %d %d BC\n",ansday,ansmonth,yea);
			}
			else
			{
				yea=1;
				while(ask>getdayaf(yea))
				{
					ask-=getdayaf(yea); yea++;
				}
				inayear(ask,check(yea));
				printf("%d %d %d\n",ansday,ansmonth,yea);
			}
		}
		
	}
	return 0;
}
	

