#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c<='9'&&c>='0'){
		x=(x<<1)+(x<<3)+(c^48);
		c=getchar();
	}return x*f;
}
int n,a,b[15]={31,31,28,31,30,31,30,31,31,30,31,30,31};
int main(){
	freopen("julian.in","r",stdin);
	freopen("julian.out","w",stdout);
	n=read();
	while(n--){
		a=read();
		int year=-4713,month=1,day=1;
		day+=a;
		year+=day/365;
		day%=365;
		while(day/b[month]){
			day-=b[month];
			month++;
		}
		for(int i=-4713;i<=year;i+=4){
			if((month>=3&&day>=1)||year>-4713)day--;
			if(day==0){
	    		month--;
	    		day=b[month];
	    	}
	    	if(month==0){
    			year--;
	    		month=12;
	    	}
		}
		if(day<0){
			day=-day;
			year-=day/365;
			day%=365;
			while(day/b[month]){
			    day-=b[month];
		    	month--; 
		    	if(day==0){
		        	month--;
		        	day=b[month];
	        	}
	      	    if(month==0){
		        	year--;
	        		month=12;
	        	}
	        }
	    	if(day==0){
		    	month--;
		    	day=b[month];
	    	}
		    if(month==0){
		    	year--;
	    		month=12;
	    	}
		}
		if(year<0){
			cout<<day<<" "<<month<<" "<<-year<<" BC"<<endl;
		}
		if(year>0){
			cout<<day<<" "<<month<<" "<<year+1<<endl;
		}
	}
	return 0;
}
