#include <bits/stdc++.h>
using namespace std;
int q;
long long julian[100100];
const int four_years_day=1461;
const int normal[12]={31,28,31,30,31,30,31,31,30,31,30,31};
const int special[12]={31,29,31,30,31,30,31,31,30,31,30,31};
int years,days,sum=0,months,i=0;	
void init(){
	cin>>q;
	for(int i=0;i<q;i++){
		cin>>julian[i];
	}
}
void outit(){
	if(years>4712){
		cout<<days<<" "<<months<<" "<<years-4712;
	}else{
		cout<<days<<" "<<months<<" "<<4713-years<<" "<<"BC";
	}
	cout<<endl;
}
void w1(long long a){

	years=a/1461*4;
	a%=1461;
	if(a>=366){
		years=years+1+(a-366)/365;
		a=(a-366)%365;		
		
		while(sum<=a){
			days=a-sum+1;
			sum+=normal[i];
			i++;
		}
		months=i;	
	}else{
		while(sum<=a){
			days=a-sum+1;
			sum+=special[i];
			i++;
		}
		months=i;	
	}
	outit();
	years=0;days=0;sum=0;months=0;i=0;
}
int main(){	
	freopen("julian.in","r",stdin);
	freopen("julian.out","w",stdout);
	init();
	for(int i=0;i<q;i++){
		w1(julian[i]);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

