#include<bits/stdc++.h>
using namespace std;
int yuefen(int x){
	if(x<182){
		if(x<90){
			if(x<59){
				if(x>31)return 2;
				else return 1;
			}else{
				return 3;
			}
		}else{
			if(x<121)return 4;
			else {
				if(x<152)return 5;
				else return 6;
			}
		}	
	}else{
		if(x>273){
			if(x>304){
				if(x>334)return 12;
				else return 11;
			}else return 10;
		}else{
			if(x>212){
				if(x>243)return 9;
				else return 8;
			}else return 7;
		} 
	}
}
int runyue(int x){
	if(x<183){
		if(x<91){
			if(x<60){
				if(x>32)return 2;
				else return 1;
			}else{
				return 3;
			}
		}else{
			if(x<122)return 4;
			else {
				if(x<153)return 5;
				else return 6;
			}
		}	
	}else{
		if(x>274){
			if(x>305){
				if(x>335)return 12;
				else return 11;
			}else return 10;
		}else{
			if(x>213){
				if(x>244)return 9;
				else return 8;
			}else return 7;
		} 
	}
}
int a[100005],d[100005];
int b[13]={0,0,31,59,90,120,151,181,212,243,273,304,334};
int c[13]={0,0,31,60,91,121,152,182,213,244,274,305,335};
int main(){
	freopen("julian.in","r",stdin);
	freopen("julian.out","w",stdout);
	int n=0,sum1=0,sum=0,year=0,year1=4713,month=0,day=0,t=0,t1=0;
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		if(a[i]<=2299160){
			if(a[i]>365){
				year=4*(a[i]/1461);
				sum1=a[i]%1461;
				year+=sum1/365;
				sum1%=365;
				if(sum1==0)sum1++;
				if(year1>year)year=year1-year-1,sum=1;
				else year-=year1-1;
				if(year%4==0){
					month=runyue(sum1);
					if(month==1){
						day=sum1;
					}else{
						day=sum1-c[month];
					}
				}else{
					month=yuefen(sum1);
					if(month==1){
						day=sum1;
					}else{
						day=sum1-b[month];
					}
				}
				if(sum==1){
					cout<<day<<" "<<month<<" "<<year+1<<" "<<"BC"<<endl;
				}else{
					cout<<day<<" "<<month<<" "<<year<<endl;
				}
			}else{
				a[i]+=1;
				month=yuefen(a[i]);
				day=a[i]-c[month];
				cout<<day<<" "<<month<<" "<<year1<<" "<<"BC"<<endl;
			}
		}else{
			d[i]=a[i]-2298873;
			year=4*(d[i]/1461);
			t=year/100;
			t1=year/400;
			year=year+1582;
			sum1=d[i]%1461+t-t1;
			year+=sum1/365;
			sum1=(d[i]+t-t1)%1461;
			sum1%=365;
			if(sum1==0)sum1++;
			if(((year%4==0)&&(year%100!=0))||(year%400==0)){
				month=runyue(sum1);
				if(month==1){
					day=sum1;
				}else{
					day=sum1-c[month];
				}
			}else{
				month=yuefen(sum1);
				if(month==1){
					day=sum1;
				}else{
					day=sum1-b[month];
				}
			}
			cout<<day<<" "<<month<<" "<<year<<endl;
		}
	}
	return 0;
	
}
