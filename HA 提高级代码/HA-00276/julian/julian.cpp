#include <bits/stdc++.h>
#define rint register int
#define ull unsigned long long
using namespace std;

int Q,n;
bool nowbc;
int nowyear,nowmonth,nowday;
bool isrun()
{
	if(nowyear<=1582&&nowbc==false)
		if((nowyear%4)==0)
			return true;
	if(nowbc)
		if(((nowyear-1)%4)==0)
			return true;
	if(nowyear>1582&&nowbc==true)
		if(((nowyear%400)==0)||((nowyear%4)==0&&(nowyear%100)!=0))
			return true;
			
	return false;
}
int get_day()
{
	if(nowmonth==1||nowmonth==3||nowmonth==5||nowmonth==7||nowmonth==8||nowmonth==10||nowmonth==12)
		return 31;
	if(nowmonth==4||nowmonth==6||nowmonth==9||nowmonth==11)
		return 30;
	bool run=isrun();
	if(nowmonth==2)
	{
		if(run)
			return 29;
		return 28;
	}
}
void solve()
{
	scanf("%d",&n);
	nowbc=true;
	nowyear=4713;
	nowday=1;
	nowmonth=1;
	while(n--)
	{
		nowday++;
		if(nowday>get_day())
		{
			nowmonth++;
			nowday=1;
		}
		if(nowmonth>12)
		{
			nowmonth=1;
			if(nowbc==false)
				nowyear++;
				
			if(nowbc==true)
			{
				nowyear--;
				if(nowyear==0)
				{
					nowyear++;
					nowbc=false;
				}
			}
			
		}
		if(nowyear==1582&&nowmonth==10&&nowday==5&&nowbc==false)
			nowday=15;
	}
	printf("%d %d %d",nowday,nowmonth,nowyear);
	if(nowbc)
		printf(" BC");
	printf("\n");
}

int main()
{
//	freopen("D:\\1.txt","r",stdin);
	freopen("julian.in","r",stdin);
	freopen("julian.out","w",stdout);
	scanf("%d",&Q);
	while(Q--)
		solve();
	return 0;
}
