#include<bits/stdc++.h>
using namespace std;
int q,a,bc;
void md(int x,int flag){
	if(x<31){
		cout<<x+1<<" "<<1<<" ";
		return;
	}else{
		x-=31;
		if(flag){
			if(x<29){
				cout<<x+1<<" "<<2<<" ";
				return;
			}
			else x-=29;
		}else{
			if(x<28){
				cout<<x+1<<" "<<2<<" ";
				return;
			}
			else x-=28;
		}
		if(x<31){
			cout<<x+1<<" "<<3<<" ";
			return;
		}else x-=31;
		if(x<30){
			cout<<x+1<<" "<<4<<" ";
			return;
		}else x-=30;
		if(x<31){
			cout<<x+1<<" "<<5<<" ";
			return;
		}else x-=31;
		if(x<30){
			cout<<x+1<<" "<<6<<" ";
			return;
		}else x-=30;
		if(x<31){
			cout<<x+1<<" "<<7<<" ";
			return;
		}else x-=31;
		if(x<31){
			cout<<x+1<<" "<<8<<" ";
			return;
		}else x-=31;
		if(x<30){
			cout<<x+1<<" "<<9<<" ";
			return;
		}else x-=30;
		if(x<31){
			cout<<x+1<<" "<<10<<" ";
			return;
		}else x-=31;
		if(x<30){
			cout<<x+1<<" "<<11<<" ";
			return;
		}else x-=30;
		cout<<x+1<<" "<<12<<" ";
		return;
	}
}
int main(){
	freopen("julian.in","r",stdin);
	freopen("julian.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>q;
	while(q--){
		cin>>a;
		int year,mouth,day,flag=0;
		if(a>=2299161){//after 1582 10 15
			a-=2299161;
			if(a<17){
				cout<<a+15<<" "<<10<<" "<<1582<<endl;continue;
			}
			a-=17;
			if(a<30){
				cout<<a+1<<" "<<11<<" "<<1582<<endl;continue;
			}
			a-=30;
			if(a<31){
				cout<<a+1<<" "<<12<<" "<<1582<<endl;continue;
			}
			a-=31;
			year=(a/146097)*400;
			a-=year/400*146097;
			if(a>=6575) a-=6575,year+=18;
			while(a>=36524) a-=36524,year+=100;
			year+=(a/1461)*4;
			a%=1461;
			if(a>=365) a-=365,year++;
			if(a>=365) a-=365,year++;
			if(a>=366) a-=366,year++;
			if(a>=365) a-=365,year++;
			year+=1583;
			if((year%400==0)||(year%100!=0&&year%4==0)) flag=1;
			md(a,flag);
			cout<<year<<endl;
		}else{
			year=(a/1461)*4;
			a-=year/4*1461;
			if(a>=366) a-=366,year++;
			while(a>=365) a-=365,year++;
			year=year-4713;
			if(year>=0){
				year++;
				if(year%4==0) flag=1;
			}else if((year*-1-1)%4==0) flag=1;
			md(a,flag);
			if(year<0) cout<<year*-1<<" BC\n";
			else cout<<year<<endl;
		}
	}
	return 0;
}
