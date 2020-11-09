//1760480
//7 12 107
//1812560
//9 7 250
#include <bits/stdc++.h>
using namespace std;
long long int day;
int s_year=-4713,s_month=1,s_day=1;
const int month[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
int main() {
	freopen("julian.in","r",stdin);
	freopen("julian.out","w",stdout);
	int Q;
	cin>>Q;
	for(int i=0;i<Q;i++){
		cin>>day;
		while(day>0){
			if(s_year<0){
				if((s_year+1)%4!=0){
					if(day>365){
						day-=365;
						s_year++;
					} 
					else{
						for(int i=0;i<365;i++){
							day-=1;
							s_day+=1;
							if(s_day>month[s_month]){
								s_month++;
								s_day=1;
							}
							if(day==0) break;
						}
					}
				}
				else{
													//cout<<s_year<<endl;
					if(day>366){
						day-=366;
						s_year++;
						if(s_year==0) s_year=1;
					} 
					else{
						for(int i=0;i<366;i++){
							//cout<<day<<endl;
							day-=1;
							s_day+=1;
							if(s_month==2&&s_day==28){
								s_day=-1;
								s_month=3;
								continue;
							}
							if(s_day>month[s_month]){
								s_month++;
								s_day=1;
							}
							if(day==0) break;
						}
					}
				}
			}
			if(s_year>0){
				if((s_year%4==0&&s_year%100!=0)||s_year%400==0){
					                                          //cout<<s_year<<endl;
					if(day>366){
						day-=366;
						s_year++;
					} 
					else{
						for(int i=0;i<366;i++){
							day-=1;
							s_day+=1;
							if(s_month==2&&s_day==28){
								s_day=-1;
								s_month=3;
								continue;
							}
							if(s_day>month[s_month]){
								s_month++;
								s_day=1;
							}
							if(day==0) break;
						}
					}
				}
				else{
					if(s_year<1600&&s_year%100==0){
						if(day>366){
							day-=366;
							s_year++;
						} 
						else{
							for(int i=0;i<366;i++){
								day-=1;
								s_day+=1;
								if(s_month==2&&s_day==28){
									s_day=-1;
									s_month=3;
									continue;
								}
								if(s_day>month[s_month]){
									s_month++;
									s_day=1;
								}
								if(day==0) break;
							}
						}	
					}
					else{
						if(day>365){
							day-=365;
							if(s_year==1582) day+=10;
							s_year++;
						} 
						else{
							for(int i=0;i<365;i++){
								if(s_year==1582&&s_month==10){
									if(s_day>=5&&s_day<=14){
										s_day++;
										continue;
									} 
								}
								day-=1;
								s_day+=1;
								if(s_day>month[s_month]){
									s_month++;
									s_day=1;
								}
								if(day==0) break;
							}
						}
					}
				}
			}
		}
		if(s_year<0){
			cout<<s_day<<" "<<s_month<<" "<<abs(s_year)<<" BC"<<endl;
		}
		else cout<<s_day<<" "<<s_month<<" "<<s_year<<endl;
		s_year=-4713;
		s_month=1;
		s_day=1;
	}
	return 0;
}
