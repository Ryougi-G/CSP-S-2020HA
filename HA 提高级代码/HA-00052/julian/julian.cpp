#include<bits/stdc++.h>
#define ll long long
#define list l
using namespace std;

ll q,list[100000];
struct date{
	char x;
	ll year;
	ll month;
	ll day;
};
 date begin;
void input();
void add();
void output(date a);
bool Isrn(date a,char x);
int dtm(int n);
int main(){
	freopen("julian.in","r",stdin);
	freopen("julian.out","w",stdout);
	begin.x='B';
	begin.year=4713;
	begin.month=1;
	begin.day=1;
	input();
	add();
	return 0;
}
void input(){
	cin>>q;
	for(int i=0; i<q; i++) cin>>list[i];
}
void add(){
	date d=begin;
	for(int i=0; i<q; i++){
		while(list[i]!=0){
			list[i]--;
			d.day++;
			if(Isrn(d,'j')){
				if(d.day==366)
				{
					d.day=0;
					d.year++;
				}
			}
			else{
				if(d.day==365){
					d.day=0;
					d.year++;
				}
			}
		}
		//dtm(&d.day,&d.month,Isrn(d,'j'));
		d.year+=(-begin.year)+1;
		d.day-=begin.day;
		if(d.month==4||d.month==6||d.month==9||d.month==11){
			if(d.day==31){
				d.day=1;
				d.month++;
			}
		}
		if(d.month==2){
		//	if(!Isrn(d,'b')&&d.day==29) d.day=1;
		//	if(Isrn(d,'b')&&d.day==30) d.day==1;
			d.month++;
		}
		d.month+=(-begin.month);
		if(d.month==13){d.year++; d.month=1;}
		if(d.year<begin.year) d.x='b';
		output(d);
	}
}
void output(date a){
	cout<<a.day<<" "<<a.month<<" "<<a.year;
	if(a.x=='b'){
		cout<<" BC"<<endl;
	}else cout<<endl;
}
bool Isrn(date a,char x){
	if(x=='j'){
		if(a.year%4==0) return 1;
	}else{
		if(a.year%400==0){
			return 1;
		}
		else{
			if(a.year%100==0) return 0;
			if(a.year%4==0) return 1;
		}
	}
	return 0;
}
bool PD(ll x){
	return x>0;
}
void dtm(ll *n,ll *m,bool rn){
	ll temp=*n;
	if(PD(*n-31)){
		*n-=31;
		*m++;
	}
	if(rn){
		if(PD(*n-29)){
			*n-=29;
			*m++;
		}
	}else{
		if(PD(*n-29)){
			*n-29;
			*m++;
		}
	} //Feb.
	if(PD(*n-31)){
		*n-=31;
		*m++;
	}
	if(PD(*n-30)){
		*n-=31;
		*m++; //April
	}
	if(PD(*n-31)){
		*n-=31;
		*m++;
	}
	if(PD(*n-30)){
		*n-=30;
		*m++; //6
	}
	if(PD(*n-31)){
		*n-=31;
		*m++;
	}
	if(PD(*n-31)){
		*n-=31;
		*m++;
	} //8
	if(PD(*n-30)){
		*n-=31;
		*m++;
	}
	if(PD(*n-31)){
		*n-=31;
		*m++;
	}
	if(PD(*n-30)){
		*n-=31;
		*m++;
	}
	if(PD(*n-31)){
		*n-=31;
		*m++;
	}
	if(temp==*n) *m=1;
}
