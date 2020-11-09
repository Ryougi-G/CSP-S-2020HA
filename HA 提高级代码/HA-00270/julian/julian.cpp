#include<iostream>
#include<cstdio>
using namespace std;
long long year=-4713,mon=1,day=1;
int monv[20]={0,1,2,1,0,1,0,1,1,0,1,0,1};//1 for 31
long long tem=0,n=0,m;
int runf=0;
int main(){
	freopen("julian.in","r",stdin);
	freopen("julian.out","w",stdout);
	scanf("%lld",&m);
	for(int i = 1;i<=m;i++){
		scanf("%lld",&n);
		year=-4713;mon=1;day=1;tem=0;
		while(n>=366){
		if(year==0)  year++;
		int ty=year;
		if(ty<0)  ty=-1*(ty+1);
		if((year<1582&&ty%4==0)||(ty%400==0||(ty%4==0&&ty%100!=0))){
			n-=366;
		}
		else if(year==1582){
			n-=355;
		}
		else{
			n-=365;
		}year++;
		}
		
		int ty=year;
		if(ty<0)  ty=-1*(ty+1);
		if((year<1582&&ty%4==0)||(ty%400==0||(ty%4==0&&ty%100!=0))){
			runf=1;
		}
		else{
			runf=0;
		}
		
		while(tem!=n){
		tem++;
		day++;
		if(year==1582&&mon==10&&day==5){
			day=15;
			continue;
		}
		if(monv[mon]==1){//31
			if(day==32){
				day=1;
				mon++;
			}
			continue;
		}
		else if(monv[mon]==0){//30
			if(day==31){
				day=1;
				mon++;
			}
			continue;
		}
		else{
			if(runf){
			if(day==30){
				day=1;
				mon++;
			}	
			}
			else{
			if(day==29){
				day=1;
				mon++;
			}
			}
		}}
		if(year<0){
			printf("%lld %lld %lld BC\n",day,mon,year*-1);
		}
		else{
			printf("%lld %lld %lld\n",day,mon,year);
		}
	}
}
