// 1178 1720245 1721423
// 383 577430 577813
// 2299236
// 277
// 2299513/2298525
// 2299527
// 2299525
#include<bits/stdc++.h>
#define ll long long

using namespace std;

int mon[12]={31,28,31,30,31,30,31,31,30,31,30,31};
int Q;

int main()
{
	freopen("julian.in","r",stdin);
	freopen("julian.out","w",stdout);
	
	cin>>Q;
	for(int i=0;i<Q;i++)
	{
		ll tmp;
		cin>>tmp;
		if(tmp<=2299525+78)
		{
			int year=tmp/1461*4;
			int day=tmp-(year*365);
			day-=(year/4);
			if(day>=365)
			{
				year+=day/365;
				day%=365;
			}
//			cout<<day<<" "<<year<<" lq"<<endl;
			int j=0;
			while(day>=mon[j])
			{
				day-=mon[j];
				j++;
			}
			if(j==0)
			{
				day++;
			}
			if(year>4713)
			{
				cout<<day<<" "<<j+1<<" "<<year-4713+1<<endl;
			}else if(year<4713)
			{
				cout<<day<<" "<<j+1<<" "<<4713-year<<" BC"<<endl;
			}
		}else if(tmp>2299525+78)
		{
			
//			int year=tmp/1461*4;
//			int day=tmp-year*365;
//			day-=1573;
//			day-=(year-6295-1)/4;
//			day+=((year-6295)/400)*3;
//			day+=11;
////			cout<<year-6295+1582<<endl;
//			if(day>=365)
//			{
//				if((year+1-6295+1582)%4==0)
//				{
//					day++;
//				}
//				year+=day/365;
//				day%=365;
//			}
////			cout<<day<<" "<<year<<" nmsl"<<endl;
//				
//			int j=0;
//			while(day>=mon[j])
//			{
//				day-=mon[j];
//				j++;
//			}
//			if(j==0)
//			{
//				day++;
//			}
//			cout<<day<<" "<<j+1<<" "<<year-4713+1<<endl;
			
//			tmp-=2299513-78;
//			int year=tmp/365;
//			int day=tmp-year*365;
//			for(int i=1600;i<=1582+year;i++)
//			{
//				if(i%400==0)
//				{
//					day--;
//				}else if(i%4==0&&i%100!=0)
//				{
//					day--;
//				}
//			}
//			int j=0;
//			while(day>=mon[j])
//			{
//				day-=mon[j];
//				j++;
//			}
//			cout<<day<<" "<<j+1<<" "<<year+1582<<endl;

			tmp-=2299525;
			tmp-=78;
			int j=0; 
			
			
//			int j,o;
//			int day=0,year=1583;
//			j=tmp/365;
//			day=tmp-j*365;
//			cout<<day<<endl;
//			day=day-j/400-j/4+j/100;
//			cout<<day<<endl;
//			for(o=year+j;day>365;o++)
//			{
//				cout<<o<<" ";
//				if(o%4==0&&o%100!=0)
//				{
//					day-=366;
//				}else if(o%400==0)
//				{
//					day-=366;
//				}else
//				{
//					day-=365;
//				}
//			}cout<<" "<<day<<endl;
			for(j=1583;;j++)
			{
				if(tmp<365)
				{
					break;
				}
				if(j%4==0&&j%100!=0)
				{
					tmp-=366;
				}else if(j%400==0)
				{
					tmp-=366;
				}else
				{
					tmp-=365;
				}
//				cout<<tmp<<endl;
			}
			
			while(tmp<0)
			{
				if((j%4==0&&j%100!=0)||j%400==0)
				{
					j--;
					tmp+=366;
				}else
				{
					j--;
					tmp+=365;
				}
			}
			
			int j1=0;
			while(tmp>=mon[j1])
			{
				tmp-=mon[j1];
				j1++;
			}
			cout<<tmp<<" "<<j1+1<<" "<<j+1<<endl;
		}
	}
}
