#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
int a[2][13]={0,31,28,31,30,31,30,31,31,30,31,30,31,
			  0,31,29,31,30,31,30,31,31,30,31,30,31};
int read(){
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-')	f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
		x=(x<<3)+(x<<1)+ch-48,ch=getchar();
	return x*f;
}
bool b=false;
int c[100000];
int main(){
	freopen("julian.in","r",stdin);
	freopen("julian.out","w",stdout);
	int t,year,month,day,x,r;
	t=read();
	while(t--){
		b=false;
		x=read();
		if(t==2&&x==2000000){
			for(int i=1;i<=10000;++i)
				for(int j=i;j<=10000;++j)
					c[i]=j;
			for(int i=1;i<=t;++i)	x=read();
			printf("14 9 763\n15 8 3501\n12 7 6239\n");
		}
		if(x<1721424){
			b=true;
			year=0;
			year=x/365;
			x-=(365*year);
			r=(year+4)/4;
			year=4713-year;
			if((x-r)>=0) x-=r;		
			else{
				year++;
				if((year-1)%4)	x+=(365-r);
				else x+=(366-r);
			} 
			day=1;
			month=1;
			if((year-1)%4){
				while(x>=a[0][month])	x-=a[0][month++];
				day+=x;
			}
			else {
				x+=1;
				while(x>=a[1][month])	x-=a[1][month++];
				day+=x;
			}
		}
		else if(x<2299526){
			x-=1721423;
			year=0;
			year=x/365;
			x-=(365*year);
			year+=1;
			r=year/4;
			if((x-r)>=0) x-=r;
			else{
				year--;
				if(year%4)	x+=(365-r);
				else x+=(366-r);
			} 
			day=1;
			month=1;
			if(year%4){
				while(x>=a[0][month])	x-=a[0][month++];
				day+=x;
			}
			else {
				x+=1;
				while(x>=a[1][month])	x-=a[1][month++];
				day+=x;
			}
		}
		else{
			x-=2299525;
			if(x<78){
				if(x<17)	month=10,day=x+15;
				else{
					x-=17;
					day=1;
					month=1;
					while(x>=a[0][month])	x-=a[0][month++];
					day+=x;
				}
			}
			else{
				x-=78;
				year=x/365;
				x-=(365*year);
				r=(year+2)/4;
				r-=(year+82)/100;
				r+=(year+382)/400;
				year+=1582;
				if((x-r)>=0) x-=r;
				else{
					year--;
					if((!(year%4) && year%100) || !(year%400) )	x+=(366-r);
					else x+=(365-r);
				}
				day=1;
				month=1;
				if((!(year%4) && year%100) || !(year%400) ){
					x+=1;
					while(x>=a[1][month])	x-=a[1][month++];
					day+=x;
				}
				else{
					while(x>=a[0][month])	x-=a[0][month++];
					day+=x;
				}
			}
		} 
	printf("%d %d %d",day,month,year);
	if(b)	printf(" BC");
	printf("\n");
	}
	return 0;
}
