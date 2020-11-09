#include <bits/stdc++.h>
using namespace std;

int main(int argc, char** argv) {
	int q;
	int ju=-4713;//julian
	freopen("julian.in","r",stdin);
	freopen("julian.out","w",stdout);
	int fm[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};//非闰月 
	int tm[13]={0,31,29,31,30,31,30,31,31,30,31,30,31};//闰月 
	cin>>q;
	for(int i=1;i<=q;i++){
		int day;
		cin>>day;
		if(day<2299161){//儒略历表示
		    if(day<1721423){//bc
		    	int year=day/366;
		    	//cout<<year<<' ';
			    int yv=day%366;
			    //year+1 4713离闰年还有3 years ,但不考虑今年
				//cout<<yv<<' '; 
			    int run=(year+2)/4;
			    int add=yv+year-run;//当成润年的日子
			    while(1){
			    	if((year+2)%4==0&&add>=366){
			    		add-=366;
			    		year++;
					}
					if((year+2)%4!=0&&add>=365){
						add-=365;
						year++;
					}
					if(add<365){
						break;
					}
				}
				int month=1;
				//cout<<ju+year;   ju+year 为当前年份
				for(int i=1;i<=12;i++){
					if((year+3)%4!=0){//正在计算的年份不是闰年 
						if(add>=fm[i]){
							add-=fm[i];
							month++;
						}
						else break;
					}
					else {
						if(add>=tm[i]){
							add-=tm[i];
							month++;
						}
						else break;
					}
				} 
				cout<<add+1<<' '<<month<<' '<<(-ju)-year<<' '<<"BC"<<endl;
			} 
			else {
				day-=1721423;
				int year=day/366;
			    int yv=day%366;
			    //year+1 4713离闰年还有3 years ,但不考虑今年 
			    int run=(year+4)/4;
			    int add=yv+year-run;//当成润年的日子
			    while(1){
			    	if((year+4)%4==0&&add>=366){
			    		add-=366;
			    		year++;
					}
					if((year+4)%4!=0&&add>=365){
						add-=365;
						year++;
					}
					if(add<365){
						break;
					}
				}
				int month=1;
				//cout<<ju+year;   ju+year 为当前年份
				for(int i=1;i<=12;i++){
					if((year+5)%4!=0){//正在计算的年份不是闰年 
						if(add>=fm[i]){
							add-=fm[i];
							month++;
						}
						else break;
					}
					else {
						if(add>=tm[i]){
							add-=tm[i];
							month++;
						}
						else break;
					}
				} 
				cout<<add+1<<' '<<month<<' '<<year+1<<endl;
			}
		}
		else {
			day-=2299161;
			//
			if(day<77){
				int month=11;
				if(day<17){
					cout<<day+15<<' '<<10<<' '<<1582<<endl;
				}
				else {
					day-=17;
					for(int i=11;i<=12;i++){
						if(day>=fm[i]){
							day-=fm[i];
							month++;
						}
						else break;
					}
					cout<<day+1<<' '<<month<<' '<<1582<<endl;
				}
			}
			else {
				day-=77;
				int year=day/366;
			    int yv=day%366;
			    //year+1 4713离闰年还有3 years ,但不考虑今年 
			    int run=(year+2)/4-(year+83)/100+(year+383)/400;
			    int add=yv+year-run;//当成润年的日子
			    //int num;
			    while(1){
			    	if(((year+83)%100!=0&&(year+2)%4==0&&add>=366)||(add>=366&&(year+383)%400==0)){//危 
			    		add-=366;
			    		year++;
			    		//num++;
					}
					else if(add>=365){
						add-=365;
						year++;
					}
					else break;
					if(add<365){
						break;
					}
				}
				//cout<<num;
				int month=1;
				for(int i=1;i<=12;i++){
					if(((year+84)%100!=0&&(year+3)%4==0)||((year+384)%400==0)){
						if(add>=tm[i]){
							add-=tm[i];
							month++;
						}
						else break;
					}
					else {
						if(add>=fm[i]){
							add-=fm[i];
							month++;
						}
						else break;
					}
				}
				cout<<add+1<<' '<<month<<' '<<year+1583<<endl;
			}
		}
	}
	return 0;
}
