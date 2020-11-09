#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int year,month,day;
int yuefen1(int);
int yuefen2(int);
int abc[10];
int main()
{
	freopen("julian.in","r",stdin);
	freopen("julian.out","w",stdout);
	int n,x;
	cin>>n;
	for(int i=0;i<n;i++)
	{
	cin>>abc[i];}
	for(int i=0;i<n;i++){
	x=abc[i];
	if(x<1720245+1179)
	{
	 int a,b,z,w;//
	 a=x/1461;
	 b=x%1461;
	 year=4713-4*a;
	 if(b<366) 
	 yuefen2(b);
	 else 
	 {
	 z=b-366;year=year-1-z/365;
	 w=z%365;
	 yuefen1(w);
	 }
	 cout<<day<<" "<<month<<" "<<year<<" "<<"BC"<<endl;
    }
	
	if(x>=1720245+1179&&x<=1720245+577736+1179)
	 {
	 	int a,b,z,w;
	 	x=x-1720245-1179;
	 	a=x/1461;
	    b=x%1461;
	 	year=4*a+1;
	 	if(b<1095){
	 		z=b/365;
	 		year=year+z;
	 		w=b%365;
	 		yuefen1(w);
	 	}
	    
	     else 
	     {
          year=year+3;
          w=b-1095;
	      yuefen2(w);
	    }
	 	cout<<day<<" "<<month<<" "<<year<<endl;
	 }
	if(x>1720245+577736+1179)
	  {
	  	int a,b,z,w,m,n;
		x=x-1720245-577736+651-1179;
	    m=(x-6939)/146097;
	    n=(x-6939)%146097;
        x=x+3*m+(n-1461*25)/(1461*25-1)+1;
		a=x/1461;
	    b=x%1461;
	    year=4*a+1581;
		if(b<1095){
	 		z=b/365;
	 		year=year+z;
	 		w=b%365;
	 		yuefen1(w);
	 		
	 	}
	     else 
	     {
          year=year+3;
          w=b%365;
	      yuefen2(w);
	    }
		  cout<<day<<" "<<month<<" "<<year<<endl;
	  }
 }
}
int yuefen1(int yue)
{
	
	
if(yue<31){
month=1;day=yue+1;}
else if(yue<59){
month=2;day=yue-30;}
	else if(yue<90){
	
	month=3;day=yue-58;}
	else if(yue<120){
	
	month=4;day=yue-89;}
	else if(yue<151){
	
	month=5;day=yue-119;}
 else if(yue<181){
 
 month=6;day=yue-150;}
   else if(yue<212){
   
month=7;day=yue-180;}
 else if(yue<243){
 
		  month=8;day=yue-211;}
		   else if(yue<273){
		   
		   month=9;day=yue-242;}
		    else if(yue<304){
		    
			month=10;day=yue-272;}
			 else if(yue<334){
			 
			 month=11;day=yue-303;}
			  else {
			  month=12; day=yue-333;}
	
}
int yuefen2(int yue)
{
   if(yue<31){
   
	month=1;day=yue+1;}
	else if(yue<60){
	month=2;day=yue-30;}
	 else if(yue<91){
	 
	 month=3;day=yue-59;}
	  else if(yue<121){
	  
	  month=4;day=yue-90;}
	   else if(yue<152){
	   
	   month=5;day=yue-120;}
	    else if(yue<182){
	    
	    month=6;day=yue-151;}
	     else if(yue<213){
	     
		 month=7;day=yue-181;}
		  else if(yue<244){
		  
		  month=8;day=yue-212;}
		   else if(yue<274){
		   
		   month=9;day=yue-243;}
		    else if(yue<305){
		    
			month=10;day=yue-273;}
			 else if(yue<335){
			 
			 month=11;day=yue-304;}
			  else {
			  month=12; day=yue-334;}
}
