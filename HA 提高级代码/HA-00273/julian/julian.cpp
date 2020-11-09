#include<bits/stdc++.h>
using namespace std;
int mon[13]={-1,31,28,31,30,31,30,31,31,30,31,30,31};
int q,r[100009];
struct note
{
	int y;
	int m;
	int d;
	bool f;
};
note rip[100009];
int main()
{
	
	freopen("julian.in","r",stdin);
	freopen("julian.out","w",stdout);
	cin>>q;
	for(int i=1;i<=q;i++)
	cin>>r[i];
	for(int i=1;i<=q;i++)
	{
		if(r[i]<1721423)
		{
			int yy=4713,mm=1,dd=1;
			for( ; ; )
			{
				if((yy-1)%4==0)
				mon[2]=29;
				else
				mon[2]=28;
				if(mm==12&&dd==mon[mm])
				{
					mm=1;
					dd=1;
					yy--;
					r[i]--;
					if(r[i]==0)
					{
						rip[i].y=yy;
						rip[i].m=mm;
						rip[i].d=dd;
						rip[i].f=true;
						break;
					}
					continue;
				}
				if(mm!=12&&dd==mon[mm])
				{
					mm++;
					dd=1;
					r[i]--;
					if(r[i]==0)
					{
						rip[i].y=yy;
						rip[i].m=mm;
						rip[i].d=dd;
						rip[i].f=true;
						break;
					}
					continue;
				}
				dd++;
				r[i]--;
				if(r[i]==0)
				{
					rip[i].y=yy;
					rip[i].m=mm;
					rip[i].d=dd;
					rip[i].f=true;
					break;
				}
			}
		}
		else if(r[i]==1721423)
		{
			rip[i].y=1;
			rip[i].m=12;
			rip[i].d=31;
			rip[i].f=true;
		}
		else if(r[i]==1721424)
		{
			rip[i].y=1;
			rip[i].m=1;
			rip[i].d=1;
			rip[i].f=false;
		}
		else if(r[i]>1721424&&r[i]<2299160)
		{
			int yy=1,mm=1,dd=1;
			r[i]-=1721424;
			for( ; ; )
			{
				if(yy%4==0)
				mon[2]=29;
				else
				mon[2]=28;
				if(mm==12&&dd==mon[mm])
				{
					mm=1;
					dd=1;
					yy++;
					r[i]--;
					if(r[i]==0)
					{
						rip[i].y=yy;
						rip[i].m=mm;
						rip[i].d=dd;
						rip[i].f=true;
						break;
					}
					continue;
				}
				if(mm!=12&&dd==mon[mm])
				{
					mm++;
					dd=1;
					r[i]--;
					if(r[i]==0)
					{
						rip[i].y=yy;
						rip[i].m=mm;
						rip[i].d=dd;
						rip[i].f=true;
						break;
					}
					continue;
				}
				dd++;
				r[i]--;
				if(r[i]==0)
				{
					rip[i].y=yy;
					rip[i].m=mm;
					rip[i].d=dd;
					rip[i].f=false;
					break;
				}
			}
		}
		else if(r[i]==2299160)
		{
			rip[i].y=1582;
			rip[i].m=10;
			rip[i].d=4;
			rip[i].f=false;
		}
		else if(r[i]==2299161)
		{
			rip[i].y=1582;
			rip[i].m=10;
			rip[i].d=15;
			rip[i].f=false;
		}
		else if(r[i]>2299161)
		{
			int yy=1582,mm=10,dd=15;
			r[i]-=2299161;
			bool f=true;
			for( ; ; )
			{
				r[i]-=365250000;
				yy+=1000000;
				if(r[i]==0)
				{
					f=false;
					rip[i].y=yy;
					rip[i].m=mm;
					rip[i].d=dd;
					rip[i].f=false;
					break;
				}
				if(r[i]<0)
				{
					r[i]+=365250000;
					yy-=1000000;
					break;
				}
			}
			if(f)
			for( ; ; )
			{
				if((yy%4==0&&yy%100!=0)||yy%400==0)
				mon[2]=29;
				else
				mon[2]=28;
				if(mm==12&&dd==mon[mm])
				{
					mm=1;
					dd=1;
					yy++;
					r[i]--;
					if(r[i]==0)
					{
						rip[i].y=yy;
						rip[i].m=mm;
						rip[i].d=dd;
						rip[i].f=true;
						break;
					}
					continue;
				}
				if(mm!=12&&dd==mon[mm])
				{
					mm++;
					dd=1;
					r[i]--;
					if(r[i]==0)
					{
						rip[i].y=yy;
						rip[i].m=mm;
						rip[i].d=dd;
						rip[i].f=true;
						break;
					}
					continue;
				}
				dd++;
				r[i]--;
				if(r[i]==0)
				{
					rip[i].y=yy;
					rip[i].m=mm;
					rip[i].d=dd;
					rip[i].f=false;
					break;
				}
			}
		}
	}
	for(int i=1;i<=q;i++)
	{
		cout<<rip[i].d<<' '<<rip[i].m<<' '<<rip[i].y;
		if(rip[i].f)
		cout<<' '<<"BC"<<'\n';
		else
		cout<<'\n';
	}
	
	return 0;
}

// 1 12 31 BC ==> 1721423
// 4 10 1582  ==> 2299160
// R.I.P.
