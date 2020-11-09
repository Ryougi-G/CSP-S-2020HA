#include<bits/stdc++.h>
#define rint register int
#define N 100005
#define UL  long long
using namespace std;
inline int read(){
	int f=1,x=0;char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
	return x*f;
}
int n;
bool pc=false;//判断闰年 
UL year=-4713,month=1,day=1;
UL x,x1,x2;
int mon[14]={0,31,28,31,30,31,30,31,31,30,31,30,31};
void findyear(UL x){
	x2=0;
	if(x<365){
		x2=x;
		return ;
	}
	else{
		while(year<-1&&x>0){
			UL year1=(-1)*year;
			if(year1%4==1){
				if(x-366<0) {
					x2=x;return ;
				} 
				x-=366,year++;
			}
			else{
				if(x-365<0){
					x2=x;return ;
				} 
				x-=365,year++;
			}
		}//-4713---- -1
		if(year==-1&&x>=0){
			if(x-366<0) {
				x2=x;return ;
			}
			x-=366,year=1;
		}//对于-1 --1 的判断 
		while(year<1582&&x>=0){
			pc=false;
			if(year%4==0) pc=true;
			if(pc==true){
				if(x-366<0){
					x2=x;return ;
				} 
				x-=366,year++;
			}
			else{
				if(x-365<0) {
					x2=x;return ;
				}
				x-=365,year++;
			}
		}
		if(year==1582&&x>=0){
			if(x-355<0){
				x2=x;return ;
			} 
			x-=355,year++;
		}
		while(x>=0){
			pc=false;
			if((year%400==0)||(year%4==0&&year%100!=0)) pc=true;
			if(pc==true){
				if(x-366<0){
					x2=x; return ;
				} 
				x-=366,year++;
			}
			else{
				if(x-365<0)
				{
					x2=x;return ;
				} 
				x-=365,year++;
			}
		}
	}
}
void findmonth(UL x){
	x1=0;
	if(year>1582){
		mon[2]=28;
		if((year%400==0)||(year%4==0&&year%100!=0)) mon[2]=29;
		while(x>=0){
			for(int i=1;i<=12;i++){
				if(x-mon[i]<0)
				{
					month=i;x1=x;
					return ;
				} 
				else{
					x-=mon[i];x1=x;
				}
			}
		}
	}
	else if(year==1582){
		mon[10]=20;mon[2]=28;
		while(x>=0){
			for(int i=1;i<=12;i++){
				if(x-mon[i]<0)
				{
					month=i;x1=x;
					return ;
				} 
				else x-=mon[i];
			}
		}
	}
	else if(year>=1){
		mon[2]=28;
		if(year%4==0) mon[2]=29;
		while(x>=0){
			for(int i=1;i<=12;i++){
				if(x-mon[i]<0)
				{
					month=i;x1=x;
					return ;
				} 
				else x-=mon[i];
			}
		}
	}
	else if(year<=-1){
		mon[2]=28;
		UL year1=-1*year;
		if(year1%4==1) mon[2]=29;
		while(x>=0){
			for(int i=1;i<=12;i++){
				if(x-mon[i]<0)
				{
					month=i;x1=x;
					return ;
				} 
				x-=mon[i];
			}
		}
	}
	
}
void findday(UL x){
	if(year!=1582){
		day+=x;
	}
	else{
		if(x<4){
			day+=x;
		} 
		else{
			day+=10+x;
		}
	}
}
void solve(){
	year=-4713,month=1,day=1;
	findyear(x);
	findmonth(x2);
	findday(x1);
	printf("%lld %lld %lld ",day,month,abs(year));
	if(year<0) printf("BC");
	printf("\n");
}
int main(){
	freopen("julian.in","r",stdin);
	freopen("julian.out","w",stdout);
	n=read();
	for(rint i=1;i<=n;i++){
		x=read();
		solve();
	}
	return 0;
}
