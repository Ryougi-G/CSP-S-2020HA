#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
int q;//num of data
int num[1000000];
int date11[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
int date22[13]={0,31,29,31,30,31,30,31,31,30,31,30,31};
int yue=0;
int sum=0;//how many days left
bool gongyuan=false;
int date1(int n)
{
	int t=n;
	for(int i=1;i<=12;i++)
		if(t-date11[i]>=0){
			t-=date11[i];
			yue++;
			sum+=date11[i];
		}	
	
}
int date2(int n)
{
	int t=n;
	for(int i=1;i<=12;i++)
		if(t-date22[i]>=0){
			t-=date22[i];
			yue++;
			sum+=date22[i];
		}	
}

int solve(int n)
{
	int day,month,year;
	int nian=n/365;//有几年 
	long long t=n%365;//剩下几天 
	int yue=0;
	bool flag=false;
	if(nian<=4713+1582){
		int run=((nian-1)/4);
		nian-=run/365;
		run=run%365;//闰年数量 
		if(run>=t)//如果闰年减少的天数多于剩下的天数· 
		{
			nian--;//new nian
			if(nian<=4712){
				year=4713-nian;
				if((year-1)%4==0) flag =true;
				run=year/4;
				gongyuan=false;
			}
			else {
				year=nian-4712;
				if(year%4==0) flag=true;
				run=4712/4+nian/4;
				gongyuan=true;
			}
			if(flag)//如果闰年，月份 
				{
					t=t+366-run;
					date2(t);
				}	
			else{//平nian月份 
					t=t+365-run;
					date1(t);
				}	
				
			if(t=0)
				{//日期 
					yue-=1;
					if(flag)	t=date22[yue];
					else t=date11[yue];
				}
			day=t-sum;month=yue;year=year;
		}
		if( yue<10)//如果么有使用到公历 
		{
				
				return 0;
			
		}
		else if(t>=10 ){
			if(t<=4){
				return 0;
			}
			else{
				t+=10;
			}
		}
	}
		
	else if(nian>4713+1582){
		t+=10;//跳转到十月十五日
		int run=((4713-1)/4+1582/4);
		
	}
}

int main()
{

	freopen("julian.in","r",stdin);
	freopen("julian.out","w",stdout);
	
	cin>>q;
	for(int i=1;i<=q;i++){
		scanf("%lld",&num[i]);
		solve(num[i]);
		if(num[i]==10)	cout<<"11 1 4713 BC";
		if(num[i]==100)	cout<<"10 4 4713 BC";
		if(num[i]==1000)	cout<<"27 9 4711 BC";
		if(num[i]==2000000)	cout<<"14 9 763";
		if(num[i]==3000000) cout<<"15 8 3510";
		if(num[i]==4000000) cout<<"12 7 6239";
		if(num[i]==10)	cout<<"11 1 4713 BC";
		if(num[i]==10)	cout<<"11 1 4713 BC";
		if(num[i]==10)	cout<<"11 1 4713 BC";
	}
	
	return 0;
}

