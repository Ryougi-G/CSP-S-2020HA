#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int BCTIME=1721424;
const int TIME1582=114514;
struct date{
	int day,month,year;
	bool isbc;
};
date deal(int day){
	date res;
	res.day=0;res.month=0;res.year=0;
	if(day<BCTIME){
		res.isbc=true;
		for(int i=4713;i>=1;i--){
			if((i-1)%4==0){
				if(day<=365){
					res.year=i;
					break;
				}
				day-=366;
			}else{
				if(day<=364){
					res.year=i;
					break;
				}
				day-=365;
			}
		}
		for(int i=1;i<=12;i++){
			if(i==2){
				if((res.year-1)%4==0){
					if(day<29){
						res.month=i;
						break;
					}
					day-=29;
				}else{
					if(day<28){
						break;
					}
					day-=28;
				}
			}else if((i==1)||(i==3)||(i==5)||(i==7)||(i==8)||(i==10)||(i==12)){
				if(day<31){
					res.month=i;
					break;
				}
				day-=31;
			}else{
				if(day<30){
					res.month=i;
					break;
				}
				day-=30;
			}
		}
		res.day=day+1;
		return res;
	}else{
		res.isbc=false;
		day=day-BCTIME;
		int ti1=1;
		int dts=0;
		while(true){
			if(ti1!=1582){
				if((ti1%4==0&&ti1%100!=0)||ti1%400==0){
					if(day<365){
						res.year=ti1;
						break;
					}
					dts+=366;
					day-=366;
				}else{
					if(day<364){
						res.year=ti1;
						break;
					}
					dts+=365;
					day-=365;
				}
			}else{
				if(day<355){
					res.year=ti1;
					break;
				}
				dts+=355;
				day-=355;
			}
			ti1++;
		}
		if(res.year!=1582){
			for(int i=1;i<=12;i++){
				if(i==2){
					if((res.year%4==1&&res.year%100==0)||res.year%400==0){
						if(day<29){
							res.month=i;
							break;
						}
						day-=29;
					}else{
						if(day<28){
							break;
						}
						day-=28;
					}
				}else if((i==1)||(i==3)||(i==5)||(i==7)||(i==8)||(i==10)||(i==12)){
					if(day<31){
						res.month=i;
						break;
					}
					day-=31;
				}else{
					if(day<30){
						res.month=i;
						break;
					}
					day-=30;
				}
			}
			res.day=day+1;
			return res;
		}else{
			for(int i=1;i<10;i++){
				if(i==2){
					if((res.year%4==1&&res.year%100==0)||res.year%400==0){
						if(day<29){
							res.month=i;
							break;
						}
						day-=29;
					}else{
						if(day<28){
							break;
						}
						day-=28;
					}
				}else if((i==1)||(i==3)||(i==5)||(i==7)||(i==8)||(i==10)||(i==12)){
					if(day<31){
						res.month=i;
						break;
					}
					day-=31;
				}else{
					if(day<30){
						res.month=i;
						break;
					}
					day-=30;
				}
			}
			if(day<21){
				if(res.year==0){
					if(day<4){
						res.day=day+1;
					}else if(day>=4){
						res.day=14+(day-3);
					}
					return res;
				}else{
					res.day=day+1;
					return res;
				}
			}else{
				day-=21;
				for(int i=11;i<=12;i++){
					if(i==2){
						if((res.year-1)%4==0){
							if(day<29){
								res.month=i;
								break;
							}
							day-=29;
						}else{
							if(day<28){
								break;
							}
							day-=28;
						}
					}else if((i==1)||(i==3)||(i==5)||(i==7)||(i==8)||(i==10)||(i==12)){
						if(day<31){
							res.month=i;
							break;
						}
						day-=31;
					}else{
						if(day<30){
							res.month=i;
							break;
						}
						day-=30;
					}
				}
				res.day=day+1;
				return res;
			}
		}
	}
}
int main(){
	freopen("julian.in","r",stdin);
	freopen("julian.out","w",stdout);
	int q;
	cin>>q;
	while(q--){
		ll day;
		cin>>day;
		date res=deal(day);
		if(res.isbc){
			cout<<res.day<<" "<<res.month<<" "<<res.year<<" BC"<<endl;
		}else{
			cout<<res.day<<" "<<res.month<<" "<<res.year<<endl;
		}
	}
	return 0;
}



