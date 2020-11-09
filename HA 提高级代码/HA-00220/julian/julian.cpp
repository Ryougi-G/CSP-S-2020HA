#include <iostream>
#include <stdio.h>
#include <cmath>
using namespace std;
	int cachemon,cacheyear;
	int month=1,day=1,day1=4713;
/*
1582.10.4以前 只要是年份为4的倍数就是闰年（400的倍数不一定是闰年）
1582.10.5-1582.10.14 这些日期不存在，直接删除
1582.10.15以后	只要年份倍数为400或者4的倍数但不为100的倍数时，该年为闰年


一月31
二月28/29
三月31
四月30
五月31
六月30
七月31
八月31
九月30
十月31
十一月30
十二月31


不存在公元0年
儒略历从公元前45年开始实行
 BC闰1 5 9 13 17 21 25 29 33 37 41 45  
*/
// unsigned long long abd();

int pdday(int day){
	/*
	if(month==2){
		for(int i=day;i>=28;i=i-28){
			cachemon++;
			month++;
			day=day-28;
			
		}
		if(day==0){
			return 1;
		}
		
		return day;
	}
	
	else if(month==4||month==6||month==9||month==11){
	for(int i=day;i>=30;i=i-30){
			cachemon++;
			month++;
			day=day-30;
		}
	}
	else if(month==1||month==3||month==5||month==7||month==8||month==10||month==12){
		for(int i=day;i>=31;i=i-31){
			cachemon++;
			month++;
			day=day-31;
		}
		if(day==0){
			return 1;
		}
		return day;
		
	}
	*/
	
}
int pdmon(int month){
	for(int i=month;i>=30;i=i-30){
			cacheyear++;
			month=month-30;
		}
		return cachemon;
}
int pdyear(int a){
	
}
int main(){
	freopen("julian.in","r",stdin);
	freopen("julian.out","w",stdout);
	int day=1,month=1,year=-4713,a,e;
	bool abd=0,yr=1;//yr =
	cin>>e;
	for(int i=e;i>0;i--){
		cin>>a;
		day=a+day;
		for(;day>31;){
			if(month==1||month==3||month==5||month==7||month==8||month==10||month==12){
				day=day-31;
				month++;
			}
			else if(month==4||month==6||month==9||month==11){
				day=day-30;
				month++;
			}
			else if(month==2){
				if(year<-45){
					year=abs(year);
					if(year%4==0){
						day=day-29;
						month++;
					}
					else{
						day=day-28;
						month++;
					}
				}
				else{
					year=abs(year);
					if(year%4==0||year%400==0){
						day=day-29;
						month++;
					}
					else{
						day=day-28;
						month++;
					}
				}
			}
			for(;month>12;){
				year--;
				month=month-12;
			}
		}
		if(year<0){
			year=abs(year);
			abd=1;
		}
		//else if(){
			
		//}
		
		if(month!=1||year!=-4713){
			day=day-1;
			
		}
		
		cout<<day<<" "<<month<<" "<<year;
		if(abd=1){
			cout<<" "<<"BC";
		}
		cout<<endl;
		day=1;
		month=1;
		year=-4713;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
