#include <bits/stdc++.h>
typedef long long LL;
int Q,r;                                   
//const int year_400 = 97 * 366 + 303 * 365;                            
//const int year_4 = 3 * 365 + 366;
//const int year_100 = 24 * 366 + 76 * 365;
bool judge(int,int,LL);
int year_day(int,int,LL);
int cy(int year,int month,LL day,int x) {          
	if(year < 1582&&(year + x) > 1582) {
		int cnt = 0;
		for(int i = year;i <= year + x;++ i) {
			cnt += year_day(i , month ,day);
		}
		return cnt;
	}        
	if(year <= 1582||(year == 1582&&month < 10)||(year == 1582&&month == 10&&day <= 4)) {
		if(x == 4) {
			return 3 * 365 + 366;                                              
		}     
		if(x == 100) {
			return 25 * 366 + 75 * 365;
		}
		if(x == 400) {                                                 
			return 100 * 366 + 300 * 365;
		}
	}
	if(x == 4)return 3 * 365 + 366;
	if(x == 100)return 24 * 366 + 76 * 365;         
	if(x == 400)return 97 * 366 + 303 * 365;
} 
int sty = 4713,stm = 1;
LL stdd = 1;
bool judge(int year,int month,LL day) {        
	if(year < 1582||(year == 1582&&month < 10)||(year == 1582&&month == 10&&day <= 4)) {
		if(year > 0) {                      
			return year % 4 == 0;                               
		}                        
		else {                                               
			year = -year;
			-- year;
			if(year == -1)return true;
			return (year % 4 == 0&&year % 100 != 0)||(year % 400 == 0);
		}
	}                                                                         
	if(year == 0)return false;                                                     
	if(year > 0) { 
		return (year % 4 == 0&&year % 100 != 0)||year % 400 == 0; 
	}   
	else {    
		year = -year;   
		-- year;              
		return (year % 4 == 0&&year % 100 != 0)||(year % 400 == 0);         
	}    
	return false; 
}                                        
int to_day(bool run,int month_) { 
	int& x = month_; 
	if(x == 1)return 31; 
	if(x == 2)return run ? 29 : 28; 
	if(x == 3)return 31; 
	if(x == 4)return 30; 
	if(x == 5)return 31;             
	if(x == 6)return 30; 
	if(x == 7)return 31; 
	if(x == 8)return 31;  
	if(x == 9)return 30;
	if(x == 10)return 31;
	if(x == 11)return 30;
	if(x == 12)return 31;
}
int year_day(int year,int month,LL day) {
	return judge(year , month , day) ? 366 : 365;
}                                     
void print(int year,int month,LL day) {
	printf("%lld %d ",day,month);
	bool flag = true;
	if(year < 0) {          
		year = -year;                                    
		flag = false;
	}
	printf("%d ",year);                  
	puts(flag ? " " : "BC");
}
void add(int &year,int last) {                           
	if(last < 0&&year >= 0) {           
		++ year;                                 
	}
	return ;
}                 
bool flagfinish = false;                                                   
void ad(int &year,int &month,LL &day) {
	if(year >= 1582&&month >= 10&&day >= 15&&!flagfinish) {
		day += 10;                                                                       
		if(day > to_day(judge(year , month , day) , month)) {
			day -= to_day(judge(year , month , day) , month);
			++ month;                       
		}                  
		if(month > 12) {    
			month = 1;
			++ year;                                                                        
		}
		flagfinish = true;                                 
	}          
}
void work(void) {          
	scanf("%lld",&r);
	sty = -4713;
	stdd = 1;                     
	stm = 1;
	stdd += r;           
	int now;
	// part of year                              
	while(stdd >= year_day(sty , stm , stdd)) {                 
		while(stdd >= year_day(sty , stm , stdd)&&!judge(sty , stm , stdd)) {
			stdd -= year_day(sty , stm , stdd);                                                                      
			++ sty;                       
			ad(sty , stm , stdd);    
			add(sty , sty - 1);   
		}             
		while(stdd >= year_day(sty , stm , stdd)&&judge(sty , stm , stdd)) {
			stdd -= year_day(sty , stm , stdd);
			++ sty;             
			ad(sty , stm , stdd);         
			add(sty , sty - 1); 
		}  
		while(stdd >= cy(sty , stm , stdd , 400)) {
			now = stdd / cy(sty , stm , stdd , 400);
			stdd -= cy(sty , stm , stdd , 400) * now;
			sty += 400 * now;     
			ad(sty , stm , stdd);                                   
			add(sty , sty - 400 * now);                  
		}     
		while(stdd >= cy(sty , stm , stdd , 100)) {          
			now = stdd / cy(sty , stm , stdd , 100);                      
			stdd -= cy(sty , stm , stdd , 100) * now;
			sty += 100 * now; 
			ad(sty , stm , stdd);     
			add(sty , sty - 100 * now);             
		}               
		while(stdd >= cy(sty , stm , stdd , 4)) {
			now = stdd / cy(sty , stm , stdd , 4);
			stdd -= cy(sty , stm , stdd , 4) * now;
			sty += 4 * now;        
			ad(sty , stm , stdd);                    
			add(sty , sty - 4 * now);                                      
		}
		while(stdd >= year_day(sty , stm , stdd)) {
			stdd -= year_day(sty , stm , stdd);
			++ sty;              
			ad(sty , stm , stdd);       
			add(sty , sty - 1);          
		}
	} 
	//part of month
	while(stdd > to_day(judge(sty , stm , stdd) , stm)) {
		stdd -= to_day(judge(sty , stm , stdd) , stm);
		++ stm;                                              
		if(stm > 12) {                   
			stm = 1;
			++ sty;
		}
	}          
	print(sty , stm , stdd); 
	return ;
}                    
int main() {
	freopen("julian.in","r",stdin);
	freopen("julian.out","w",stdout);
	scanf("%d",&Q);              
	while(Q --) {
		work();
	}
	return 0;
}
