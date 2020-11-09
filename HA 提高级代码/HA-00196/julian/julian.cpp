#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int q,r,day,month,year,run[13]={0,31,29,31,30,31,30,31,31,30,31,30,31},ping[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
int f(int x){
	year=x/1461*4;
	x%=1461;
	if(x>366){
		x-=366;
		year++;
		year+=x/365;
		x%=365;
		int i=1;
		while(x>0){
			x-=ping[i];
			i++;
		}
		month=max(1,i-1);
		x+=ping[i-1]+1;
		day=max(1,x);
	}else{
		int i=1;
		while(x>0){
			x-=run[i];
			i++;
		}
		month=max(1,i-1);
		x+=run[i-1]+1;
		day=max(1,x);
	}
	year=4713-year;
}
int a(int x){
	year=x/1461*4+1;
	x%=1461;
	if(x*1.0/365>3){
		year+=3;
		x-=1095;
		int i=1;
		while(x>0){
			x-=run[i];
			i++;
		}
		month=max(1,i-1);
		x+=run[i-1];
		day=max(1,x);
	}else{
		year+=x/365;
		x=x%365;
		int i=1;
		while(x>0){
			x-=ping[i];
			i++;
		}
		month=max(1,i-1);
		x+=ping[i-1];
		day=max(1,x);
	}
}
int b(int x){
	year+=x/146097*400;
	x%=146097;
	year+=x/36524*100;
	x%=36524;
	year+=x/1461*4;
	x%=1461;
	cout<<x<<endl;
	if(x*1.0/365>1&&x*1.0/365<=2){
		year+=1;
		x-=365;
		int i=1;
		while(x>0){
			x-=run[i];
			i++;
		}
		month+=max(1,i-2);
		x+=run[i-1];
		day+=max(1,x);
		if(month>12){
			year++;
			month-=12;
		}
		if(day>ping[month]){
			day-=ping[month];
			month++;
		}else if(day<=0){
			month--;
			day+=ping[month];
		}
		if(month>12){
			year++;
			month-=12;
		}
		if(month<=0){
			month+=12;
			year--;
		}
		month++;
	}else if(x*1.0/365<=1){
		year+=x/365;
		x=x%365;
		int i=1;
		while(x>0){
			x-=ping[i];
			i++;
		}
		month+=max(1,i-1);
		x+=ping[i-1];
		day+=max(1,x);
		if(month>12){
			year++;
			month-=12;
		}
		if(day>ping[month]){
			day-=ping[month];
			month++;
		}else if(day<=0){
			month--;
			day+=ping[month];
		}
		if(month>12){
			year++;
			month-=12;
		}
		if(month<=0){
			month+=12;
			year--;
		}
	}else if(x*1.0/365>2){
		x-=731;
		year+=x/365+2;
		x=x%365;
		int i=1;
		while(x>0){
			x-=ping[i];
			i++;
		}
		month+=max(1,i-1);
		if(i==1){
			x+=ping[12];
			month=12;
		}else{
			x+=ping[i-1];
		}
		day+=max(1,x);
		if(month>12){
			year++;
			month-=12;
		}
		if(day>ping[month]){
			day-=ping[month];
			month++;
		}else if(day<=0){
			month--;
			day+=ping[month];
		}
		if(month>12){
			year++;
			month-=12;
		}
		if(month<=0){
			month+=12;
			year--;
		}
	}
}
int main(){
	freopen("julian.in","r",stdin);
	freopen("julian.out","w",stdout);
	cin>>q;
	while(q>0){
		year=0;
		month=0;
		day=0;
		q--;
		cin>>r;
		if(r<1721424){
			f(r);
			cout<<day<<" "<<month<<" "<<year<<" BC"<<endl;
			continue;
		}else if(r>1721424&&r<2299161){
			r-=1721423;
			a(r);
		}else if(r==1721424){
			cout<<1<<" "<<1<<" "<<1<<" ";
			continue;
		}else if(r<=2299238&&r>=2299161){
			r+=10;
			r-=2299161;
			a(577737);
			b(r);
		}else if(r>2299238){
			year=1583;
			month=0;
			day=-1;
			r-=2299237;
			b(r);
		}
		cout<<day<<" "<<month<<" "<<year<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
