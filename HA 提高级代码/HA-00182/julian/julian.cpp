#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
using namespace std;
int main() {
	freopen("julian.in","r",stdin);
	freopen("julian.out","w",stdout);
	int Q,r;
	int year=-4713,month=1,day=1;
	int days[15]={31,28,31,30,31,30,31,31,30,31,30,31};
	scanf("%d",&Q);
	for(int i=0;i<Q;i++) {
		scanf("%d",&r);
		for(int j=0;j<r;j++) {
			day++;
			if( (year<0 && (year-1)%4==0) || 
				(year>0 && ((year<1582 || (year==1582 && month<10) || (year==1582 && month ==10 && day<=4)) && year%4==0) ||
				((year>1582 || (year==1582 && month>10) || (year==1582 && month ==10 && day>4)) && (year%400==0 || (year%4==0 && year%100!=0))))) {
				if((month!=2 && day>days[month-1]) || (month==2 && day>29)) month++,day=1;
			} else {
				if(day>days[month-1]) month++,day=1;
			}
			if(month>12) year++,month=1;
			if(year==0) year++,day--;
			if(year==1582 && month==10 && day==5) day=15;
		}
		if(year<0) {
			printf("%d %d %d BC",day,month,-year);
		} else {
			printf("%d %d %d",day,month,year);
		}
		cout << endl;
		year=-4713,month=1,day=1;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

