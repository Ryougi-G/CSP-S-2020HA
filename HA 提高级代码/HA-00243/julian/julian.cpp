#include<bits/stdc++.h>
using namespace std;
int q,ask,day=1,month=1,year=4713;
bool bc=true,rl=true;
int main(){
	freopen("julian.in","r",stdin);
	freopen("julian.out","w",stdout);
	cin>>q;
	for(int i=1;i<=q;i++){
		day=1;
		month=1;
		year=4713;
		bc=true;
		cin>>ask;
		for(int j=1;j++;){
		if(bc==true||(bc==false&&year<=1582)||(bc==false&&year==1582&&month<=10)||(bc==false&&year==1582&&month==10&&day<=4)){
	if(((year-1)%4==0&&bc==true)||((year%4==0&&bc==false))){
			if((month==1||month==3||month==5||month==7||month==8||month==10||month==12)){
				if(ask>=31){
					month++;
					ask-=31;
				}
				else {
					day+=ask;
					ask=0;
				}
			}
			if(month==2){
				if(ask>=29){
					month++;
                    ask-=29;
				}
				else {
					day+=ask;
					ask=0;
				}
			}
			if(month==4||month==6||month==9||month==11){
				if(ask>=30){
					month++;
					ask-=30;
				}
			else{
				day+=ask;
				ask=0;	
				}
			}
		}
		else{
			if((month==1||month==3||month==5|month==7||month==8||month==10||month==12)){
				if(ask>=31){
					month++;
					ask-=31;
				}
				else {
					day+=ask;
					ask=0;
				}
			}
			if(month==2){
				if(ask>=28){
					month++;
                    ask-=28;
				}
				else {
					day+=ask;
					ask=0;
				}
			}
			if(month==4||month==6||month==9||month==11){
				if(ask>=30){
					month++;
					ask-=30;
				}
			else{
				day+=ask;
				ask=0;	
				}
			}
		}
		if(month==13&&bc==true){
			year--;
			month=1;
		}
		if(month==13&&bc==false){
			year++;
			month=1;
		}
			}
			if(bc==true&&year==1&&month==12&&ask>=31){
				bc=false;
				year=1;
				month=1;
				ask-=31;
			}//rulue
			if(bc==false&&year==1582&&month==10&&ask>=5){
				ask+=10;
			}
			if(bc==false){
			if(year>1582||(year==1582&&month>10)||(year==1582&&month==10&&ask>17)){
				if(year%400==0||(year%4==0&&year%100!=0)){
					if(month==1||month==3||month==5||month==7||month==8||month==10||month==12){
						if(ask>=31){
							ask-=31;
							month++;
						}
						else {
							day+=ask;
							ask=0;
						}
					}
					if(month==2){
						if(ask>=29){
							ask-=29;
							month++;
						}
						else {
							day+=ask;
							ask=0;
						}
					}
					if(month==4||month==6||month==9||month==11){
						if(ask>=30){
							ask-=30;
							month++;
						}
						else {
							day+=ask;
							ask=0;
						}
					}
				}	
				else{
					if(month==1||month==3||month==5||month==7||month==8||month==10||month==12){
						if(ask>=31){
							ask-=31;
							month++;
						}
						else {
							day+=ask;
							ask=0;
						}
					}
					if(month==2){
						if(ask>=29){
							ask-=29;
							month++;
						}
						else {
							day+=ask;
							ask=0;
						}
					}
					if(month==4||month==6||month==9||month==11){
						if(ask>=30){
							ask-=30;
							month++;
						}
						else {
							day+=ask;
							ask=0;
						}
					}
				}	
				}
				if(month==13&&bc==false){
			year++;
			month=1;
		}
			}if(ask==0)break;
				}
			
		if(bc==true){
			cout<<day<<" "<<month<<" "<<year<<" BC"<<endl;
		}
		else cout<<day<<" "<<month<<" "<<year<<endl;	
	}	return 0;
	
			}
	


