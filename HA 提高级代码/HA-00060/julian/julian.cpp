#include<bits/stdc++.h>
#define reg register 
inline long long qr(){
	long long x=0,f=0;char ch=0;
	while(!isdigit(ch)){f|=ch=='-';ch=getchar();}
	while(isdigit(ch)){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
	return f?-x:x;
}
struct julian{
	int year,month,day;
}a[5000010];//5e6空间松散 
//1,3,5,7,8,10,12;
int o[13]={};
int yu1,yu2,flag;//两个阈值,第一个是公元分界,第二个是1582 
int q;
int main(){
	freopen("julian.in","r",stdin);
	freopen("julian.out","w",stdout);
	o[1]=1;o[3]=1;o[5]=1;o[7]=1;o[8]=1;o[10]=1;o[12]=1;o[2]=2;
	a[0].day=1;a[0].month=1;a[0].year=-4713;
	for(reg int i=1;i<=5000010;i++){
		a[i].day=a[i-1].day+1;//先算出来日 
		if(o[a[i-1].month]==1){//31
			if(a[i].day>31){
				a[i].month=a[i-1].month+1;
				a[i].day=1;
				if(a[i].month>12){
					a[i].year=a[i-1].year+1;
					a[i].month=1;
					if(a[i].year==0){//没有公元0年 
						a[i].year=1;
					}
				}
				else a[i].year=a[i-1].year;
			}
			else {
				a[i].month=a[i-1].month;
				a[i].year=a[i-1].year;	
				if(a[i].year==1582&&a[i].day==5&&a[i].month==10){//1582新纪元 
					a[i].day=15;
					flag=1;
				}
			}
		}
		if(!o[a[i-1].month]){//30
			a[i].year=a[i-1].year;
			if(a[i].day>30){
				a[i].month=a[i-1].month+1;
				a[i].day=1;
			}
			else a[i].month=a[i-1].month;
		}	
		else if(o[a[i-1].month]==2){
			a[i].year=a[i-1].year;
			if((a[i].year%4==0&&(a[i].year%100!=0||a[i].year%400==0)&&flag==1)
			||(((a[i].year%4==0&&a[i].year>0)||(a[i].year<0&&(a[i].year+1)%4==0))&&flag==0))
			{//如果是闰年 
					if(a[i].day>29){
						a[i].month=a[i-1].month+1;
						a[i].day=1;
					}
					else{
						a[i].month=a[i-1].month;
					}
			}
			else if(a[i].day>28){//不是闰年 
				a[i].month=a[i-1].month+1;
				a[i].day=1;
			}
			else if(a[i].day<=28){
				a[i].month=a[i-1].month;
			}
		}
	}
	q=qr();
	while(q--){
		long long r;
		r=qr();
		if(r<=5000010){//80pts
			printf("%d %d %d",a[r].day,a[r].month,std::abs(a[r].year));
			if(a[r].year<0){
				printf(" BC");
			}
			printf("\n");
		}
		else{
			
		}
	}
	return 0;
}

