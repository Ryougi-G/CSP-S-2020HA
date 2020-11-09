#include<bits/stdc++.h>
using namespace std;
long long a,b,c,d,m,n;
bool mon[13];
int main(){
	freopen("julian.in","r",stdin);
	freopen("julian.out","w",stdout);
	mon[1]=mon[3]=mon[5]=mon[7]=mon[8]=mon[10]=mon[12]=1;
	cin>>n;
	for(long long i=1;i<=n;i++){
	long long tm;
	cin>>tm;
		long long year=-4712;
		long long month=1;
		long long date=1;
		if((year+tm/146100*400)>1582){
			year=1580;
			tm=tm-146100*6292/400;
		}else{
			year=year+tm/146100*400;
			tm=tm%146100;
			while(tm>=365){
				if(year%4==0){
					if(tm<366) break;
					year++;
					tm-=366;
				}else{
					year++;
					tm-=365;
			}	
		}
	}
		if(year>=1582) tm+=10;
		while(tm>=365){
			if(year%100==0){
				if(year%400==0){
					if(tm<366) break;
					year++;
					tm-=366;
				}else{
					year++;
					tm-=365;
				}
			}else{
				if(year%4==0){
					if(tm<366) break;
					year++;
					tm-=366;
				}else{
					year++;
					tm-=365;
				}
			}
			if(year==1582) tm+=10;
		}
		
		while(tm>=28){
			if(mon[month]==1){
				if(tm<31) break;
				month++;
				tm-=31;
			}
			else{
				if(month!=2){
					if(tm<30) break;
					month++;
					tm-=30;
				}else{
					if(year%4!=0){
						month++;
						tm-=28;
					}else{
						if(tm<29) break;
						month++;
						tm-=29;
					}
				}
			}
		}
		date+=tm;
		if(year<=0) cout<<date<<" "<<month<<" "<<-year+1<<" BC"<<endl;
		else cout<<date<<" "<<month<<" "<<year<<endl;
	}
	return 0;
}
