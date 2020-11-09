#include<bits/stdc++.h>
using namespace std;
int day,month;
long long year;
bool bc,run;
int type;
int n;
long long a;
int biao[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
void init(){
	day=1;
	month=1;
	year=4713;
	bc=true;
	run=false;
}
bool Run(long long nian){
	if(bc||(!bc&&year<1582)){
		if((nian-1)%4==0){
			return true;
			
		}
		else return false;
	}
	else{
		if((nian%400==0)||((nian%4==0)&&(nian%100!=0))){
			return true;	
		}
		else {
			return false;
		}
	}
}
void Year(){
	while(a>=365){
		if(bc){//before century
			if(Run(year)){
				if(a<366){
					return;
				}
				year-=1;
				a-=366;
			}
			else{
				year-=1;
				a-=365;
			}
			if(year==0){
				year=1;
				bc=false;
				a+=1;
			}
		}
		else{//after century
			if(Run(year)){
				if(a<366){
					return;
				}
				year+=1;
				a-=366;
			}
			else{
				year+=1;
				a-=365;
			}
		}
	}
	return;
}
void Month(){
	while(a>0){
		day++;
		a--;
		if(day>=biao[month]&&month!=2){
			day-=biao[month];
			month++;
			if(month>12){
				month-=12;
			}
			
		}
		else if(day>=28&&!Run(year)&&month==2){
			day-=28;
			month++;
			if(month>12){
				month-=12;
			}
		}
		else if(day>=29&&Run(year)&&month==2){
			day-=29;
			month++;
			if(month>12){
				month-=12;
			}
		}
	//	cout<<day<<" ";
	}
	return;
}
void Special(){
	if((!bc&&year>1582)||(!bc&&year==1582&&month>=10&&day>=5)){
	if(!Run(year)){
		day+=10;
		if(day>biao[month]){
			day-=biao[month];
			month++;
		}
	}
	else{
		day+=10;
		if(day>biao[month]){
			if(month==2){
				day-=29;
			month++;
			}
			else{
			day-=biao[month];
			month++;	
			}
			
		}
	}		if(month>12){
			month-=12;
			year++;
		}	
	}
}
int main(){
	freopen("julian.in","r",stdin);
	freopen("julian.out","w",stdout);
	cin>>n;
	for(int kk=0;kk<n;kk++){
		init();
		cin>>a;
		Year();
		Month();
		Special();
		if(bc){
			cout<<day<<" ";
			cout<<month<<" ";
			cout<<year<<" ";
			cout<<"BC";
		}
		else{
			cout<<day<<" ";
			cout<<month<<" ";
			cout<<year;
		}
		cout<<endl;
	}
	return 0;
}
