#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=5e6+10;
const int yy=365;
const int ru=4713;
int BC[4810],AC[maxn];
int dayy[12]={0,31,28,31,30,31,30,31,31,30,31,30};
inline int readint()
{
	int x=0,f=1; char c=getchar();
	while(c<'0'||c>'9')
	{
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		x=(x<<1)+(x<<3)+(c^48);
		c=getchar();
	}
	return f*x;
}
inline bool pana(int x)
{
	if(x%4==1) return 1;
	else return 0;
}
inline bool panb(int x)
{
	if((x%400==0)||((x%4==0)&&(x%100!=0))) return 1;
	else return 0;
}
inline void init()
{
	int n=ru;
	while(n)
	{
		BC[n]=(BC[n+1]+(n%4==1));
		--n;
	}
	AC[1]=BC[1];
	for(int i=2;i<=1581;++i) AC[i]=AC[i-1]+pana(i);
	AC[1582]=AC[1581]-10;
	for(int i=1583;i<=5e6;++i) AC[i]=AC[i-1]+panb(i);
}
inline int mypower(int &myday,bool flag)
{
	int ans=1;
	for(int i=1;i<=11;++i)
	{
		if(i==2&&flag) --myday;
		if(myday<=dayy[i]) return ans;
		myday-=dayy[i];
		++ans;
	}
}

int main()
{
	freopen("julian.in","r",stdin);
	freopen("julian.out","w",stdout);
	init();
	int q=readint();
	while(q--)
	{
		int myday,mymonth,myyear;
		myday=readint(); ++myday;
		myyear=myday/yy;//过去的整年 
		bool flag=0;
		if(myyear<ru)
		{
			int res=myday%yy;
			myyear=ru-myyear;//真实的年份 
			while(res<BC[myyear+1]) 
			{
				++myyear;
				res+=(yy+(BC[myyear+1]-BC[myyear+2]));
			}
			
			myday-=(yy*(ru-myyear)+BC[myyear+1]);//该年剩下的天数 
			if(pana(myyear)) flag=1;//该年是否为闰年 
			mymonth=mypower(myday,flag);//求月份和日期 
			printf("%d %d %d BC\n",myday,mymonth,myyear);
		}
		else
		{
			int res=myday%yy;
			myyear-=(ru-1);//真实的年份
			while(res<AC[myyear-1]) 
			{
				--myyear;
				res+=(yy+(AC[myyear-1]-AC[myyear-2]));
			}
			myday-=(yy*(myyear+ru-1)+AC[myyear-1]);//该年剩下的天数
			if(panb(myyear)) flag=1;//该年是否为闰年 
			mymonth=mypower(myday,flag);//求月份和日期 
			printf("%d %d %d\n",myday,mymonth,myyear);
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
