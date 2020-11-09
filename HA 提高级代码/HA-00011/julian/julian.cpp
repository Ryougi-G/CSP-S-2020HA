#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<bits/stdc++.h>
#include<list>
#include<functional>
#include<cctype>
#define ll long long
using namespace std;
int q;//读入 
ll r;//读入 
int gongyuan=4713;
int shengyu,ez,shengyuu,ezz; 
//前4713年为闰 
int run[12]={31,29,31,30,31,30,31,31,30,31,30,31};
//闰年366天 
int ping[12]={31,28,31,30,31,30,31,31,30,31,30,31};
//平年365天 
int year,month,day;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-') f=-1;ch=getchar();}
	while(isdigit(ch)){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
void print(int  x){
	if(x<0)	putchar('-'),x=-x;
	if(x>9)	print(x/10);
	putchar(x%10+'0');
}
bool pd(int x){//判断闰平年 
	if(x<0){
		if((-x-1)%4==0)	return true;
		return false;
	}
	else if(x>0 && x<1582){
		if(x%4==0)	return true;
		return false; 
	}
	else if(x>=1582){
		if(x%4==0 && x%100!=0)	return true;
		else if(x%400==0)	return true;
		return false;	
	}
} 
void yearr(int x){
//	bool flag=1;//1为闰,0为平
	int ez=-4713;
	while(1){
		if(ez==0)	ez++;
		if(pd(ez)){//是闰年 
			if(x>=366){
				x-=366;year++;ez++;
			} else break;
		}
		if(!pd(ez)){
			if(x>=365){
				x-=365;year++;ez++;
			} else break; 
		}
	} shengyu=x;year=ez;//return year;return x;
//	while(1){
//		if(flag){
//			if(x>=366){
//				x-=366;year++;flag=false;ez--;
//			}else	break;
//		}else if(!flag){
//			if(x>=365){
//				x-=365;year++;flag=true;
//			}else	break;
//		}
//	}	shengyu=x;return year;return shengyu;	
} 
void monthh(int x){
//	int mmm=0;
	if(pd(year)){
		while(x>run[month]){
			month++;x-=run[month];
		}shengyuu=x;//ezz=mmm+1;
	}
	else if(!pd(year)){
		while(x>ping[month]){
			month++;x-=ping[month];
		}shengyuu=x;//ezz=mmm+1;
	}
}
int main(){
	freopen("julian.in","r",stdin);
	freopen("julian.out","w",stdout);
	scanf("%d",&q);
	for(register int i=1;i<=q;i++){
		r=read();//scanf("%lld",&r);
		if(r>=2299478)	r+=11;
		year=0;month=0;day=0;//初始化 
		yearr(r);
//		cout<<year<<endl;cout<<shengyu<<endl; 
		monthh(shengyu);
//		if(pd(ez))	cout<<shengyuu<<" ";
//		else if(!pd(ez))		cout<<shengyuu<<" ";
//		if(year>=1582 && month+1>=10 && shengyuu>=15){
//			shengyuu+=9;
//		}
		if(month==0)	cout<<shengyuu+1<<" ";
		else cout<<shengyuu<<" ";
		cout<<month+1<<" ";
		if(year<0){
			year=-year;
			print(year);cout<<" "<<"BC"<<endl;//cout<<-year<<" "<<"BC"<<endl;
		} 
		else{
			cout<<year+1<<endl;
		}
//		cout<<year<<endl;
//		if(year=) 
//		year=year-4713;
	}
	return 0;
}
/*
1582 10 4:
2299478

1582 10 15：
2299479
*/
